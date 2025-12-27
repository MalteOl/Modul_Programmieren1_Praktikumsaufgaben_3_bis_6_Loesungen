#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "dinosaur.h"

class Herbivore;

class Carnivore : public Dinosaur
{
public:
    Carnivore(std::string race, double maxWeight, double growthRate, double breedChance);
    bool hunt(Herbivore &prey);
    Dinosaur *reproduce() override;
    void checkHuntStreak();
    void resetHuntingAttempt();

private:
    int failedHunts; // ZÃ¤hlt, wie oft die Jagd misslungen ist
    bool hasAttemptedHunt;
};

#endif
