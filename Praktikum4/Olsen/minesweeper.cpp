#include "minesweeper.h"
#include <iostream>
#include "random.h"
#include <array>
#include <iomanip>


using namespace std;
using std::array;
using std::cin;
using std::cout;

Tile board[rows][cols];
int mines = 20;

void initialize(int mines){
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

}

void display(bool showMines){

    // Spielfeld ausgeben
    for (size_t r = 0; r < rows; r++)
    {
        // Zeilennummer ausgeben
        cout << setw(2) << r + 1 << "|";

        for (size_t c = 0; c < cols; c++)
        {
            if (showMines && board[r][c].allocation == mine) {
                cout << "X ";
            } else if (board[r][c].allocation == hidden) {
                cout << "* ";
            } else {
                if (board[r][c].sumOfAllMinesInAdjacentFields == 0) {
                    cout << ". ";
                } else {
                    cout << " " << board[r][c].sumOfAllMinesInAdjacentFields << " ";
                }
            }
        }
        cout << endl;
    }


    // Spaltennummer ausgeben
    cout << "   -----------------------" << endl;
    cout << "  ";
    for (int c = 0; c < rows; c++) {
        cout << setw(2) << c+1;
    }
    cout << endl;

}

bool processInput() {
    int x, y;

    while (true) {
        cout << "Bitte geben Sie nun Ihren naechsten Zug ein." << endl;
        cout << "Zeile (1-" << rows << ") _Leerzeichen_ Spalte (1-" << cols << "): ";

        cin >> x >> y;

        // Adjust to 0-based indexing
        x--;
        y--;

        // Validate input
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            break;
        }
    }

    // Check if mine was hit
    if (board[x][y].allocation == mine) {
        display(true); // Zeige alle Minen
        return false;
    }

    // Reveal the tile if it's hidden
    if (board[x][y].allocation == hidden) {
        board[x][y].allocation = revealed;
    }

    display(false); // Zeige aktuelles Spielfeld ohne Minen
    return true;
}
