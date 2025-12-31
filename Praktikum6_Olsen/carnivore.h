#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "dinosaur.h"

class Carnivore : public Dinosaur
{
private:

public:
    Carnivore();
    Carnivore(const string &race, int initialWeight, int maxWeight, double growthRate, double breadingChance);
    ~Carnivore();
    void hunt();
};

#endif // CARNIVORE_H
