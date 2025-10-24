#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool b = true;
    while(b)
    {
        cout << "Herzlich Willkommen zum Flaechenberechner!" << endl << endl;

        cout << "Von welcher geometrischen Figur soll die Flaeche berechnet werden?" << endl << endl;

        cout << "k) Kreis" << endl;
        cout << "r) Rechteck" << endl;
        cout << "d) Dreieck" << endl << endl;
        cout << "q) Beenden" << endl;

        char auswahl;
        cin >> auswahl;
        switch(auswahl)
        {
        default:
        {
            cout << "Ungueltig "<< endl;
            break;
        }
        case 'k':
        {
            cout << "Bitte geben sie den Radius an: " << endl;
            double radius;
            cin >> radius;
            double pi = 3.141593;

            double kreis = pi * radius * radius;
            cout << "Der Flaecheninhalt betraegt: " << kreis << endl;
            break;

        }
        case 'r':
        {
            cout << "Bitte geben sie a und b ein: " << endl;
            double a;
            double b;
            cin >> a;
            cin >> b;

            double rechteck = a * b;
            cout << "Der Flaecheninhalt betraegt: " << rechteck << endl;
            break;

        }
        case 'd':
        {
            cout << "Bitte geben sie die Höhe und die Länge der Grundseite an: " << endl;
            double höhe;
            double grundseite;
            cin >> höhe;
            cin >> grundseite;

            double dreieck = (grundseite * höhe)/2;
            cout << "Der Flaecheninhalt betraegt: " << dreieck << endl;
            break;

        }
        case 'q':
        {
            b = false;
        }
        }
    }


}
