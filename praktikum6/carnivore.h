#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "dinosaur.h"


class Carnivore : public Dinosaur
{
private:
    bool hide();
public:
    Carnivore(int currentWeigth, string race);
    void hunt();
};

#endif // CARNIVORE_H
