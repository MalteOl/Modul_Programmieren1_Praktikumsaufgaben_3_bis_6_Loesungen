#include "dinosaur.h"
#include "random.h"

int Dinosaur::getRandom(int lower, int upper)
{
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

double Dinosaur::getCurrentWeigth() const
{
    return m_currentWeigth;
}

string Dinosaur::getRace() const
{
    return m_race;
}

int Dinosaur::getMaxWeight() const
{
    return m_maxWeight;
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
//    m_currentWeigth += m_currentWeigth * (1 + m_growthRate);
    m_currentWeigth += m_currentWeigth * m_growthRate;

// Sobald Maximalgewicht erreicht oder irgendeine Zufallszahl größer ist als die
// vorhergehende Wachstumsrate, stirbt der Dino
    if (m_currentWeigth > m_maxWeight || getRandom(0,100) % 100 > m_breedingChance) {
        return false;
    }
    return true;
}

bool Dinosaur::breed()
{
    // eine zufällige Prozentzahl zwischen 0 und 100 wird verglichen mit der Vermehrungsrate
    return getRandom(0,100) % 100 < m_breedingChance;

}
