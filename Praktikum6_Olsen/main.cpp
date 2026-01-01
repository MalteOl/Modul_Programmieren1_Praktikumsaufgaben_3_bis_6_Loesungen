#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object

    while (park.sumOfDinos() <= 100) {
        park.passingTime();
    }
    return 0;
}
