#include <iostream>
#include "random.h"
#include <random>
#include <windows.h>


using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int budgetOfPlayer = 10000;
    int betMoney;
    int betNumber;
    int realNumber;

    int choice;
    string colour, column;
    int number;

    do {


        // Budgetlimit
        do {
            cout << "Wie hoch ist Ihr Einsatz?" << endl;
            cin >> betMoney;
            if ((betMoney > 0) && (betMoney <= budgetOfPlayer)) {
                break;
            }
            cout << "Bitte mehr als 0 € und weniger als " << budgetOfPlayer << " € ausgeben" << endl;
        } while (!(betMoney > 0) || !(betMoney >= budgetOfPlayer));



        do {
            // Zahlenrad neu drehen
            realNumber = getRandom(1,10);
            cout <<realNumber; // bitte auskommentieren für Live-Zustand

            cout << "Auf welche Zahl wetten Sie?" << endl;
            cin >> betNumber;

            cout << "Im Roulette-Rad ist die Zahl " << realNumber << " gefallen." << endl;

            if (realNumber != betNumber) {
                budgetOfPlayer -= betMoney;
                cout << "Sie haben verloren!" << endl << "Sie haben noch "
                     << budgetOfPlayer << " € übrig." << endl;
            } else {
                budgetOfPlayer = budgetOfPlayer * 35 + betMoney;
                cout << "Sie haben gewonnen!" << endl << "Sie haben noch "
                     << budgetOfPlayer << " € übrig." << endl;
            }

            std::cout << "1 Farbe" << std::endl;
            std::cout << "2 Spalte" << std::endl;
            std::cout << "3 Zahl" << std::endl;
            std::cout << "0 Programm beenden" << std::endl;
            std::cout << "Wählen Sie eine Option: ";

            while (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ungültige Eingabe. Bitte wählen Sie eine Zahl zwischen 0 und 3: ";
            }

            switch (choice) {
            case 1: {
                cout << "1 Farbe [Rot] oder [Schwarz]" << endl;
                cin >> colour;
                if (colour == "Rot") {
                    ((realNumber%2==0) && (realNumber != 0) && (betNumber != 0)) ?
                        cout << "Ihr Farbentipp auf Rot war richtig." << endl :
                        cout << "Ihr Farbentipp auf Rot war falsch." << endl;
                    budgetOfPlayer += betMoney;
                }
                if (colour == "Schwarz") {
                    ((realNumber%2!=0) && (realNumber != 0) && (betNumber != 0)) ?
                        cout << "Ihr Farbentipp auf Schwarz war richtig." << endl :
                        cout << "Ihr Farbentipp auf Schwarz war falsch." << endl;
                    budgetOfPlayer += betMoney;
                }
                break;
            }
            case 2: {
                vector<int> v1 = {1,4,7,10,13,16,19,22,25,28,31,34}; // Spalte 1
                vector<int> v2 = {2,5,8,11,14,17,20,23,26,29,32,35}; // Spalte 2
                vector<int> v3 = {3,6,9,12,15,18,21,24,27,30,33,36}; // Spalte 3

                cout << "2 Spalte [1], [2] oder [3]" << endl;
                cin >> column;

                bool numberGuess = false;

                // Spalte 1
                if(column=="1"){
                    for (int i = 0; i < v1.size(); i++) {
                        if (v1[i]==realNumber)
                            numberGuess = true;
                    }

                }

                // Spalte 2

                if(column=="2"){
                    for (int i = 0; i < v2.size(); i++) {
                        if (v2[i]==realNumber)
                            numberGuess = true;
                    }
                }
                // Spalte 3

                if(column=="3"){
                    for (int i = 0; i < v3.size(); i++) {
                        if (v3[i]==realNumber)
                            numberGuess = true;
                    }
                }

                if (numberGuess == true) {
                    cout << "Sie haben mit " << column << " richtig geraten!";
                    budgetOfPlayer += 2*betMoney;
                    cout << " Sie haben noch " << budgetOfPlayer << " € übrig" << endl;
                } else {
                    budgetOfPlayer -= betMoney;
                    cout << "Sie haben mit " << column << " falsch geraten!";
                    cout << " Sie haben noch " << budgetOfPlayer << " € übrig" << endl;
                }

                break;
            }
            case 3: {
                cout << "3 Zahl zwischen [0] und [36]" << endl;
                realNumber = getRandom(0,36);
                cout << realNumber; // bitte auskommentieren für Live-Zustand
                cin >> number;
                if (realNumber != number) {
                    budgetOfPlayer -= betMoney;
                    cout << "Sie haben verloren!" << endl << "Sie haben noch "
                         << budgetOfPlayer << " € übrig." << endl;
                } else {
                    budgetOfPlayer = budgetOfPlayer * 35 + number;
                    cout << "Sie haben gewonnen!" << endl << "Sie haben noch "
                         << budgetOfPlayer << " € übrig." << endl;
                }
                break;
            }
            default:
                std::cout << "Ungueltige Option. Bitte wählen Sie erneut." << std::endl;
            }
        } while (choice != 0);



    } while (budgetOfPlayer > 0);




    return 0;
}
