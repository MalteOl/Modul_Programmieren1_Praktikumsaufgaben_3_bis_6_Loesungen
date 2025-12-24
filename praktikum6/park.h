#ifndef PARK_H
#define PARK_H
#include <vector>
#include "herbivor.h"
#include "carnivore.h"

using std::vector;

class Park
{
public:
    Park();
    Park(int weigth, int growth, int fertilityRate, int hidingChance);
    vector<Carnivore> carnivores;
private:
    void passingTime();
};


#endif // PARK_H
