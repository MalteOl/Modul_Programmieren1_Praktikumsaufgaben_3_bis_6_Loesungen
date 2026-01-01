#include "dinosaur.h"
#include "random.h"

Dinosaur::Dinosaur(string race, double initialWeight, int maxWeight, double growthRate, double breadingChance, double hidingChance):
    m_race(race),
    m_initialWeight(initialWeight),
    m_maxWeight(maxWeight),
    m_growthRate(growthRate),
    m_breadingChance(breadingChance),
    m_hidingChance(hidingChance)
{}

bool Dinosaur::age()
{

}

bool Dinosaur::bread()
{

}
