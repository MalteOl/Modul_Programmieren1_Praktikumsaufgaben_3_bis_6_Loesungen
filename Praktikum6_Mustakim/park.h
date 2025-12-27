#ifndef PARK_H
#define PARK_H
#include "carnivore.h"
#include "herbivore.h"
#include <memory>
#include <vector>

class Park //max 100 animals alive
{
public:
    Park();

    void passingTime();

private:
    std::vector<std::unique_ptr<Herbivore>> herbivores;
    std::vector<std::unique_ptr<Carnivore>> carnivores;
};

#endif // PARK_H
