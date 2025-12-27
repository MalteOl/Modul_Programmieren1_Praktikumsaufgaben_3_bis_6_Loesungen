#ifndef DINOSAUR_H
#define DINOSAUR_H
#include <string>

class Dinosaur
{
protected:
    double curWeight;
    double maxWeight;
    double growthRate;
    double breedChance;
    bool alive;
    std::string race;

public:
    Dinosaur(double maxWeight,
             double growthRate,
             double breedChance,
             std::string race,
             double initialWeightFactor);
    //
    virtual Dinosaur *reproduce();
    void age();
    bool breed();
    bool isAlive();
    void printStatus();
    double getWeight();
    std::string getSpecies(); // Gibt die Art des Dinosauriers zurÃ¼ck
};

#endif // DINOSAUR_H
