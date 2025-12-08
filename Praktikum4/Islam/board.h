#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

constexpr std::size_t ROWS{12};
constexpr std::size_t COLS{12};
extern Tile field[ROWS][COLS];

void initialize(std::size_t mineCount);
void display(bool debug = false);
bool playerMove(std::size_t &remaining, std::size_t &extraLives);
bool revealedEmptyNeighbour(std::size_t r, std::size_t c);
bool checkNeighbours(std::size_t &remaining);
#endif // BOARD_H

