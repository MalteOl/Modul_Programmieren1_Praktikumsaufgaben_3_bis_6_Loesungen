#include "herbivore.h"


Herbivore::Herbivore(const string &race, double currentWeigth, int maxWeight,
                     double growthRate, double breedingChance, double hidingChance):
Dinosaur(race, currentWeigth, maxWeight, growthRate, breedingChance, hidingChance)
{}

bool Herbivore::hide()
{

}
