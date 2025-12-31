#include "herbivore.h"


float Herbivore::hidingChance()
{

}

Herbivore::Herbivore(const string &race, int initialWeight, int maxWeight,
                     double growthRate, double breadingChance) :
    Dinosaur(race, initialWeight, maxWeight, growthRate, breadingChance)
{}

void Herbivore::hide()
{

}
