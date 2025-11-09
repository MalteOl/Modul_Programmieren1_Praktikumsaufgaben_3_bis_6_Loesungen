#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int key;
    string wort;
    vector<string>wortvektor;
    // Schlüssel eingeben (mit Fehlerprüfung)
    cout << "Schluessel (ganze Zahl): ";
    while (!(cin >> key)) {
        cout << "Fehler: Das ist keine Zahl! Bitte erneut eingeben: ";
        cin.clear(); // Fehlerstatus zurücksetzen
        cin.ignore(10000, '\n'); // Eingabepuffer leeren
    }

    // Wort eingeben
    cout << "Wort: ";
    cin >> wort;
    wortvektor.push_back(wort);

    // Großbuchstaben in Kleinbuchstaben umwandeln
    for (int i = 0; i < wort.length(); i++) {
        if (wort[i] >= 'A' && wort[i] <= 'Z')
        {
            wort[i] += 32; // ASCII-Trick für Groß->Klein
        }
    }

    // Verschlüsselung durchführen
    for (int i = 0; i < wort.length(); i++)
    {
        char c = wort[i];
        if (c >= 'a' && c <= 'z')
        {
            c += key;

            // Bereichskorrektur für zyklisches Alphabet
            while (c > 'z') c -= 26;
            while (c < 'a') c += 26;

            wort[i] = c;
        }
    }

    cout << "Verschluesselt: " << wort << endl;

    return 0;
}
