#include "carnivore.h"

Carnivore::Carnivore(const string &race, double currentWeigth, int maxWeight,
                     double growthRate, double breadingChance, double hidingChance) :
    Dinosaur(race, currentWeigth, maxWeight, growthRate, breadingChance, hidingChance)
{}

bool Carnivore::hunt(Herbivore herbivore)
{
    // Carnivore wiegt mehr als Herbivore?
    if(currentWeigth() >= herbivore.currentWeigth()){

    }

}
