#include "dinosaur.h"
#include "random.h"

Dinosaur::Dinosaur(string race, int initialWeight, int maxWeight, double growthRate, double breadingChance):
    m_race(race),
    m_initialWeight(initialWeight),
    m_maxWeight(maxWeight),
    m_growthRate(growthRate),
    m_breadingChance(breadingChance)
{}

bool Dinosaur::age()
{

}

bool Dinosaur::bread()
{

}
