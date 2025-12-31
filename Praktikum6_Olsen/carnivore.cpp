#include "carnivore.h"

Carnivore::Carnivore(const string &race, int initialWeight, int maxWeight,
                     double growthRate, double breadingChance) :
    Dinosaur(race, initialWeight, maxWeight, growthRate, breadingChance)
{}

void Carnivore::hunt()
{

}
