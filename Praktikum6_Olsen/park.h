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
    void addHerbivore(Herbivore* h);
    void addCarnivore(Carnivore* c);

};

#endif // PARK_H
