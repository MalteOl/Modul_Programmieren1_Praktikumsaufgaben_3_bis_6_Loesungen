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

int Dinosaur::isAlive()
{
    return life;

}

void Dinosaur::setCurrentWeigth(double newCurrentWeigth)
{
    m_currentWeigth = newCurrentWeigth;
}

double Dinosaur::getHidingChance() const
{
    return m_hidingChance;
}

double Dinosaur::getBreedingChance() const
{
    return m_breedingChance;
}

double Dinosaur::getGrowthRate() const
{
    return m_growthRate;
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
    setCurrentWeigth(m_currentWeigth + m_currentWeigth * (1 + m_growthRate));

// Sobald Bedingung true, dass Maximalgewicht erreicht oder irgendeine Zufallsprozentzahl
// größergleich die vorhergehende Wachstumsrate, stirbt der Dino
    if (m_currentWeigth < m_maxWeight || getRandom(0,99) / 100 < m_breedingChance) {
        return false;
    }
    return true;
}

bool Dinosaur::breed()
{
// ist die Vermehrrate größer als eine random Prozentzahl
    return (getRandom(0,99) / 100) < m_breedingChance;

}

bool Dinosaur::diesOfAge()
{
    if(m_currentWeigth != m_maxWeight)
    {
        return false;
    }

    const int chance = std::rand() / 100;

    return chance <= m_growthRate;
}
