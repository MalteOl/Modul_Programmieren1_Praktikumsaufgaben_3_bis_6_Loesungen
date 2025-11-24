#include <iostream>
#include "minesweeper.h"
#include <array>
#include <windows.h>
#include "random.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    initialize(mines);

    // Display initial board (without showing mines)
    display(false);

    // Game loop
    bool gameRunning = true;

    while (gameRunning) {
        gameRunning = processInput();
    }

    // Game over message
    if (!gameRunning) {
        cout << "\n**** B0000M ****" << endl;
        cout << "Leider verloren." << endl;
    } else {
        cout << "\nHerzlichen Glückwunsch! Sie haben gewonnen!" << endl;
    }

    // Show final board with mines
    display(true);

    return 0;
}
