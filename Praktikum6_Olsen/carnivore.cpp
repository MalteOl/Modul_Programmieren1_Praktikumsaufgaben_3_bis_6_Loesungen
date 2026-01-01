#include "carnivore.h"

Carnivore::Carnivore(const string &race, double initialWeight, int maxWeight,
                     double growthRate, double breadingChance, double hidingChance) :
    Dinosaur(race, initialWeight, maxWeight, growthRate, breadingChance, hidingChance)
{}

void Carnivore::hunt()
{

}
