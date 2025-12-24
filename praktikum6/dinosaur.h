#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class Dinosaur
{
private:

public:
    void Brachiosaurier();
    void Parasaurolophusse();
    void T_Rexe();
    void Raptoren();

    Dinosaur(int c, string r) : currentWeigth(c), race(r) {}

    int currentWeigth;
    int maximalWeigth;
    string race;
    Dinosaur();
    int age();
    bool breed();
};

#endif // DINOSAUR_H
