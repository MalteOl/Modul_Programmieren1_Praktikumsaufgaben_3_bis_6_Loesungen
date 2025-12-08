#include "ship.h"
#include <stdexcept>


Ship::Ship() = default;


Ship::Ship(int row, int col, int lengthOfShip, Direction direction) {

    m_parts.push_back(Part(row, col));


    for (int i = 1; i < lengthOfShip; i++) {
        switch (direction) {
        case Direction::north: row--; break;
        case Direction::east:  col++; break;
        case Direction::south: row++; break;
        case Direction::west:  col--; break;
        }
        m_parts.push_back(Part(row, col));
    }
}

bool Ship::hasPartIn(int row, int col) {
    for (Part& part : m_parts) {
        if (part.getRow() == row && part.getCol() == col) {
            return true;
        }
    }
    return false;
}

Part& Ship::getPartIn(int row, int col) {
    for (Part& part : m_parts) {
        if (part.getRow() == row && part.getCol() == col) {
            return part;
        }
    }
    throw std::invalid_argument("No ship part at position");
}

bool Ship::isDamaged() {
    for (Part& part : m_parts) {
        if (part.isDamaged()) {
            return true;
        }
    }
    return false;
}

bool Ship::isSunk() {
    for (Part& part : m_parts) {
        if (!part.isDamaged()) {
            return false;
        }
    }
    return true;
}
