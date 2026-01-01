#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "dinosaur.h"

class Carnivore : public Dinosaur
{
private:

public:
    Carnivore();
    Carnivore(const string &race, double initialWeight, int maxWeight, double growthRate, double breadingChance, double hidingChance);
    ~Carnivore();
    void hunt();
};

#endif // CARNIVORE_H
