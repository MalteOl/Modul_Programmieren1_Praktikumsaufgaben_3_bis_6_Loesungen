#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "dinosaur.h"
#include <vector>


class Carnivore : public Dinosaur
{
private:
//    int currentWeigth;
//    int maximalWeigth;
//    string race;

    std::vector<Carnivore> carnivores;

public:
    Carnivore(const int& c, const string& r);
    void hunt();
};

#endif // CARNIVORE_H
