#ifndef HERBIVOR_H
#define HERBIVOR_H
#include "dinosaur.h"
#include <vector>


class Herbivor : public Dinosaur
{
private:
    bool hide();
    int currentWeigth;
    string race;
    std::vector<Herbivor> herbivors;

public:
    Herbivor(int c, string r);
};

#endif // HERBIVOR_H
