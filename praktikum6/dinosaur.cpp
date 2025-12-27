#include "dinosaur.h"

// Konstruktor, der die Attribute als Parameter übergeben bekommt
Dinosaur::Dinosaur(int c, string r) : currentWeigth(c), race(r)
{
    c = 0;
    r = "";
}

void Dinosaur::anzeigen()
{
    std::cout << currentWeigth << " and " << race;
}


void Brachiosaurier() {
    //    int currentWeigth = 0.05 * Dinosaur().maximalWeigth();
}

void Parasaurolophusse() {

}

void T_Rexe() {

}

void Raptoren() {

}
