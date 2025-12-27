#include "park.h"
#include <algorithm> // Für std::remove und std::erase
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::remove;
Park::Park()
{
    for (int i = 0; i < 4; i++) {
        herbivores.push_back(std::make_unique<Herbivore>("Brachiosaurus", 30000, 0.2, 0.2, 0.5));
    }
    for (int i = 0; i < 5; i++) {
        herbivores.push_back(std::make_unique<Herbivore>("Parasaurolophus", 1500, 0.4, 0.85, 0.75));
    }
    for (int i = 0; i < 2; i++) {
        carnivores.push_back(std::make_unique<Carnivore>("Tyrannosaurus Rex", 8000, 0.2, 0.08));
    }
    for (int i = 0; i < 4; i++) {
        carnivores.push_back(std::make_unique<Carnivore>("Raptor", 500, 0.3, 0.12));
    }
}

void Park::passingTime()
{
    for (auto &carnivore : carnivores) {
        carnivore->resetHuntingAttempt();
    }
    // Process herbivores: Age, check for death, then handle breeding
    auto h_it = herbivores.begin();
    while (h_it != herbivores.end()) {
        (*h_it)->age();
        if (!(*h_it)->isAlive()) {
            h_it = herbivores.erase(h_it); // Remove dead herbivores
        } else {
            ++h_it;
        }
    }
    std::vector<std::unique_ptr<Herbivore>> newHerbivores;
    for (auto &herbivore : herbivores) {
        if (herbivore->breed()) {
            if (herbivores.size() + carnivores.size() < 100) {
                newHerbivores.push_back(std::make_unique<Herbivore>(*herbivore));
            }
        }
    }
    /*
    for (auto &herbivore : herbivores) {
    if (herbivore->breed()) {
        // Check Art
        std::string species = herbivore->getSpecies();

        int count = (species == "Parasaurolophus") ? 3 : 1;

        for (int i = 0; i < count && (herbivores.size() + carnivores.size() + newHerbivores.size()) < 100; ++i) {
            newHerbivores.push_back(std::make_unique<Herbivore>(*herbivore));
        }
    }
}

     */
    for (auto &h : newHerbivores) {
        herbivores.push_back(std::move(h));
    }

    // Process carnivores: Age, check for death, then handle breeding
    auto c_it = carnivores.begin();
    while (c_it != carnivores.end()) {
        (*c_it)->age();
        if (!(*c_it)->isAlive()) {
            c_it = carnivores.erase(c_it); // Remove dead carnivores
        } else {
            ++c_it;
        }
    }

    std::vector<std::unique_ptr<Carnivore>> newCarnivores;
    for (auto &carnivore : carnivores) {
        if (carnivore->breed()) {
            if (herbivores.size() + carnivores.size() < 100) {
                newCarnivores.push_back(std::make_unique<Carnivore>(*carnivore));
            }
        }
    }
    for (auto &c : newCarnivores) {
        carnivores.push_back(std::move(c));
    }

    // Handle hunting
    for (auto &carnivore : carnivores) {
        if (!carnivore->isAlive())
            continue;

        // Find first eligible herbivore
        for (auto it = herbivores.begin(); it != herbivores.end();) {
            if (carnivore->hunt(**it)) {
                std::cout << carnivore->getSpecies() << " hat ein " << (*it)->getSpecies()
                << " erlegt." << std::endl;
                it = herbivores.erase(it);
                break; // Stop after successful hunt
            } else {
                ++it;
            }
        }

        carnivore->checkHuntStreak();
    }
    cout << "\nAktuelle Population:" << endl;
    cout << "Herbivoren: " << herbivores.size() << endl;
    cout << "Karnivoren: " << carnivores.size() << endl;
}
