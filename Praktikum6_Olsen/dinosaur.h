#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class Dinosaur
{
protected:
    string m_race;
    int m_maxWeight;
    double m_currentWeigth, m_growthRate, m_breedingChance, m_hidingChance;
public:
    Dinosaur(string race, double currentWeight, int maxWeight,
             double growthRate, double breedingChance, double hidingChance);
    bool age();
    bool breed();
};

#endif // DINOSAUR_H
