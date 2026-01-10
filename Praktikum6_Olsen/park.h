#ifndef PARK_H
#define PARK_H

#include <vector>
#include "carnivore.h"
#include "herbivore.h"

using std::cout;
using std::endl;

class Park
{
public:
    Park();
    void addHerbivore(const Herbivore &h);
    void addCarnivore(const Carnivore &c);
    void breedSimulation();
    void huntSimulation();
    void passingTime();
    int sumOfDinos();
    int sumOfHerbivors();
    int sumOfCarnivos();
    int sumOfT_Rexes();
private:
    std::vector<Carnivore> m_carnivors;
    std::vector<Herbivore> m_herbivors;

};

#endif // PARK_H
