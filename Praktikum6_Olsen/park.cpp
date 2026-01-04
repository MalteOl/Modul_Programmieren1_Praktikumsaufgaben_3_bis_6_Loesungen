#include <iostream>
#include "park.h"

Park::Park()
{
    // Name des Tiers, aktuelles Gewicht, Maximalgewicht, Wachstumsrate, Vermehrrate, Versteckchance
    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        Carnivore t_rex ("Tyrannosaurus Rex", 8000*0.05, 8000, 0.2, 0.8, 0);
        addCarnivore(t_rex);
    }
    // 4x Raptor
    for (int i = 0; i < 4; ++i) {
        Carnivore rapt ("Raptor", 500*0.05, 500, 0.3, 0.12, 0);
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

    // neue Dinos erzeugen
    //    if (m_herbivors[i]->breed()==true) {
    //        addHerbivore(para);
    //    }
}

void Park::addHerbivore(const Herbivore &h)
{
    m_herbivors.push_back(h);

}

void Park::addCarnivore(const Carnivore &c)
{
    m_carnivors.push_back(c);

}

void Park::passingTime()
{
    // alle Herbivors altern lassen
    for(int i = 0; i < m_herbivors.size(); i++)
        if (!m_herbivors[i].age()) {
            m_herbivors.erase(m_herbivors.begin() + i);
        } else {
            ++i;
        }
    // und alle Carnivors
    for(int i = 0; i < m_carnivors.size(); i++)
        if (!m_carnivors[i].age()) {
            m_carnivors.erase(m_carnivors.begin() + i);
        } else {
            ++i;
        }
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
        if (carnivore.race() == "Tyrannosaurus Rex")
            counter++;
    }
    return counter;
}
