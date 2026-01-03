#include <iostream>
#include "park.h"

Park::Park()
{
    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        Carnivore *t_rex = new Carnivore
            ("Tyrannosaurus Rex", 8000*0.05, 8000, 0.2, 0.8, 0);
        addCarnivore(t_rex);
    }
    // 4x Raptor
    for (int i = 0; i < 4; ++i) {
        Carnivore *rapt = new Carnivore
            ("Raptor", 500*0.05, 500, 0.3, 0.12, 0);
        addCarnivore(rapt);
    }

    // 4x Brachiosaurus
    for (int i = 0; i < 4; ++i) {
        Herbivore *brach = new Herbivore
            ("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5);
        addHerbivore(brach);
    }

    // 5x Parasaurolophus
    for (int i = 0; i < 5; ++i) {
        Herbivore *para = new Herbivore
            ("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75);
        addHerbivore(para);
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

void Park::passingTime()
{
    // alle Herbivors & Carnivors altern lassen
    for (int i = 0; i < m_herbivors.size(); ) {

        if (!m_herbivors[i]->age()) {
            delete m_herbivors[i];
            m_herbivors.erase(m_herbivors.begin() + i);
        } else {
            ++i;
        }

        for (int i = 0; i < m_carnivors.size(); ) {
            if (!m_carnivors[i]->age()) {
                delete m_carnivors[i];
                m_carnivors.erase(m_carnivors.begin() + i);
            } else {
                ++i;
            }
        }
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
