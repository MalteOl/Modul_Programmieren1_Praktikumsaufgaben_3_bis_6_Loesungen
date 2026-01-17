#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>
#include <random>
#include <iostream>

extern std::random_device rd;

using std::string;
using std::cout;
using std::endl;

class Dinosaur
{
public:
    Dinosaur(string race, double currentWeight, int maxWeight,
             double growthRate, double breedingChance, double hidingChance);
    double getCurrentWeigth() const;
    string getRace() const;
    int getMaxWeight() const;
    double getGrowthRate() const;
    double getBreedingChance() const;
    double getHidingChance() const;

    static int getRandom(int lower, int upper);
    bool age();
    bool breed();
    bool diesOfAge();

    void minLife(){life--;}
    int isAlive();

    void setCurrentWeigth(double newCurrentWeigth);

protected:
    // mit m_ für Membervariablen
    string m_race;
    int m_maxWeight;
    double m_currentWeigth, m_growthRate, m_breedingChance, m_hidingChance;
    int life;
};

#endif // DINOSAUR_H
