#include "part.h"

// Part stellt ein Schiffsteil dar, welches genau ein Feld belegt.
// Ein Schiff besteht damit aus zwei bis fünf Objekten von Part.
// Ein Schiffsteil kann entweder unbeschädigt oder beschädigt sein
// (Wenn es getroffen wurde).


// Der (einzige) Konstruktor von Part soll ein unbeschädigtes Schiffsteil
// an der in den Parametern übergebenen Position erstellen.

Part::Part(int row, int col)
{
    m_status = 0;
}

// Für den Status existiert der Getter isDamaged, welcher true liefert
// falls dieses Teil beschädigt ist

bool Part::isDamaged() const
{
    return m_status==1;
}

// ebenfalls für den Status existiert der Setter setDamaged, welcher
// den Status auf „beschädigt“ setzt

void Part::setDamaged()
{
    m_status = 1;
}

// Für die Position existieren jeweils die beiden Getter-Methoden
// getRow bzw. getCol.

int Part::getRow() const
{
    return m_row;
}

int Part::getCol() const
{
    return m_col;
}
