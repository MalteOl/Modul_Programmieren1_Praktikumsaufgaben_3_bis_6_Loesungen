#include <iostream>
#include "park.h"

Park::Park()
{
    // race, currentWeigth, maxWeight, growthRate, Vermehrrate (breedingChance), hidingChance
    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        addCarnivore(new Carnivore("Tyrannosaurus Rex", 8000*0.2, 8000, 0.2, 0.08, 0));
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
    for (Carnivore* carnivors : m_carnivors) {
        delete carnivors;
    }

    for (Herbivore* herbivors : m_herbivors) {
        delete herbivors;
    }

    //    for (unsigned i=0; i < m_carnivors.size(); i++)
    //        delete m_carnivors[i];

    //    for (unsigned i=0; i < m_herbivors.size(); i++)
    //        delete m_herbivors[i];

}

void Park::passingTime()
{



    // Jeder Dino altert (age() aufgerufen)

    // Herbivores altern lassen


    // Carnivores altern lassen


    // zu alte Herbivors werden aus dem Vektor entfernt
    for (size_t i = 0; i < m_herbivors.size(); i++)
        // ist Dino zu alt?
        if (m_herbivors[i]->age()) {
            m_herbivors.erase(m_herbivors.begin() + i);
        }

    // zu alte Carnivors werden aus dem Vektor entfernt
    for (size_t i = 0; i < m_carnivors.size(); i++)
        // ist Dino zu alt?
        if (m_carnivors[i]->age()) {
            m_carnivors.erase(m_carnivors.begin() + i);
        }


    // Karnivore jagen Herbivors zuerst (hunt() aufgerufen)
    for (size_t i = 0; i < m_carnivors.size(); i++)
        if (m_carnivors[i]->hunt(*m_herbivors[i])) {
            m_herbivors.erase(m_herbivors.begin() + i);
        }




    // Parasaurolophus-Wurf erzeugt 3 Jungtiere
    int childCount;
    for (size_t i = 0; i < m_herbivors.size(); i++)  {
        for (childCount = 0; i < 3; i++)  {
            if ((m_herbivors.at(i)->getRace() == "Parasaurolophus") && m_herbivors.at(i)->breed())
            {
                cout << "Parasaurolophusse  erzeugt: " << i << endl;
                addHerbivore(new Herbivore("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75));
                childCount++;
            }
        }

    }





    // Jeder Dino kann sich fortpflanzen (breed() aufgerufen)
//        for (size_t i = 0; i < m_carnivors.size(); i++)
//            if (m_carnivors[i]->breed()) {
//                addCarnivore(new Carnivore("Raptor", 500*0.2, 500, 0.3, 0.12, 0));
//            }
//        for (size_t i = 0; i < m_carnivors.size(); i++)
//            if (m_carnivors[i]->breed()) {
//                addHerbivore(new Herbivore("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75));
//            }


    // Bestandslisten angepasst (Tiere entfernen/hinzufügen)

    // neue Herbivores erzeugen
    // neue Carnivores erzeugen


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

void Park::removeHerbivore(Herbivore *h)
{
    m_herbivors.erase(m_herbivors.begin());
}

void Park::addCarnivore(Carnivore *c)
{
    m_carnivors.push_back(c);

}

void Park::removeCarnivore(Carnivore *c)
{
    m_carnivors.erase(m_carnivors.begin());
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

    // Carnivoren füttern

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

        if (m_carnivors.at(i)->breed() && sumOfDinos() <= 100)
        {
            int childrenCount = 1;

            if (100 - (m_herbivors.size() + m_carnivors.size()) < childrenCount)
            {
                childrenCount = 100 - (m_herbivors.size() + m_carnivors.size());
            }

            for (int count = 0; count < childrenCount; count++)
            {
                m_carnivors.emplace_back(new Carnivore(m_carnivors.at(i)->getRace(), m_carnivors.at(i)->getCurrentWeigth(), m_carnivors.at(i)->getGrowthRate(), m_carnivors.at(i)->getMaxWeight(),
                                                       m_carnivors.at(i)->getBreedingChance(), m_carnivors.at(i)->getHidingChance()));
            }
        }
    }

}

void Park::huntSimulation()
{
    int h_dieCounter = 0;
    int c_dieCounter = 0;
    int f_dieCounter = 0;
    int randomHerbivoren = Dinosaur::getRandom(0, m_herbivors.size() - 1);
    int randomKarnivoren = Dinosaur::getRandom(0, m_carnivors.size() - 1);

    for(int i = 0; i < m_carnivors.size(); i++)
    {
        // make sure there's enough herbivore to eat
        if(m_herbivors.size() >= 1)
        {
            // hunt success
            if(m_carnivors[i]->hunt(*m_herbivors[randomHerbivoren]))
            {
                // cout << "here";
                h_dieCounter++;
                m_herbivors.erase(m_herbivors.begin() + randomHerbivoren);
            }
            // hunt failed
            else
            {
                m_carnivors[i]->minLife();
            }
        }
        // nothing to eat life--
        else
        {
            m_carnivors[i]->minLife();
        }
        // Check if its still alive
        if(!m_carnivors[i]->isAlive())
        {
            c_dieCounter++;
            m_carnivors.erase(m_carnivors.begin() + i);
        }
    }
    cout << "HUNTING SEASON CASUALTIES FROM CARNIVORE" << endl;
    cout << "Herbivore: " << h_dieCounter << endl;
    cout << "Carnivore: " << c_dieCounter << endl;
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
