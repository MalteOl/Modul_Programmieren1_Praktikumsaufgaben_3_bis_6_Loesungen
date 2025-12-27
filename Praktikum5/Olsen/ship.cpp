#include "ship.h"
#include "random.h"


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

    if (!((2 <= lengthOfShip) &&  (lengthOfShip <= 5)))
        throw std::invalid_argument("Schiffe mit mindestens 2 und maximal "
                                    "5 Teilen");

//    int placeCaptain = getRandom(0,lengthOfShip - 1);

    for (int i = 0; i < lengthOfShip; i++) {
        if (direction == Direction::north) {
            m_parts.push_back(Part(row-i,col));
            // falls noch kein Captain gesetzt nun an einer random Stelle setzen
            if (i == m_parts[i].getCaptain()) {
//                placeCaptain;
                m_parts.push_back(Part(row-i,col/*,captain*/));
            }
        } else if (direction == Direction::east) {
            m_parts.push_back(Part(row, col + i));
//            m_parts.at(i).setIsCaptain(true);
        } else if (direction == Direction::south) {
            m_parts.push_back(Part(row + i, col));
//            m_parts.at(i).setIsCaptain(true);
        } else if (direction == Direction::west) {
            m_parts.push_back(Part(row, col - i));
//            m_parts.at(i).setIsCaptain(true);
        } else {
            throw std::invalid_argument("Deine Koordinaten führen ins Nichts");
        }
    }
}

bool Ship::hasPartIn(int row, int col)
{
    // for (const Part &part : m_parts)
    // {
    //     if (part.getRow() == row && part.getCol() == col)
    //         return true;
    // }
    // return false;

    for (size_t i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].getRow() == row && m_parts[i].getCol() == col) {
            return true;
        }
    }
    return false;
}

Part &Ship::getPartIn(int row, int col)
{
    // for (Part &part : m_parts)
    // {
    //     if (part.getRow() == row && part.getCol() == col)
    //         return part;
    // }
    // throw std::out_of_range("No part at given coordinates");

    for (size_t i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].getRow() == row && m_parts[i].getCol() == col) {
            return m_parts[i];
        }
    }
    throw std::invalid_argument("Es gibt keine Teile an diesen Koordinaten");
}

//Part Ship::isCaptain(int row, int col)
//{
//    for (size_t i = 0; i < m_parts.size(); i++) {
//        if (m_parts[i].getRow() != row && m_parts[i].getCol() != col) {
//            return true;
//        }
//    }
//    throw std::invalid_argument("Es gibt keinen Captain an diesen Koordinaten");

//}

// • beschädigt, wenn mindestens ein (aber nicht alle!) Schiffsteil
//   beschädigt ist,
bool Ship::isDamaged()
{
    // for (const Part &part : m_parts)
    // {
    //     if (part.isDamaged())
    //         return true;
    // }
    // return false;

    for (size_t i = 0; i < m_parts.size(); i++) {
        if (m_parts[i].isDamaged()) {
            return true;
        }
    }
    return false;
}


// • oder aber versenkt, wenn alle Schiffsteile beschädigt sind
bool Ship::isSunk()
{
    // for (const Part &part : m_parts)
    // {
    //     if (!part.isDamaged())
    //         return false;
    // }
    // return true;

    for (size_t i = 0; i < m_parts.size(); i++) {
        if (!(m_parts[i].isDamaged())) {
            return false;
        }
        if (m_parts[i].isCaptain()) {
            return true;
            break;
        }
    }
    return true;
}
