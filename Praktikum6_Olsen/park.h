#ifndef PARK_H
#define PARK_H

#include <vector>
#include "carnivore.h"
#include "herbivore.h"

class Park
{
private:
    std::vector<Carnivore*> m_carnivors;
    std::vector<Herbivore*> m_herbivors;

public:

    Park();
    void addHerbivore(Herbivore* h);
    void addCarnivore(Carnivore* c);
    void printHerbivore();

};

#endif // PARK_H
