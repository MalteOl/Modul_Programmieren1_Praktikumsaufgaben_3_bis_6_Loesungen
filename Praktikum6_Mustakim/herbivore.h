#ifndef HERBIVORE_H
#define HERBIVORE_H
#include "dinosaur.h"

class Herbivore : public Dinosaur
{
public:
    Herbivore(std::string race,
              double maxWeight,
              double growthRate,
              double breedChance,
              double hideChance);
    bool hide();
    Dinosaur *reproduce() override;

private:
    double hideChance; // Versteck-Chance
};

#endif // HERBIVORE_H
