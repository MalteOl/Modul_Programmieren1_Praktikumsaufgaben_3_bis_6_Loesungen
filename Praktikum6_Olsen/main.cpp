#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    Park park; // non-const object

    int answer = 0;

    while (park.sumOfDinos() > 0 && park.sumOfDinos() <= 100) {

        // Let them breed first
//        park.breedSimulation();

        // Get hunt
//        park.huntSimulation();

        park.passingTime();

        std::cin >> answer;
        if (std::cin.fail()) {
            std::cout << "Zahl eingeben, fuer naechsten Zeitabschnitt" << endl;
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                answer = 0;
            }


    }
    return 0;
}
