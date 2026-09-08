#include "carnivore.h"
#include "herbivore.h"

Carnivore::Carnivore(const string &race, double currentWeigth, int maxWeight,
                     double growthRate, double breadingChance, double hidingChance) :
    Dinosaur(race, currentWeigth, maxWeight, growthRate, breadingChance, hidingChance)
{
}

Carnivore::~Carnivore()
{

}

bool Carnivore::hunt(Herbivore &herbivore)
{
    // Carnivore wiegt mehr als Herbivore?
    if(getCurrentWeigth() <= herbivore.getCurrentWeigth()){
        return false;
    }

    // Herbivore hat es nicht geschafft, sich rechtzeitig zu verstecken
    if(!herbivore.hide()){
        return true;
    }
    // Falls beides ja, darf Carnivore Herbivore jagen
    return false;
}

bool Carnivore::getFed() const
{
    return m_fed;

}

void Carnivore::setFed(bool fedValue)
{
    m_fed = fedValue;

}

