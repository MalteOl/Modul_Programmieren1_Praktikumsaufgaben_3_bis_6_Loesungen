#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "dinosaur.h"
#include "herbivore.h"

class Carnivore : public Dinosaur
{
public:
    bool hunt(Herbivore herbivore);
    Carnivore();
    Carnivore(const string &race, double currentWeigth, int maxWeight,
              double growthRate, double breedingChance, double hidingChance);
    ~Carnivore();
private:

};

#endif // CARNIVORE_H
