#ifndef TILE_H
#define TILE_H

#include <cstddef>

enum class Allocation { Hidden, Revealed, Mine };

struct Tile
{
    Allocation state = Allocation::Hidden;
    std::size_t nachbarminen = 0;
    bool hasExtraLife = false;
};

#endif // TILE_H
