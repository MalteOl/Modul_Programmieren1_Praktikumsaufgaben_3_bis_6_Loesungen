#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>
#include <random>
extern std::random_device rd;

using std::string;

class Dinosaur
{
public:
    static int getRandom(int lower, int upper);
    Dinosaur(string race, double currentWeight, int maxWeight,
             double growthRate, double breedingChance, double hidingChance);
    bool age();
    bool breed();
    double currentWeigth() const;
protected:
    string m_race;
    int m_maxWeight;
    double m_currentWeigth, m_growthRate, m_breedingChance, m_hidingChance;
};

#endif // DINOSAUR_H
