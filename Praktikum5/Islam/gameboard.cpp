#include "gameboard.h"
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

GameBoard::GameBoard() {
    for (auto& row : m_enemyBoard) {
        row.fill('.');
    }
}

void GameBoard::printBoard() {

    std::array<std::array<char, 10>, 10> grid;
    for (auto& row : grid) row.fill('.');


    for (size_t shipIdx = 0; shipIdx < m_ships.size(); shipIdx++) {

        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                if (m_ships[shipIdx].hasPartIn(row, col)) {
                    Part& part = m_ships[shipIdx].getPartIn(row, col);

                    if (m_ships[shipIdx].isSunk()) {
                        grid[row][col] = '#';
                    } else if (part.isDamaged()) {
                        grid[row][col] = 'X';
                    } else {
                        grid[row][col] = '0' + shipIdx;
                    }
                }
            }
        }
    }

    std::cout << "  ";
    for (int i = 0; i < 10; i++) std::cout << i << " ";
    std::cout << "\n";

    for (int row = 0; row < 10; row++) {
        std::cout << row << " ";
        for (int col = 0; col < 10; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << "\n";
    }
}

void GameBoard::printEnemyBoard() {
    std::cout << "  ";
    for (int i = 0; i < 10; i++) std::cout << i << " ";
    std::cout << "\n";

    for (int row = 0; row < 10; row++) {
        std::cout << row << " ";
        for (int col = 0; col < 10; col++) {
            std::cout << m_enemyBoard[row][col] << " ";
        }
        std::cout << "\n";
    }
}

bool GameBoard::hit(int row, int col) {
    for (Ship& ship : m_ships) {
        if (ship.hasPartIn(row, col)) {
            ship.getPartIn(row, col).setDamaged();
            return true;
        }
    }
    return false;
}

void GameBoard::mark(int row, int col, bool wasHit) {
    if (row >= 0 && row < 10 && col >= 0 && col < 10) {
        m_enemyBoard[row][col] = wasHit ? 'X' : 'O';
    }
}

void GameBoard::randomPlaceShips() {
    std::vector<int> lengths = {5,4,4,3,3,3,2,2,2,2};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> posDist(0, 9);
    std::uniform_int_distribution<> dirDist(0, 3);

    for (int i = 0; i < lengths.size(); i++) {
        int size = lengths[i];
        bool placed = false;
        int attempts = 0;

        while (!placed && attempts < 100) {
            attempts++;
            int row = posDist(gen);
            int col = posDist(gen);
            Direction dir = static_cast<Direction>(dirDist(gen));

            bool canPlace = true;
            int tempRow = row;
            int tempCol = col;

            for (int j = 0; j < size; j++) {
                if (tempRow < 0 || tempRow > 9 || tempCol < 0 || tempCol > 9) {
                    canPlace = false;
                    break;
                }

                for (int k = 0; k < i; k++) {
                    if (m_ships[k].hasPartIn(tempRow, tempCol)) {
                        canPlace = false;
                        break;
                    }
                }

                if (!canPlace) break;

                switch (dir) {
                case Direction::north: tempRow--; break;
                case Direction::east:  tempCol++; break;
                case Direction::south: tempRow++; break;
                case Direction::west:  tempCol--; break;
                }
            }

            if (canPlace) {
                m_ships[i] = Ship(row, col, size, dir);
                placed = true;
            }
        }

        if (!placed) {
            throw std::runtime_error("Could not place ship after 100 attempts");
        }
    }
}

bool GameBoard::allShipsSunk() {
    for (Ship& ship : m_ships) {
        if (!ship.isSunk()) return false;
    }
    return true;
}
