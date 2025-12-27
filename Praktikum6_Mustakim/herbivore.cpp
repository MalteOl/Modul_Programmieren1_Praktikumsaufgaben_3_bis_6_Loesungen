#include "herbivore.h"
#include <cstdlib>

using std::rand;
using std::string;
Herbivore::Herbivore(
    string race, double maxWeight, double growthRate, double breedChance, double hideChance)
    : Dinosaur(maxWeight, growthRate, breedChance, race, 0.05)
    , hideChance(hideChance)
{}

bool Herbivore::hide()
{
    return (rand() % 100) < (hideChance * 100); // Verstecken basierend auf der Chance
}

Dinosaur *Herbivore::reproduce()
{
    if (breed()) {
        return new Herbivore(race, maxWeight, growthRate, breedChance, hideChance);
    }
    return nullptr; // Keine Fortpflanzung
}
