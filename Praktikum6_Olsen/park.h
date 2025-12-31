#ifndef PARK_H
#define PARK_H

#include <vector>
#include "carnivore.h"
#include "herbivore.h"

class Park
{
private:
    std::vector<Herbivore*> m_herbivors;
    std::vector<Carnivore*> m_carnivors;

public:
    Park();
    void addHerbivore(string race, int initialWeight, int maxWeight, double growthRate, double breadingChance);
    void addCarnivore(string race, int initialWeight, int maxWeight, double growthRate, double breadingChance);

};

#endif // PARK_H
