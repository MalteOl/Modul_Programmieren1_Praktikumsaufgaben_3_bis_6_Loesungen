#include "dinosaur.h"
#include "random.h"

int Dinosaur::getRandom(int lower, int upper)
{
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

double Dinosaur::currentWeigth() const
{
    return m_currentWeigth;
}

Dinosaur::Dinosaur(string race, double currentWeigth, int maxWeight,
                   double growthRate, double breedingChance, double hidingChance):
    m_race(race),
    m_currentWeigth(currentWeigth),
    m_maxWeight(maxWeight),
    m_growthRate(growthRate),
    m_breedingChance(breedingChance),
    m_hidingChance(hidingChance)
{}

bool Dinosaur::age()
{
// Sobald Maximalgewicht erreicht, stirbt der Dino
    if (m_currentWeigth < m_maxWeight) {
        m_currentWeigth += m_currentWeigth * (1 + m_growthRate);
    } else {
//        delete herbivore;
    }
}

bool Dinosaur::breed()
{

}
