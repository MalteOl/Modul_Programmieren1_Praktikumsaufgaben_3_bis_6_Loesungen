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
