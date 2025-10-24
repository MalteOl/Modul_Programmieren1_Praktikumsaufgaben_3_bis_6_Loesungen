#include <iostream>
#include "random.h"
using namespace std;

int main()
{
    cout << "Raten sie die Zahl: ";
    int zahl;
    int random = getRandom(1,10);
    int anzahl =  1;
    for(int i = 0; i <= 5; i++)
    {
        cin >> zahl;
        if (zahl == random)
        {
            cout << "Glückwunsch! Sie haben die Zahl richtig erraten." << endl;
            break;
        }
        else if(i == 5)
        {
            cout << "Sie haben zu oft falsch geraten" << endl;
            break;
        }
        else
        {
            cout << "Es tut mir leid. Sie liegen falsch. Versuch: " << anzahl << endl;
            anzahl++;
        }
    }
}
