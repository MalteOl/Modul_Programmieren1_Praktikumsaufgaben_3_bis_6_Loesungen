#include "herbivore.h"


Herbivore::Herbivore(const string &race, int initialWeight, int maxWeight,
                     double growthRate, double breadingChance) :
    Dinosaur(race, initialWeight, maxWeight, growthRate, breadingChance)
{}
