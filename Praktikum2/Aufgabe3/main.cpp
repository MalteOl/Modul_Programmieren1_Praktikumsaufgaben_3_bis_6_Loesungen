#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Geben sie eine Zahl ein: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if(i % 2 != 0)
        {
            int quadrat = i * i;
            cout << quadrat << endl;
        }

    }
}
