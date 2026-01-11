#include <iostream>
#include "park.h"

Park::Park()
{
    // Name des Tiers, aktuelles Gewicht, Maximalgewicht, Wachstumsrate, Vermehrrate, Versteckchance
    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        Carnivore t_rex ("Tyrannosaurus Rex", 8000*0.2, 8000, 0.2, 0.8, 0);
        addCarnivore(t_rex);
    }
    // 4x Raptor
    for (int i = 0; i < 4; ++i) {
        Carnivore rapt ("Raptor", 500*0.2, 500, 0.3, 0.12, 0);
        addCarnivore(rapt);
    }

    // 4x Brachiosaurus
    for (int i = 0; i < 4; ++i) {
        Herbivore brach ("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5);
        addHerbivore(brach);
    }

    // 5x Parasaurolophus
    for (int i = 0; i < 5; ++i) {
        Herbivore para ("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75);
        addHerbivore(para);
    }
}

void Park::addHerbivore(const Herbivore &h)
{
    m_herbivors.push_back(h);

}

void Park::addCarnivore(const Carnivore &c)
{
    m_carnivors.push_back(c);

}

void Park::breedSimulation()
{
    int breedCounter = 0;

    for(int i = 0; i < m_herbivors.size(); i++)
    {
        if(m_herbivors[i].breed() )
        {
            breedCounter++;
            //            Herbivore brach ("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5);
            //            addHerbivore(brach);
//                        Herbivore para ("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75);
//                        addHerbivore(para);
        }
        // Erzeuge ein neues Herbivore-Objekt mit den Attributen des Elternteils
//        Herbivore baby(
//            m_herbivors[i].getRace(),
//            m_herbivors[i].getMaxWeight() * 0.05, // Startgewicht 5%
//            m_herbivors[i].getMaxWeight(),
//            m_herbivors[i].getGrowthRate(),
//            m_herbivors[i].getBreedingChance(),
//            m_herbivors[i].getHidingChance()
//            );
//        addHerbivore(baby);
    }


    breedCounter = 0;

    for(int j = 0; j < m_carnivors.size(); j++)
    {
        if(m_carnivors[j].breed())
        {
            breedCounter++;

            //            Carnivore t_rex ("Tyrannosaurus Rex", 8000*0.2, 8000, 0.2, 0.8, 0);
            //            addCarnivore(t_rex);
//                        Carnivore rapt ("Raptor", 500*0.2, 500, 0.3, 0.12, 0);
//                        addCarnivore(rapt);
        }
        // Erzeuge ein neues Carnivore-Objekt mit den Attributen des Elternteils
//        Carnivore baby(
//            m_carnivors[j].getRace(),
//            m_carnivors[j].getMaxWeight() * 0.2, // Startgewicht 20%
//            m_carnivors[j].getMaxWeight(),
//            m_carnivors[j].getGrowthRate(),
//            m_carnivors[j].getBreedingChance(),
//            m_carnivors[j].getHidingChance()
//            );
//        addCarnivore(baby);
    }

}

void Park::huntSimulation()
{
    int h_dieCounter = 0;
    int c_dieCounter = 0;
    int f_dieCounter = 0;
    int randomHerbivoren = Dinosaur::getRandom(0,m_herbivors
                                                          .size()-1);
    int randomKarnivoren = Dinosaur::getRandom(0, m_carnivors.size()-1);

    for(int i = 0; i < m_carnivors.size(); i++)
    {
        // make sure there's enough herbivore to eat
        if(m_herbivors.size() >= 1)
        {
            // hunt success
            if(m_carnivors[i].hunt(m_herbivors[randomHerbivoren]))
            {
                // cout << "here";
                h_dieCounter++;
                m_herbivors.erase(m_herbivors.begin() + randomHerbivoren);
            }
            // hunt failed
            else
            {
                m_carnivors[i].minLife();
            }
        }
        // nothing to eat life--
        else
        {
            m_carnivors[i].minLife();
        }
        // Check if its still alive
        if(!m_carnivors[i].isAlive())
        {
            c_dieCounter++;
            m_carnivors.erase(m_carnivors.begin() + i);
        }
    }
    cout << "HUNTING SEASON CASUALTIES FROM CARNIVORE" << endl;
    cout << "Herbivore: -" << h_dieCounter << endl;
    cout << "Carnivore: -" << c_dieCounter << endl;
}

void Park::passingTime()
{
    int dieCounter = 0;

    // alle Herbivors altern lassen
    for(int i = 0; i < m_herbivors.size(); i++) {
        if (!m_herbivors[i].age()) {
            dieCounter++;
            m_herbivors.erase(m_herbivors.begin() + i);
        }
    }

    dieCounter = 0;
    // und jetzt alle Carnivors altern lassen
    for(int i = 0; i < m_carnivors.size(); i++) {
        if (!m_carnivors[i].age()) {
            dieCounter++;
            m_carnivors.erase(m_carnivors.begin() + i);
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
        if (carnivore.getRace() == "Tyrannosaurus Rex")
            counter++;
    }
    return counter;
}
