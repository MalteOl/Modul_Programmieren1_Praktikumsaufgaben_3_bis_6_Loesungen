#include <iostream>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
using std::string;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string plaintext;
    unsigned key;
    int i = 0, j = 0;
    vector<string> cipher(800000);
    bool numberGuess = false;

    // checken, ob Wort nur aus Buchstaben bestehend ist
    do {
        cout<< "Bitte Wort ohne Leerzeichen eingeben" << endl;
        cin>>plaintext;

        numberGuess = true;
        for (int i = 0; i < plaintext.size(); i++) {
            if (!(isalpha(plaintext[i]))) {
                numberGuess = false;
                break;
            }
        }

    } while (!numberGuess);

    cout << "Schlüssel eingeben: ";
    cin >> key;

    for (int i = 0; i < plaintext.size(); i++) {
        // tmp ist die um key verschobene Position des Buchstabens
        // mit tolower werden Großbuchstaben in Kleinbuchstaben umgewandelt
        // mit -'a' wird der ASCII-Wert von 'a', also 97, abgezogen; somit
        // kommen wir auf einen Bereich von 0 bis 25
        int tmp = (tolower(plaintext[i]) - 'a') + key;

        cout << tmp << endl;

        // falls tmp negativ ist, muss mittels doppeltem Modulorechnen wieder
        // in den positiven Bereich umgerechnet werden
        if (tmp<0)
            tmp = ((tmp % 26)+26)%26 + 'a';
        cipher[j++] = tmp;
    }

    for (int i = 0; i < cipher.size(); i++) {
        cout << cipher[i];
    }


    return 0;
}
