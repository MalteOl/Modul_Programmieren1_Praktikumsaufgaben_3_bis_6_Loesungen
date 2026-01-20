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
    ~Park(); // aus beiden Vektoren alle Pointers löschen
    void addHerbivore(Herbivore *h);
    void removeHerbivore(Herbivore *h);
    void addCarnivore(Carnivore *c);
    void removeCarnivore(Carnivore *c);
    void deathHerbis(int index);
    void deathCarnis(int index);
    void lifeHerbis(int index);
    void lifeCarnis(int index);
    std::vector<int> findPrey();
    void hunt(std::vector<int> potentialPreys);
    void breedSimulation();
    void huntSimulation();
    void passingTime();
    int sumOfDinos();
    int sumOfHerbivors();
    int sumOfCarnivos();
    int sumOfT_Rexes();
private:
    std::vector<Carnivore*> m_carnivors;
    std::vector<Herbivore*> m_herbivors;

};

#endif // PARK_H
