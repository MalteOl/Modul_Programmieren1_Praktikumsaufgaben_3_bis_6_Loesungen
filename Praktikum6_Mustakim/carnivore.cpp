#include "carnivore.h"
#include "herbivore.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

Carnivore::Carnivore(std::string race, double maxWeight, double growthRate, double breedChance)
    : Dinosaur(maxWeight, growthRate, breedChance, race, 0.2)
    , failedHunts(0)
{}

bool Carnivore::hunt(Herbivore &prey)
{
    if (!isAlive() || hasAttemptedHunt || !prey.isAlive())
        return false;
    hasAttemptedHunt = true; // Mark hunt attempt

    double weightRatio = prey.getWeight() / this->getWeight();
    double successChance = 0.6 - weightRatio;
    if (successChance < 0.1)
        successChance = 0.1;

    if ((rand() % 100) < (successChance * 100)) {
        failedHunts = 0; // Reset streak
        return true;
    }
    failedHunts++;
    return false;
}
void Carnivore::resetHuntingAttempt()
{
    hasAttemptedHunt = false; // Reset for next time step
}
void Carnivore::checkHuntStreak()
{
    if (failedHunts > 2) {
        alive = false;
        std::cout << race << " verhungert." << std::endl;
    }
}

Dinosaur *Carnivore::reproduce()
{
    if (breed()) {
        return new Carnivore(race, maxWeight, growthRate, breedChance);
    }
    return nullptr;
}
