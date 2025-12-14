#include "battleship.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>


Battleship::Battleship(const std::string& player1Name, const std::string& player2Name)
    : m_players{Player(player1Name), Player(player2Name)}
{

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}


void Battleship::play() {
    for (GameBoard& board : m_boards) {
        board.randomPlaceShips();
    }

    int activePlayerIdx = std::rand() % 2;
    int inactivePlayerIdx = 1 - activePlayerIdx;

    std::cout << "Spiel beginnt! "
              << m_players[activePlayerIdx].getName()
              << " startet.\n\n";

    while (true) {
        std::cout << "\n--- " << m_players[activePlayerIdx].getName() << " ist am Zug ---\n";

        std::cout << "\nDein Spielfeld:\n";
        m_boards[activePlayerIdx].printBoard();

        std::cout << "\nSchmierzettel (Gegnerisches Spielfeld):\n";
        m_boards[activePlayerIdx].printEnemyBoard();

        int row, col;
        std::cout << "Bitte Zielkoordinaten eingeben (Reihe Spalte): ";
        std::cin >> row >> col;

        bool hit = m_boards[inactivePlayerIdx].hit(row, col);

        m_boards[activePlayerIdx].mark(row, col, hit);

        std::cout << (hit ? "Treffer!" : "Wasser!") << "\n";

        if (m_boards[inactivePlayerIdx].allShipsSunk()) {
            std::cout << "\n*************************************************\n";
            std::cout << m_players[activePlayerIdx].getName() << " hat gewonnen!\n";
            std::cout << "*************************************************\n";

            m_players[activePlayerIdx].addGameWon();
            m_players[inactivePlayerIdx].addGameLost();
            break;
        }

        std::swap(activePlayerIdx, inactivePlayerIdx);
    }
}
