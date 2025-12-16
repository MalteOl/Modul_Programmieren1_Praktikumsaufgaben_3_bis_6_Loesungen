#ifndef STATISTICS_H
#define STATISTICS_H


class Statistics
{
public:
    Statistics();
    static void addHitCounter();
    static void addMissCounter();
    static int getHitCounter();
    static int getMissCounter();
    static int getShootCounter();

//    void getScore();
private:
    // Hit PART of the Ship
    static int hitCounter;
    // Hit the water
    static int missCounter;
    // Total hits -> hitCounter + missCounter
    static int shootCounter;
};


#endif // STATISTICS_H
