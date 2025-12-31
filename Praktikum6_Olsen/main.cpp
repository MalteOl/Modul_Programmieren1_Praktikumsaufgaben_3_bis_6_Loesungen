#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object
    Carnivore *c = new Carnivore(Carnivore());
    Herbivore *h = new Herbivore(Herbivore());

    park.addCarnivore(c);
    park.addHerbivore(h);

    return 0;
}
