#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    Park park; // non-const object

    while (park.sumOfDinos() > 0 && park.sumOfDinos() <= 100) {

        // Let them breed first
        park.breedSimulation();

        // Get hunt
        park.huntSimulation();

        park.passingTime();

    }
    return 0;
}
