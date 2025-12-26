#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class Dinosaur
{
private:
    int currentWeigth;
    int maximalWeigth;
    string race;
public:
    void Brachiosaurier();
    void Parasaurolophusse();
    void T_Rexe();
    void Raptoren();



//    Dinosaur();
    Dinosaur(int c, string r);

    int age();
    bool breed();
};

#endif // DINOSAUR_H
