#include <iostream>
// #include "random.h"
// #include <random>
#include <windows.h>


using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // int rightNumber = getRandom(1,10);
    int rightNumber;

    int counter = 0;
    int guessedNumber;

    //Erweiterung: Die Zahl wird nicht mehr zufällig berechnet, sondern vom Benutzer eingegeben. Dabei
    //muss kontrolliert werden, ob die eingegebene Zahl innerhalb des Bereichs liegt. Ist dies nicht
    //der Fall
    do {
        cout << "Bitte geben Sie eine Zahl zwischen 1 und 10 ein" << endl;
        cin >> rightNumber;

        if ((1 <= rightNumber) && (rightNumber <= 10)) {
            break;
        }
    } while (!(1 <= rightNumber) || !(rightNumber <= 10));


    do {
        cout << "Bitte raten Sie eine Zahl zwischen 1 und 10" << endl;
        cin >> guessedNumber;
        if (guessedNumber == rightNumber) {
            cout << "Herzlichen Glückwunsch! Sie haben richtig geraten." << endl;
            break;
        }
        cout << "Falsch geraten. Weiter raten!" << endl;
        counter++;
        cout << "Sie befinden sich im " << counter << ". Rateversuch" << endl;
        if (counter >= 5) {
            cout << "Sie hatten bereits 5 Rateversuche. Nun ist Schluss." << endl;
            break;        }
    } while (guessedNumber != rightNumber);

    cout << endl;
    return 0;
}
