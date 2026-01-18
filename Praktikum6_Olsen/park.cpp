#include <iostream>
#include "park.h"

Park::Park()
{
    // Name des Tiers, aktuelles Gewicht, Maximalgewicht, Wachstumsrate, Vermehrrate (breedingChance), Versteckchance
    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        addCarnivore(new Carnivore("Tyrannosaurus Rex", 8000*0.2, 8000, 0.2, 0.8, 0));
    }
    // 4x Raptor
    for (int i = 0; i < 4; ++i) {
        addCarnivore(new Carnivore("Raptor", 500*0.2, 500, 0.3, 0.12, 0));
    }

    // 4x Brachiosaurus
    for (int i = 0; i < 4; ++i) {
        addHerbivore(new Herbivore("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5));
    }

    // 5x Parasaurolophus
    for (int i = 0; i < 5; ++i) {
        addHerbivore(new Herbivore("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75));
    }
}

Park::~Park()
{
    for (auto c : m_carnivors) {
        delete c;
    }
    m_carnivors.clear();
    for (auto h : m_herbivors) {
        delete h;
    }
    m_herbivors.clear();
}

std::vector<int> Park::findPrey()
{
    std::vector<int> potentialPrey;

    for (int i = 0; i < m_herbivors.size(); i++)
    {
        if(m_herbivors[i]->hide() == false)
        {
            potentialPrey.push_back(i);
        }
    }

    return potentialPrey;
}

void Park::hunt(std::vector<int> potentialPreys)
{
    // For Schleifen Zyklus 2x laufen lassen, aber nur für die, die nicht satt sind!
    for (int i = 0; i < m_carnivors.size(); i++)
    {
        Carnivore* carni = m_carnivors.at(i);

        bool preyCaught = false;
        for(int j = 0; j < potentialPreys.size(); j++)
        {
            Herbivore* potentialPrey = m_herbivors[potentialPreys[j]];

            // Herbi zu schwer, move along tiny boi
            if (potentialPrey->getCurrentWeigth() > carni->getCurrentWeigth())
            {
                continue;
            }

            // Beute gefunden, hamham, finito
            preyCaught = true;
            carni->setFed(true);
            deathHerbis(potentialPreys[i]);
            potentialPreys.erase(potentialPreys.begin() + j);

            // alle folgenden potential preys müssen um 1 reduziert werden, weil einer entfallen ist
            for (int k = j; k < potentialPreys.size(); k++)
            {
                potentialPreys[k] = potentialPreys[k]--;
            }

            break;
        }

        // Wenn keiner klein genug war...
        if (preyCaught == false)
        {
            // Hatte er noch etwas zu essen vom letzten Ma(h)l?
            if (carni->getFed() == true)
            {
                carni->setFed(false);
            } else
            {
                // wenn nicht, dann verhungert er
                deathCarnis(i);
            }
        }
    }
}

void Park::addHerbivore(Herbivore *h)
{
    m_herbivors.push_back(h);

}

void Park::addCarnivore(Carnivore *c)
{
    m_carnivors.push_back(c);

}

void Park::deathHerbis(int index)
{
    m_herbivors.erase(m_herbivors.begin() + index);
}

void Park::deathCarnis(int index)
{
    m_carnivors.erase(m_carnivors.begin() + index);

}

void Park::lifeHerbis(int index)
{
    Herbivore *parent = m_herbivors.at(index);
    m_herbivors.emplace_back(new Herbivore(parent->getRace(), parent->getCurrentWeigth(), parent->getMaxWeight(),
                                           parent->getGrowthRate(), parent->getBreedingChance(), parent->getHidingChance()));

}

void Park::lifeCarnis(int index)
{
    Carnivore* parent = m_carnivors.at(index);
    m_carnivors.emplace_back(new Carnivore(parent->getRace(), parent->getCurrentWeigth(), parent->getMaxWeight(),
                                       parent->getGrowthRate(), parent->getBreedingChance(), parent->getHidingChance()));

}

void Park::breedSimulation()
{
    // Herbivoren füttern

    for (int i = 0; i < m_herbivors.size(); i++)
    {
        if (m_herbivors.at(i)->breed() && (sumOfDinos() <= 100))
        {
            // Parasaurolophus erhält 3 Kinder

            int childrenCount = 1;
            if (m_herbivors.at(i)->getRace() == "Parasaurolophus")
            {
                childrenCount = 3;
            }

            // We cannot breed more dinos than we have room
            if (100 - (m_herbivors.size() + m_carnivors.size()) < childrenCount)
            {
                childrenCount = 100 - (m_herbivors.size() + m_carnivors.size());
            }

            for (int count = 0; count < childrenCount; count++)
            {
                m_herbivors.emplace_back(new Herbivore(m_herbivors.at(i)->getRace(), m_herbivors.at(i)->getCurrentWeigth(), m_herbivors.at(i)->getGrowthRate(), m_herbivors.at(i)->getMaxWeight(),
                                                       m_herbivors.at(i)->getBreedingChance(), m_herbivors.at(i)->getHidingChance()));
            }
        }
    }

    // hide&seek
    std::vector<int> potentialPreys = findPrey();
    hunt(potentialPreys);

    for (int i = 0; i < m_carnivors.size(); i++)
    {
        Carnivore* carni = m_carnivors.at(i);
        // Happy Birthday!
        carni->age();
        // Sad Deathday?
        int countCarnis = m_carnivors.size();
        if (m_carnivors[i]->diesOfAge())
        {
            deathCarnis(i);
            // Keinen überspringen und die Liste ist kürzer geworden, also früher aufhören
            // sonst altern Neugeborene oder wir greifen auf einen nicht vorhandenen Dino zu
            i--;
            countCarnis--;
            continue;
        }
        // Carnivoren füttern

        if (m_carnivors.at(i)->breed() && sumOfDinos() <= 100)
        {
            m_carnivors.emplace_back(new Carnivore(m_carnivors.at(i)->getRace(), m_carnivors.at(i)->getCurrentWeigth(), m_carnivors.at(i)->getGrowthRate(), m_carnivors.at(i)->getMaxWeight(),
                                                   m_carnivors.at(i)->getBreedingChance(), m_carnivors.at(i)->getHidingChance()));
        }
    }

}

void Park::huntSimulation()
{
    int h_dieCounter = 0;
    int c_dieCounter = 0;
    std::vector<int> deadCarnivores;
    for (int i = 0; i < static_cast<int>(m_carnivors.size()); ++i) {
        if (!m_herbivors.empty()) {
            int randomHerbivoren = Dinosaur::getRandom(0, static_cast<int>(m_herbivors.size()) - 1);
            if (m_carnivors[i]->hunt(*m_herbivors[randomHerbivoren])) {
                h_dieCounter++;
                m_herbivors.erase(m_herbivors.begin() + randomHerbivoren);
            } else {
                m_carnivors[i]->minLife();
            }
        } else {
            m_carnivors[i]->minLife();
        }
        if (!m_carnivors[i]->isAlive()) {
            c_dieCounter++;
            deadCarnivores.push_back(i);
        }
    }
    // Tote Karnivoren von hinten nach vorne löschen
    for (int j = static_cast<int>(deadCarnivores.size()) - 1; j >= 0; --j) {
        int idx = deadCarnivores[j];
        delete m_carnivors[idx];
        m_carnivors.erase(m_carnivors.begin() + idx);
    }
    std::cout << "HUNTING SEASON CASUALTIES FROM CARNIVORE" << std::endl;
    std::cout << "Herbivore: " << h_dieCounter << std::endl;
    std::cout << "Carnivore: " << c_dieCounter << std::endl;
}

void Park::passingTime()
{
    int dieCounter = 0;

    // alle Herbivors altern lassen
    for(int i = 0; i < m_herbivors.size(); i++) {
        if (!m_herbivors[i]->age()) {
            dieCounter++;
            m_herbivors.erase(m_herbivors.begin() + i);
            i--;
        }
    }

    dieCounter = 0;
    // und jetzt alle Carnivors altern lassen
    for(int i = 0; i < m_carnivors.size(); i++) {
        if (!m_carnivors[i]->age()) {
            dieCounter++;
            m_carnivors.erase(m_carnivors.begin() + i);
            i--;
        }
    }


    //    // Carnivors jagen Herbivors
    //    for (int i = 0; i < m_carnivors.size(); ++i) {
    //        int j = 0;
    //        while (j < m_herbivors.size()) {
    //            if (m_carnivors[i].hunt(m_herbivors[j])) {
    //                m_herbivors.erase(m_herbivors.begin() + j);
    //                break; // Ein Carnivore jagt nur einen Herbivore pro Zeiteinheit
    //            } else {
    //                ++j;
    //            }
    //        }
    //    }
    //    // neue Herbivores erzeugen
    //    for (int i = 0; i < m_herbivors.size(); ++i) {
    //        if (m_herbivors[i].breed()==true) {
    //            addHerbivore(m_herbivors[i]);
    //        }
    //    }

    //    // neue Carnivores erzeugen
    //    for (int i = 0; i < m_carnivors.size(); ++i) {
    //        if (m_carnivors[i].breed()==true) {
    //            addCarnivore(m_carnivors[i]);
    //        }
    //    }

    cout << "Verbleibende Dino-Population: " << sumOfDinos() << endl;
    cout << "Herbivoren: " << sumOfHerbivors() << endl;
    cout << "Karnivoren: " << sumOfCarnivos() << endl;
    cout << "T-Rexe: " << sumOfT_Rexes() << endl;

}

int Park::sumOfDinos()
{
    return  m_herbivors.size() + m_carnivors.size();

}

int Park::sumOfHerbivors()
{
    return m_herbivors.size();
}

int Park::sumOfCarnivos()
{
    return m_carnivors.size();
}

int Park::sumOfT_Rexes()
{
    int counter = 0;
    for (const auto carnivore: m_carnivors)
    {
        if (carnivore->getRace() == "Tyrannosaurus Rex")
            counter++;
    }
    return counter;
}
