#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object

    // 2x T-Rex
    for (int i = 0; i < 2; ++i) {
        Carnivore *t_rex = new Carnivore("Tyrannosaurus Rex", 8000*0.05, 8000, 0.2, 0.8, 0);
        park.addCarnivore(t_rex);
    }
    // 4x Raptor
    for (int i = 0; i < 4; ++i) {
        Carnivore *rapt = new Carnivore("Raptor", 500*0.05, 500, 0.3, 0.12, 0);
        park.addCarnivore(rapt);
    }

    // 4x Brachiosaurus
    for (int i = 0; i < 4; ++i) {
        Herbivore *brach = new Herbivore("Brachiosaurus", 30000*0.05, 30000, 0.2, 0.2, 0.5);
        park.addHerbivore(brach);
    }

    // 5x Parasaurolophus
    for (int i = 0; i < 5; ++i) {
        Herbivore *para = new Herbivore("Parasaurolophus", 1500*0.05, 1500, 0.4, 0.85, 0.75);
        park.addHerbivore(para);
        //        cout << park.m_herbivors[i] << endl;
    }

    // Vektoren ausgeben
    park.printHerbivore();

    return 0;
}
