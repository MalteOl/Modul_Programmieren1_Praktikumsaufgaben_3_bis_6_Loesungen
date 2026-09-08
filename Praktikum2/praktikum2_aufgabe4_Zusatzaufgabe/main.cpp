#include <iostream>

using namespace std;

int main()
{
    int zahl;
    cout << "bitte zahl eingeben" << endl;
    cin >> zahl;
    int copy = zahl;

    if (zahl < 0) {
        zahl = zahl * (-1);
        while(zahl!=0){
            cout << zahl%10 << ",";
            zahl = zahl /10;
        }
        if (copy < 0){
            cout << "-";
        }
    }
    else {
        while(zahl!=0){
            cout << zahl%10 << ",";
            zahl = zahl /10;
        }

        if (copy > 0)
            cout << "+";
    }

    return 0;

}
