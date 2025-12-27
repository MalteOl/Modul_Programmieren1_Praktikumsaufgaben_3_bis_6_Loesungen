#include "park.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Zufallszahl-Seed setzen

    Park jurassicPark;

    char choice;
    int timeSteps = 0;

    cout << "Willkommen in Jurassic Park Simulation!" << endl;

    do {
        cout << "\n--- Zeitschritt " << ++timeSteps << " ---" << endl;
        jurassicPark.passingTime();

        cout << "\nWeiter simulieren? (j = ja, andere Taste = nein): ";
        std::cin >> choice;

    } while (choice == 'j' || choice == 'J');

    cout << "\nSimulation beendet nach " << timeSteps << " Zeitschritten." << endl;

    return 0;
}
