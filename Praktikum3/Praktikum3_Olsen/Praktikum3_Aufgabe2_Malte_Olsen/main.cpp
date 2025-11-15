#include <iostream>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <windows.h>


#define N 80

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string plaintext;
    unsigned key;
    string cipher;
    cout << "Klartext eingeben: ";
    cin >> plaintext;

    cout << "Schlüssel eingeben: ";
    cin >> key;

    // von String in Integer umwandeln und um Wert des Schlüssels verschieben
    for (int i = 0; i < plaintext.size(); i++) {
        cout << plaintext[i] << " wird zu " << int(plaintext[i]) << " wird zu "
             << int(plaintext[i]) + key << " wird zu " << std::string(1,static_cast<char>(int(plaintext[i]) + key)) << endl;

    }

    // cout << "Verschlüsselter Text: " << cipher << endl;
    return 0;
}
