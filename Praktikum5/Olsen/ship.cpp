#include "ship.h"


// Ship stellt ein Schiff dar, welches eben aus verschieden vielen Teilen
// und damit aus Objekten von Part besteht.
// Das Schiff als solches ist entweder:
// • unbeschädigt, wenn alle Schiffsteile unbeschädigt sind,

    // Should do nothing. This is just needed in order for the std::array
    // in GameBoard to work.
    Ship::Ship(){}

vector<Part> m_parts;

// Der Konstruktor Ship(int row, int col, int lengthOfShip,
// Direction direction) wird verwendet, um ein neues Schiff zu erstellen.
Ship::Ship(int row, int col, int lengthOfShip, Direction direction)
{

}

bool Ship::hasPartIn(int row, int col)
{
    bool result = false;

    for (int i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;

}

Part &Ship::getPartIn(int row, int col)
{

}

// • beschädigt, wenn mindestens ein (aber nicht alle!) Schiffsteil
//   beschädigt ist,
bool Ship::isDamaged()
{
    bool result = false;
    for (int i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].isDamaged()) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;

}

// • oder aber versenkt, wenn alle Schiffsteile beschädigt sind
bool Ship::isSunk()
{
    bool result = false;
    for (int i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].isDamaged()) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

