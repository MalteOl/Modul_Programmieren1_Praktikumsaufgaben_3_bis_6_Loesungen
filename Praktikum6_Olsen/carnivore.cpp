#include "carnivore.h"

Carnivore::Carnivore(const string &race, double currentWeigth, int maxWeight,
                     double growthRate, double breadingChance, double hidingChance) :
    Dinosaur(race, currentWeigth, maxWeight, growthRate, breadingChance, hidingChance)
{
}

Carnivore::~Carnivore()
{

}

bool Carnivore::getFed() const
{
    return m_fed;

}

void Carnivore::setFed(bool fedValue)
{
    m_fed = fedValue;

}

bool Carnivore::hunt(Herbivore herbivore)
{
    // Carnivore wiegt mehr als Herbivore?
    if(getCurrentWeigth() >= herbivore.getCurrentWeigth()){
        return true;
    }

    if(!herbivore.hide())
    {
        if(life != 2)
        {
            life++;
        }
        cout << "here";
        return true;
    }
    else
    {
        life--;
        return false;
    }
}
