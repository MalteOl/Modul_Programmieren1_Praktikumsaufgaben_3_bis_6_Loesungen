#include "board.h"
#include <iostream>
int main()
{
    constexpr std::size_t MINES = 18;
    initialize(MINES);
    std::size_t remaining = ROWS * COLS - MINES;
    //Leben initialisiert
    std::size_t lives = 0;

    while (true) {
        std::cout << "\nVerbleibende Felder: " << remaining << " | Extraleben: " << lives << '\n';
        display(false);
        display(true);

        if (!playerMove(remaining, lives))
            break;

        if (remaining == 0) {
            display(true);
            std::cout << "\n*** Herzlichen Glückwunsch, Sie haben alle Felder aufgedeckt! ***\n";
            break;
        }
    }
    return 0;
}






