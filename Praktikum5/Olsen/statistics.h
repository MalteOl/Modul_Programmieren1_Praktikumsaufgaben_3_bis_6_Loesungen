#ifndef STATISTICS_H
#define STATISTICS_H


class Statistics
{
public:
    Statistics();
    static void addHitCounter();
    static void addMissCounter();
    int getHitCounter();
    int getMissCounter();
    int getShootCounter();

private:
    // Hit PART of the Ship
    int hitCounter;
    // Hit the water
    int missCounter;
    // Total hits -> hitCounter + missCounter
    int shootCounter;
};


#endif // STATISTICS_H
