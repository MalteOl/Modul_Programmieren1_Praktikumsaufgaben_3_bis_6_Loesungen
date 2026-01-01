#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object

    // 2x T-Rex
    Carnivore *t_rex = new Carnivore("Tyrannosaurus Rex", 8000*0.05, 8000, 0.2, 0.8, 0);
    park.addCarnivore(t_rex);
    park.addCarnivore(t_rex);

    // 4x Raptor
    Carnivore *rapt = new Carnivore("Raptor", 500*0.05, 500, 0.3, 0.12, 0);
    park.addCarnivore(rapt);
    park.addCarnivore(rapt);
    park.addCarnivore(rapt);
    park.addCarnivore(rapt);

    // 4x Brachiosaurus
    Herbivore *brach = new Herbivore("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5);
    park.addHerbivore(brach);
    park.addHerbivore(brach);
    park.addHerbivore(brach);
    park.addHerbivore(brach);

   // 5x Parasaurolophus
    Herbivore *para = new Herbivore("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75);
    park.addHerbivore(para);
    park.addHerbivore(para);
    park.addHerbivore(para);
    park.addHerbivore(para);
    park.addHerbivore(para);


    return 0;
}
