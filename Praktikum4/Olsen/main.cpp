#include <iostream>
#include "minesweeper.h"
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

    while (gameRunning && hiddenTilesRemaining > 0) {
        gameRunning = processInput();
        if (gameRunning) {
            // Keep checking neighbors until no more tiles are revealed
            while (checkNeighbours()) {
                display(false);
            }
            display(false);
        }
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
