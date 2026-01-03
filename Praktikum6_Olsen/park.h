#ifndef PARK_H
#define PARK_H

#include <vector>
#include "carnivore.h"
#include "herbivore.h"

class Park
{
public:
    Park();
    void addHerbivore(Herbivore *h);
    void addCarnivore(Carnivore *c);
    void passingTime();
    int sumOfDinos();
    int sumOfHerbivors();
    int sumOfCarnivos();
private:
    std::vector<Carnivore*> m_carnivors;
    std::vector<Herbivore*> m_herbivors;

};

#endif // PARK_H
