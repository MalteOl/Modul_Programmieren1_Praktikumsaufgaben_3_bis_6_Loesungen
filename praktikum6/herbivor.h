#ifndef HERBIVOR_H
#define HERBIVOR_H
#include "dinosaur.h"
#include <vector>


class Herbivor : public Dinosaur
{
private:
    bool hide();
//    int currentWeigth;
//    string race;
    std::vector<Dinosaur*> herbivors;

public:
    Herbivor(const int& c, const string& r);
    void addHerbivors(Dinosaur *d);
    void showHerbivors();
};

#endif // HERBIVOR_H
