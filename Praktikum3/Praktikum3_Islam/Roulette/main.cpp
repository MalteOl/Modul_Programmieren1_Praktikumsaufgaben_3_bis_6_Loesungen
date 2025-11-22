#include <iostream>
#include "random.h"
using namespace std;

int main()
{
    int geld = 10000;
    int einsatz;
    int zahl;
    //Roulette
    int nummer = getRandom(0,0);

    while(true)
    {
        if(geld == 0)
        {
            cout << "Sie haben ihr Geld aufgebraucht." << endl;
            break;
        }
        cout << "Willkommen im Roulette." << endl;
        cout << "Ihr verfuegbares Vermoegen belaeuft sich auf: " << geld << "Euro." << endl;
        cout << "Bitte druecken Sie: " << endl;
        cout << "'f' fuer eine Farbe (Rot oder Schwarz)" << endl;
        cout << "'s' fuer eine Spalte" << endl;
        cout << "'z' fuer eine Zahl" << endl;



        char auswahl;
        cin >> auswahl;
        switch(auswahl)
        {
        case 'f':
        {
            cout << "Welche Farbe waehlen sie. (r) fuer rot oder (s) fuer schwarz" << endl;
            char auswahl;
            cin >> auswahl;
                if(auswahl == 'r')
                {
                    cout << "Wie hoch ist ihr Einsatz" << endl;
                    double einsatz;
                    cin >> einsatz;
                    while(true)
                    {
                        if(einsatz < 0 || einsatz > geld)
                        {
                            cout << "Konto nicht ausreichend abgedeckt" << endl;
                            cin >> einsatz;
                        }
                        else if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                            cin >> einsatz;
                        }
                        else
                        {
                            geld -= einsatz;
                            cout << "Sie haben noch: " << geld << " Euro" << endl;
                            break;
                        }
                    }
                    int randomcolor = getRandom(0,1);
                    if(randomcolor == 0)
                    {
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        int gewinn = einsatz * 2;
                        geld += gewinn;
                        cout << "Sie haben " << gewinn << " Euro erhalten" << endl;
                        cout << "Ihr Kontostand betraegt " << geld << " Euro" << endl << endl;
                        break;

                    }
                    else
                    {
                        cout << "Tut mir leid sie haben ihr Geld leider verzockt" << endl;
                        cout << "Ihr Vermoegen liegt bei: " << geld << " Euro" << endl << endl;
                        break;
                    }
                }
                else if(auswahl == 's')
                {
                    cout << "Wie hoch ist ihr Einsatz" << endl;
                    double einsatz;
                    cin >> einsatz;
                    while(true)
                    {
                        if(einsatz < 0 || einsatz > geld)
                        {
                            cout << "Konto nicht ausreichend abgedeckt" << endl;
                            cin >> einsatz;
                        }
                        else if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                            cin >> einsatz;
                        }
                        else
                        {
                            geld -= einsatz;
                            cout << "Sie haben noch: " << geld << " Euro" << endl;
                            break;
                        }
                    }
                    int randomcolor = getRandom(0,1);
                    if(randomcolor == 1)
                    {
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        int gewinn = einsatz * 2;
                        geld += gewinn;
                        cout << "Sie haben " << gewinn << " Euro erhalten" << endl;
                        cout << "Ihr Kontostand betraegt " << geld << " Euro" << endl << endl;
                        break;

                    }
                    else
                    {
                        cout << "Tut mir leid sie haben ihr Geld leider verzockt" << endl;
                        cout << "Ihr Vermoegen liegt bei: " << geld << " Euro" << endl << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Bitte 'r' oder 's' " << endl << endl;
                    break;
                }
            }
        case 's':
        {
            cout << "Wie hoch ist ihr Einsatz" << endl;
            double einsatz;
            cin >> einsatz;
            while(true)
            {
                if(einsatz < 0 || einsatz > geld)
                {
                    cout << "Konto nicht ausreichend abgedeckt" << endl;
                    cin >> einsatz;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    geld -= einsatz;
                    cout << "Sie haben noch: " << geld << " Euro" << endl;
                    break;
                }
            }
            cout << "Auf welche Spalte moechten sie setzen? (1-3)" << endl;
            int spalte;
            while(true)
            {
                cin >> spalte;
                if(spalte == 1 || spalte == 2 || spalte == 3)
                {
                    break;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    cout << "Eingabe ungueltig " << endl;

                }
            }

            int randomspalten = getRandom(1,3);
            if(randomspalten == spalte)
            {
                int gewinn = einsatz * 2;
                geld  = geld + gewinn;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Der Betrag von: " << gewinn << " Euro wird nun in ihrem Konto gutgeschrieben." << endl;
                cout << "Ihr Vermoegen betraegt nun " << geld << endl;
            }
            else
            {
                cout << "Tut mir leid. Sie haben leider verloren." << endl;
                cout << "Ihr Vermoegen belaeuft sich auf:" << geld << " Euro" << endl;
                break;
            }
        }
        case 'z':
        {
            cout << "Wie hoch ist ihr Einsatz (Bitte geben sie eine positive ganze Zahl ein)" <<  endl;
            cin >> einsatz;
            while(true)
            {
                if(einsatz < 0 || einsatz > geld)
                {
                    cout << "Konto nicht ausreichend abgedeckt" << endl;
                    cin >> einsatz;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    geld -= einsatz;
                    break;
                }
            }
            cout << "Ihre Einsatz betraegt: " << einsatz << ". Sie haben noch "
                 << geld << "Euro." << endl;
            cin >> zahl;
            while(true)
            {
                if(zahl < 0 || zahl > 36)
                {
                    cout << "Die eingegebene Zahl ist ungueltig." << endl;
                    cin >> zahl;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    cout << "Sie haben auf die Zahl: " << zahl << "gesetzt" << endl;
                    break;
                }
            }
            if(nummer == zahl)
            {
                int gewinn = einsatz * 35;
                geld  = geld + (gewinn);
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Der Betrag von: " << gewinn << " Euro wird nun in ihrem Konto gutgeschrieben." << endl;
                cout << "Ihr Vermoegen betraegt nun " << geld << endl;
            }
            else
            {
                cout << "Tut mir leid. Sie haben leider verloren." << endl;
                cout << "Ihr Vermoegen belaeuft sich auf:" << geld << " Euro" << endl;
            }
        }
        //Für Großbuchstaben
        case 'F':
        {
            cout << "Welche Farbe waehlen sie. (r) fuer rot oder (s) fuer schwarz" << endl;
            char auswahl;
            cin >> auswahl;
            if(auswahl == 'r')
            {
                cout << "Wie hoch ist ihr Einsatz" << endl;
                double einsatz;
                cin >> einsatz;
                while(true)
                {
                    if(einsatz < 0 || einsatz > geld)
                    {
                        cout << "Konto nicht ausreichend abgedeckt" << endl;
                        cin >> einsatz;
                    }
                    else if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                        cin >> einsatz;
                    }
                    else
                    {
                        geld -= einsatz;
                        cout << "Sie haben noch: " << geld << " Euro" << endl;
                        break;
                    }
                }
                int randomcolor = getRandom(0,1);
                if(randomcolor == 0)
                {
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    int gewinn = einsatz * 2;
                    geld += gewinn;
                    cout << "Sie haben " << gewinn << " Euro erhalten" << endl;
                    cout << "Ihr Kontostand betraegt " << geld << " Euro" << endl << endl;
                    break;

                }
                else
                {
                    cout << "Tut mir leid sie haben ihr Geld leider verzockt" << endl;
                    cout << "Ihr Vermoegen liegt bei: " << geld << " Euro" << endl << endl;
                    break;
                }
            }
            else if(auswahl == 's')
            {
                cout << "Wie hoch ist ihr Einsatz" << endl;
                double einsatz;
                cin >> einsatz;
                while(true)
                {
                    if(einsatz < 0 || einsatz > geld)
                    {
                        cout << "Konto nicht ausreichend abgedeckt" << endl;
                        cin >> einsatz;
                    }
                    else if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                        cin >> einsatz;
                    }
                    else
                    {
                        geld -= einsatz;
                        cout << "Sie haben noch: " << geld << " Euro" << endl;
                        break;
                    }
                }
                int randomcolor = getRandom(0,1);
                if(randomcolor == 1)
                {
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    int gewinn = einsatz * 2;
                    geld += gewinn;
                    cout << "Sie haben " << gewinn << " Euro erhalten" << endl;
                    cout << "Ihr Kontostand betraegt " << geld << " Euro" << endl << endl;
                    break;

                }
                else
                {
                    cout << "Tut mir leid sie haben ihr Geld leider verzockt" << endl;
                    cout << "Ihr Vermoegen liegt bei: " << geld << " Euro" << endl << endl;
                    break;
                }
            }
            else
            {
                cout << "Bitte 'r' oder 's' " << endl << endl;
                break;
            }
        }
        case 'S':
        {
            cout << "Wie hoch ist ihr Einsatz" << endl;
            double einsatz;
            cin >> einsatz;
            while(true)
            {
                if(einsatz < 0 || einsatz > geld)
                {
                    cout << "Konto nicht ausreichend abgedeckt" << endl;
                    cin >> einsatz;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    geld -= einsatz;
                    cout << "Sie haben noch: " << geld << " Euro" << endl;
                    break;
                }
            }
            cout << "Auf welche Spalte moechten sie setzen? (1-3)" << endl;
            int spalte;
            while(true)
            {
                cin >> spalte;
                if(spalte == 1 || spalte == 2 || spalte == 3)
                {
                    break;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    cout << "Eingabe ungueltig " << endl;
                }
            }

            int randomspalten = getRandom(1,3);
            if(randomspalten == spalte)
            {
                int gewinn = einsatz * 2;
                geld  = geld + gewinn;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Der Betrag von: " << gewinn << " Euro wird nun in ihrem Konto gutgeschrieben." << endl;
                cout << "Ihr Vermoegen betraegt nun " << geld << endl;
            }
            else
            {
                cout << "Tut mir leid. Sie haben leider verloren." << endl;
                cout << "Ihr Vermoegen belaeuft sich auf:" << geld << " Euro" << endl;
                break;
            }
        }
        case 'Z':
        {
            cout << "Wie hoch ist ihr Einsatz (Bitte geben sie eine positive ganze Zahl ein)" <<  endl;
            cin >> einsatz;
            while(true)
            {
                if(einsatz < 0 || einsatz > geld)
                {
                    cout << "Konto nicht ausreichend abgedeckt" << endl;
                    cin >> einsatz;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    geld -= einsatz;
                    break;
                }
            }
            cout << "Ihre Einsatz betraegt: " << einsatz << ". Sie haben noch "
                 << geld << "Euro." << endl;
            cin >> zahl;
            while(true)
            {
                if(zahl < 0 || zahl > 36)
                {
                    cout << "Die eingegebene Zahl ist ungueltig." << endl;
                    cin >> zahl;
                }
                else if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Ungueltig. Bitte eine Zahl eingeben" << endl;
                    cin >> einsatz;
                }
                else
                {
                    cout << "Sie haben auf die Zahl: " << zahl << "gesetzt" << endl;
                    break;
                }
            }
            if(nummer == zahl)
            {
                int gewinn = einsatz * 35;
                geld  = geld + (gewinn);
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "!!Glueckwunsch sie haben richtig geraten!!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Der Betrag von: " << gewinn << " Euro wird nun in ihrem Konto gutgeschrieben." << endl;
                cout << "Ihr Vermoegen betraegt nun " << geld << endl;
            }
            else
            {
                cout << "Tut mir leid. Sie haben leider verloren." << endl;
                cout << "Ihr Vermoegen belaeuft sich auf:" << geld << " Euro" << endl;
            }
        }

        }

    }
}
