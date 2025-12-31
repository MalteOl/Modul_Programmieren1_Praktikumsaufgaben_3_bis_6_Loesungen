#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "dinosaur.h"

class Herbivore : public Dinosaur
{
private:
    float hidingChance();
public:
    Herbivore();
    Herbivore(const string &race, int initialWeight, int maxWeight, double growthRate, double breadingChance);
    ~Herbivore();

    void hide();
};

#endif // HERBIVORE_H
