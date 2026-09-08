#include <iostream>
#include <windows.h>

using namespace std;


void Kreis() {
    cout << "Wird noch implementiert ";

}

void Rechteck() {
    cout << "Wird noch implementiert ";
}

void Dreieck() {
    cout << "Wird noch implementiert ";
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char auswahl;


    cout << "Herzlich Willkommen zum Flächenberechner!" << endl << endl;
    cout << "Von welcher geometrischen Figur soll die Fläche berechnet werden?" << endl << endl;
    cout << "k) Kreis" << endl;
    cout << "r) Rechteck" << endl;
    cout << "d) Dreieck" << endl << endl;
    cout << "q) Beenden" << endl;
    cin >> auswahl;


    switch (auswahl) {
    case 'q': cout << " Programm wird beendet\n" << endl; break;
    case 'k': Kreis(); break;
    case 'r': Rechteck(); break;
    case 'd': Dreieck(); break;
    default: cout << "Ungueltige Eingabe\n" << endl; break;
    }




    return 0;
}
