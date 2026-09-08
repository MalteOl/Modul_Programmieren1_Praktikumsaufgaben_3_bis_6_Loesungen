#include <iostream>
#include <array>

using namespace std;
using std::array;

array<int,3> a;

int max(){
    int max = a[0];

    // größte Zahl
    for (int i = 0; i <= 3; i++) {
        if (max<a[i])
            max=a[i];
    }
    cout << "Das Maximum ist " << max << endl;

    return max;
}

int min(){
    int min = a[0];

    // kleinste Zahl
    for (int i = 0; i <= 3; i++) {
        if (min>a[i])
            min=a[i];
    }
    cout << "Das Minimum ist " << min << endl;
    return min;
}

int sum(){
    int sum = a[0];
    for (int i = 1; i <= 3; i++) {
        sum = sum + a[i];
    }
    cout << "Die Summe ist " << sum << endl;
    return sum;
}

int main()
{

    int input;

    // Zahl überprüfen, ob > 0


    do {

        // Zahl in Array ablegen
        for (int i = 0; i <= 3; i++) {
            cout << "Bitte geben Sie eine Zahl ein" << endl;
            cin >> input;
            a[i] = input;
        }

        // Array ausgeben
        for (int i = 0; i <= 3; i++) {
            cout << "Arrayausgabe an " << i << ".ter Stelle: " << a[i] << endl;
        }
        max();
        min();
        sum();


    } while (!(input == 0 || input < 0));

    return 0;
}
