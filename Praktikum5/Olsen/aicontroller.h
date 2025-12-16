#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "gameboard.h"

struct Coordinate{
    int x;
    int y;
};

class aiController
{

public:
    aiController();
    static Coordinate shoot(const GameBoard &board);

};

#endif // AICONTROLLER_H
