#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int key;
    string word, decryptedWord;

    cout << "Bitte Schlüssel eingeben" << endl;
    cin >> key;
    cout << "Bitte nur ein einziges zu verschlüsselndes Wort ohne Leerzeichen eingeben" << endl;
    cin >> word;
    cout << word;


    for (int i = 0; i < word.size(); i++) {

        cout << endl << static_cast<int>(word[i]) << " ";
        cout << word[i] << " ";
        int convertToNumberBetween1And26 = word[i] - 96;
        cout << convertToNumberBetween1And26 << " ";
        int addKey = (convertToNumberBetween1And26 + key) % 26;
        cout << addKey << " ";
        int convertBackToNumberBetween97And122 = addKey + 96;
        cout << convertBackToNumberBetween97And122 << " ";
        string s(1,convertBackToNumberBetween97And122);
        cout << endl << s << " ";

    }


    return 0;
}
