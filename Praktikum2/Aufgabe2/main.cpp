#include <iostream>

using namespace std;

int main()
{
    cout << "Bitte geben Sie eine positive Ganzzahl ein: " << endl;
    int zahl;
    int sum = 0;
    int mindestens;
    int maximum;
    bool erstezahl = true;
    while(true)
    {
        cin >> zahl;
        //Überprüfen, ob es die ersten zahlen sind
        if(erstezahl == true)
        {
            mindestens = zahl;
            maximum = zahl;
            erstezahl = false;
        }

        if(zahl == 0 || zahl < 0)
        {
            break;
        }

        //Summe
        sum = sum + zahl;
        //min
        if(zahl < mindestens)
        {
            mindestens = zahl;
        }
        //max
        if(zahl > maximum)
        {
            maximum = zahl;
        }
    }
    cout << "Die Zahlen die sie eingeben haben sind: " << endl;
    cout << "Summe: " << sum << endl;
    cout << "Minimum: " << mindestens << endl;
    cout << "Maximum: " << maximum << endl;


}
