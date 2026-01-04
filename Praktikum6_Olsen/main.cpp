#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    Park park; // non-const object

    while (park.sumOfDinos() > 0 && park.sumOfDinos() <= 100) {
        park.passingTime();
        cout << "Verbleibende Dino-Population: " << park.sumOfDinos() << endl;
        cout << "Herbivoren: " << park.sumOfHerbivors() << endl;
        cout << "Karnivoren: " << park.sumOfCarnivos() << endl;
        cout << "T-Rexe: " << park.sumOfT_Rexes() << endl;

    }
    return 0;
}
