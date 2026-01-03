#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object

    while (park.sumOfDinos() <= 100) {
        park.passingTime();
        cout << "Verbleibende Dino-Population: " << park.sumOfDinos();
    }
    return 0;
}
