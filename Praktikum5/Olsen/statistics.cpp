#include "statistics.h"

//int Statistics::hitCounter = 0;
//int Statistics::missCounter = 0;
//int Statistics::shootCounter = hitCounter + missCounter;

Statistics::Statistics(): hitCounter(0),missCounter(0),shootCounter(hitCounter + missCounter)
{
//     shootCounter = 0;
//     missCounter = 0;
//     shootCounter = hitCounter + missCounter;
}

void Statistics::addHitCounter()
{
    hitCounter++;
    shootCounter++;
}

void Statistics::addMissCounter()
{
    missCounter++;
    shootCounter++;
}

int Statistics::getHitCounter()
{
    return hitCounter;
}

int Statistics::getMissCounter()
{
    return missCounter;
}

int Statistics::getShootCounter()
{
    return shootCounter;
}
