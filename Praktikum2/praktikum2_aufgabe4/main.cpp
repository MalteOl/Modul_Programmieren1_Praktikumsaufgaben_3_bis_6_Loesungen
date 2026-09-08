#include <iostream>
#include <string>
#include <vector>

using std::size_t;
using namespace std;

int main()
{
    int zahl, dreierstelle, zweierstelle, einerstelle;

    cout << "Bitte eine dreistellige Zahl eingeben" << endl;
    cin >> zahl;

    einerstelle = (zahl/10)/10;
    cout << "An erster Stelle steht die: " << einerstelle << endl;

    zweierstelle = (zahl/10)%10;
    cout << "An zweiter Stelle steht die: " << zweierstelle << endl;


    cout << "An nächster Stelle steht die: " << (zahl/10)%10 << endl;

    dreierstelle = zahl % 10;
    cout << "An dritter Stelle steht die: " << dreierstelle << endl;

    // // Erweiterung
    // string number;
    // char positiveSign = '+';
    // char comma = ', ';


    // cout << "Geben Sie eine beliebig lange Zahl ein" << endl;
    // cin >> number;
    // cout << "Die Zahl in ihre einzelnen Ziffern umgekehrt zerlegt ergibt: " << endl;

    // int lastNumber = number[number.size()];


    // cout  << "letzte Ziffer: " << lastNumber << endl;
    // cout << "erste Ziffer: " << number[0];


    // for (int i = number.size(); i >= 0; i--) {
    //     cout  << endl << "Das ist der "  << i << ".te Wert: " << number[i] << ", ";
    // }

    return 0;
}
