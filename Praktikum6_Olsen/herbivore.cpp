#include "herbivore.h"

std::random_device rd;


Herbivore::Herbivore(const string &race, double currentWeigth, int maxWeight,
                     double growthRate, double breedingChance, double hidingChance):
    Dinosaur(race, currentWeigth, maxWeight, growthRate, breedingChance, hidingChance)
{}

Herbivore::~Herbivore()
{

}

bool Herbivore::hide()
{
    // 0 - 100 %
    return getRandom(0,100) % 100 < m_hidingChance;
}
