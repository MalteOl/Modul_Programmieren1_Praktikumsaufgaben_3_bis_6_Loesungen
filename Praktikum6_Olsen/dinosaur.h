#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class Dinosaur
{
private:
    string m_race;
    int m_initialWeight, m_maxWeight;
    double m_growthRate, m_breadingChance;
public:
    Dinosaur(string race, int initialWeight, int maxWeight, double growthRate, double breadingChance);
    bool age();
    bool bread();
};

#endif // DINOSAUR_H
