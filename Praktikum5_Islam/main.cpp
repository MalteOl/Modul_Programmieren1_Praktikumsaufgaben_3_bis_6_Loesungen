#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "battleship.h"

int main()
{

    std::string player1, player2;
    cout << "Spieler 1 Name: ";
    cin >> player1;
    cout << "Spieler 2 Name: ";
    cin >> player2;


    Battleship game(player1, player2);
    game.play();

    return 0;
}
