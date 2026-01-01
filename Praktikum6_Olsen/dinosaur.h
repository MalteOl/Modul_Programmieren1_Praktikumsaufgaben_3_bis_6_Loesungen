#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class Dinosaur
{
protected:
    string m_race;
    int m_maxWeight;
    double  m_initialWeight, m_growthRate, m_breadingChance, m_hidingChance;
public:
    Dinosaur(string race, double initialWeight, int maxWeight, double growthRate, double breadingChance, double hidingChance);
    bool age();
    bool bread();
};

#endif // DINOSAUR_H
