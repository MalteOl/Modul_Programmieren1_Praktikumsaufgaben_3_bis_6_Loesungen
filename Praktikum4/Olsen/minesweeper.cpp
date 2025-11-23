#include "minesweeper.h"
#include <iostream>
#include "random.h"

using namespace std;
using std::array;
using std::cin;
using std::cout;

Tile board[rows][cols];
int mines = 20;

void initialize(){
    // 1. Anlegen des Spielfelds und Initialisieren aller Felder mit "hidden",
    // noch keine benachbarten Minen
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            board[r][c].allocation = hidden;
            board[r][c].sumOfAllMinesInAdjacentFields = 0;
        }
    }

    // 2. Minen zufällig verteilen
    int minesPlaced = 0;
    for (size_t i = 0; i < mines; i++)
    {
        size_t r = getRandom(0, rows - 1);
        size_t c = getRandom(0, cols - 1);

        if (board[r][c].allocation != mine) {
            board[r][c].allocation = mine;
            minesPlaced++;
        }
    }

    // 3. Anzahl Minen in Nachbarschaft ermitteln
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            if (board[r][c].allocation != mine) {
                int count = 0;

                // Check all 8 possible neighbors
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) continue; // Skip current tile

                        int nr = r + dr;
                        int nc = c + dc;

                        // Check if neighbor is within bounds
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < rows) {
                            if (board[nr][nc].allocation == mine) {
                                count++;
                            }
                        }
                    }
                }
                board[r][c].sumOfAllMinesInAdjacentFields = count;
            }
        }
    }
    // Spielfeld ausgeben
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            cout << board[r][c].allocation << " ";
        }
        cout << endl;
    }
}




