#include "ship.h"
#include <iostream>
using std::cout;

// Ship stellt ein Schiff dar, welches eben aus verschieden vielen Teilen
// und damit aus Objekten von Part besteht.
// Das Schiff als solches ist entweder:
// • unbeschädigt, wenn alle Schiffsteile unbeschädigt sind,

    // Should do nothing. This is just needed in order for the std::array
    // in GameBoard to work.
    Ship::Ship() : m_parts() {}

vector<Part> m_parts;

// Der Konstruktor Ship(int row, int col, int lengthOfShip,
// Direction direction) wird verwendet, um ein neues Schiff zu erstellen.

Ship::Ship(int row, int col, int lengthOfShip, Direction direction)
{

    if (!(2 <= lengthOfShip && lengthOfShip <= 5)) {
        throw std::invalid_argument("Schiffe mit mindestens 2 und maximal 5 Teilen");
    }

    // für jede Koordinate Teile anlegen
    for(int i = 0; i <= lengthOfShip - 1;i++) {
        // Direction 4 Richtungen
        switch (direction) {
        case Direction::north:
            m_parts.push_back(Part(row - i, col));
            break;
        case Direction::east:
            m_parts.push_back(Part(row, col + i));
            break;
        case Direction::south:
            m_parts.push_back(Part(row + i, col));
            break;
        case Direction::west:
            m_parts.push_back(Part(row, col - i));
            break;
        default:
            cout << "Der Fehler im 2.Constructor der Klasse 'Ship'";
        }

    }
}

bool Ship::hasPartIn(int row, int col)
{
    for (const Part &part : m_parts)
    {
        if (part.getRow() == row && part.getCol() == col)
            return true;
    }
    return false;
}

Part &Ship::getPartIn(int row, int col)
{
    for (Part &part : m_parts)
    {
        if (part.getRow() == row && part.getCol() == col)
            return part;
    }
    throw std::out_of_range("No part at given coordinates");
}

// • beschädigt, wenn mindestens ein (aber nicht alle!) Schiffsteil
//   beschädigt ist,
bool Ship::isDamaged()
{
    for (const Part &part : m_parts)
    {
        if (part.isDamaged())
            return true;
    }
    return false;

}

// • oder aber versenkt, wenn alle Schiffsteile beschädigt sind
bool Ship::isSunk()
{
    for (const Part &part : m_parts)
    {
        if (!part.isDamaged())
            return false;
    }
    return true;
}

