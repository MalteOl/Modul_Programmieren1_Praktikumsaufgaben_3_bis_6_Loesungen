#include <iostream>

using namespace std;

int main()
{
    int n, i = 1;
    cout << "Bitte Zahl eingeben: ";
    cin >> n;
    while (i <= n)
    {
        cout << i << " hoch zwei ist: " << (i * i) << endl;
        i=i+2;
    }
    return 0;
}
