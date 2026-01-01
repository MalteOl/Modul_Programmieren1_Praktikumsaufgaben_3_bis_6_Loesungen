#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "dinosaur.h"

class Herbivore : public Dinosaur
{
private:
public:
    Herbivore();
    Herbivore(const string &race, double initialWeight, int maxWeight, double growthRate, double breadingChance, double hidingChance);
    ~Herbivore();

    void hide();
};

#endif // HERBIVORE_H
