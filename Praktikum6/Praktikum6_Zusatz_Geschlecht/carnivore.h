#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "dinosaur.h"
#include "herbivore.h"

class Carnivore : public Dinosaur
{
public:
    Carnivore(const string &race, double currentWeigth, int maxWeight,
              double growthRate, double breedingChance, double hidingChance);
    ~Carnivore();

    bool hunt(Herbivore &herbivore);
    bool getFed() const;
    void setFed(bool fedValue);

private:
    bool m_fed;
};

#endif // CARNIVORE_H
