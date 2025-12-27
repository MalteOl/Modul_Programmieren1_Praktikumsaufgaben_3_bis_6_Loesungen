#include "herbivor.h"


//Herbivor::Herbivor(const int& c, const string& r) : {}


//Herbivor::Herbivor(const int &c, const string &r) /*: currentWeigth(5),race("Brachiosaurus")*/
//{

//}

// Konstruktor, der die Attribute als Parameter übergeben bekommt
Herbivor::Herbivor(const int &c, const string &r) : Dinosaur{c,r}
{}

void Herbivor::addHerbivors(Dinosaur *d)
{
    herbivors.push_back(d);

}

void Herbivor::showHerbivors()
{
    std::cout  << ":" << std::endl;
    for (int i=0; i < herbivors.size(); i++) {
        std::cout << "Herbivor " << i << ": " << std::endl;
        herbivors[i]->anzeigen();
    }
}

