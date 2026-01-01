#include <iostream>
#include "park.h"

Park::Park()
{
}

void Park::addHerbivore(Herbivore *h)
{
    m_herbivors.push_back(h);

}

void Park::addCarnivore(Carnivore *c)
{
    m_carnivors.push_back(c);

}

void Park::printHerbivore()
{
    for (size_t i = 0; i < m_herbivors.size(); i++) {
        std::cout << m_herbivors[i] << std::endl;
    }
}
