#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "dinosaur.h"

class Herbivore : public Dinosaur
{
private:
public:
    Herbivore();
    Herbivore(const string &race, double currentWeigth, int maxWeight,
              double growthRate, double breedingChance, double hidingChance);
    ~Herbivore();

    bool hide();
};

#endif // HERBIVORE_H
