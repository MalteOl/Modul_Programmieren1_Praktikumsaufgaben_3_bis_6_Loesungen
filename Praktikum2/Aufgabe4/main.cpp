#include <iostream>

using namespace std;

int main()
{
    cout << "Geben Sie eine dreistellige Zahl ein" << endl;
    int zahl;
    cin >> zahl;
    if (zahl > 999 || zahl < 0)
    {
        cout << "Eine 3 stellige Zahl";
    }
    else
    {
        int hunderter = zahl / 100 % 10;
        int zehner = zahl / 10 % 10;
        int einser = zahl % 10;
        cout << hunderter << endl << zehner << endl << einser << endl;
    }
}
