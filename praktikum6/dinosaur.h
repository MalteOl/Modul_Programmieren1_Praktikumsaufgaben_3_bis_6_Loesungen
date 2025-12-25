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


    int currentWeigth;
    int maximalWeigth;
    string race;
//    Dinosaur();
    Dinosaur(int c, string r);

    int age();
    bool breed();
};

#endif // DINOSAUR_H
