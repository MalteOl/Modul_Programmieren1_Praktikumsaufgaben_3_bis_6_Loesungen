#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "battleship.h"

int main()
{
    string player1Name, player2Name;

    cout << "Wie lautet Ihr Name, Player 1?" << endl;
    cin >> player1Name;
    cout << "Wie lautet Ihr Name, Player 2?" << endl;
    cin >> player2Name;

    // An object is constructed by supplying two player names.
    Battleship game(player1Name,player2Name);

    //One game round is then started by simply calling the play function.
    game.play();

    // The Players and their boards are stored in Arrays to make the implementation of the game logic easier.

    return 0;
}
