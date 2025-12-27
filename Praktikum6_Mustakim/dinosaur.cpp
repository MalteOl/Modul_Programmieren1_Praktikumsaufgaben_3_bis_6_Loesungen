#include "dinosaur.h"
#include <iostream>

using std::cout;
using std::endl;
using std::rand;
using std::string;

Dinosaur::Dinosaur(double maxWeight,
                   double growthRate,
                   double breedChance,
                   string race,
                   double initialWeightFactor)
    : maxWeight(maxWeight)
    , growthRate(growthRate)
    , breedChance(breedChance)
    , alive(true)
    , race(race)
{
    curWeight = maxWeight * initialWeightFactor;
}

Dinosaur *Dinosaur::reproduce()
{
    if (breed()) {
        return new Dinosaur(maxWeight,
                            growthRate,
                            breedChance,
                            race,
                            0.05); // Fortpflanzung mit neuem Dino
    }
    return nullptr; // Keine Fortpflanzung ,
}

void Dinosaur::age()
{
    if (!alive)
        return; // Wenn tot, keine akt.

    // Alterung des dino, wächst mit der Wachstumsrate bis zum maximalgewicht
    if (curWeight < maxWeight) {
        curWeight += curWeight * growthRate; // Wachstumsfaktor wird angewendet
        if (curWeight > maxWeight) {
            curWeight = maxWeight; // Sicherstellen, dass das maximalgewicht nicht überschritten wird
        }
    } else {
        // Wenn das Maximalgewicht erreicht ist, überprüfen, ob der Dino stirbt
        if ((rand() % 100) < (growthRate * 100)) { // Zufall für Altersschwäche
            alive = false;                         // Dino stirbt an Altersschwäche
            cout << race << " starb an Altersschwäche." << endl;
        }
    }
}

bool Dinosaur::breed()
{
    if (!alive)
        return false; // Nur lebende Dinos können sich fortpflanzen

    // Fortpflanzungswahrscheinlichkeit
    return (std::rand() % 100) < (breedChance * 100);
}

bool Dinosaur::isAlive()
{
    return alive; // Überprüfen, ob der Dino noch lebt
}

void Dinosaur::printStatus()
{
    cout << "Art: " << race << ", Gewicht: " << curWeight << "/" << maxWeight
         << ", Lebendig: " << (alive ? "Ja" : "Nein") << endl;
}

double Dinosaur::getWeight()
{
    return curWeight; // Gibt das aktuelle Gewicht des Dinos zurück
}

std::string Dinosaur::getSpecies()
{
    return race; // Gibt die Art des Dinosauriers zurück (z. B. "Tyrannosaurus Rex")
}
