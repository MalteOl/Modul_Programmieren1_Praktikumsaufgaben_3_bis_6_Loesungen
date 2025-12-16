#include "aicontroller.h"
#include "random.h"

aiController::aiController()
{
}

Coordinate aiController::shoot(const GameBoard &board)
{
    int x,y;
    do{
        x = getRandom(0,9);
        y = getRandom(0,9);
    } while (board.alreadyShot(x,y));
    return {x,y};
}

