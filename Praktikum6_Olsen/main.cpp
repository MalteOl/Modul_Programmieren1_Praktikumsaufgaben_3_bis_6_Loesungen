#include <iostream>
#include "park.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Park park; // non-const object
    park.addCarnivore();
    park.addHerbivore();

    return 0;
}
