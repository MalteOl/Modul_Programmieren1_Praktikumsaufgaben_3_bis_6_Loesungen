#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "random.h"


enum Allocation {
    hidden,
    revealed,
    mine
};

struct Tile {
    Allocation allocation;
    int sumOfAllMinesInAdjacentFields;
};


constexpr size_t rows = 12;
constexpr size_t cols = 12;
extern int mines;

extern Tile board[rows][cols];
extern int hiddenTilesRemaining;


void initialize(int mines);
void display(bool showMines);
bool processInput();
bool revealedEmptyNeighbour(int x, int y);
bool checkNeighbours();

#endif // MINESWEEPER_H
