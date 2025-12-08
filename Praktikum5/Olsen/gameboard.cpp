#include "gameboard.h"
#include <iomanip>
#include "random.h"



// GameBoard verfügt über ein std::array mit den Schiffen eines Spielers
// sowie dem „Schmierzettel“ zur Markierung welches gegenerische Feld
// bereits beschossen wurde. Die Klasse ist ebenfalls zuständig für die
// Ausgabe des Spielfelds bzw. des „Schmierzettels“.

// This shall initialize the enemy board (attribute m_enemyBoard) with dot characters '.'.
// The player's ships can either be placed here also, or later by calling randomPlaceShips.
GameBoard::GameBoard() {
    for (auto &row : m_enemyBoard)
        row.fill('.');
    for (auto &row : m_board)
        row.fill('.');

    randomPlaceShips();
}

void GameBoard::printBoard()
{
    cout << endl << "Dein Spielfeld" << endl;
    // Spielfeld ausgeben
    for (size_t r = 0; r < m_board.size(); r++) {
        // Zeilennummer ausgeben
        cout << std::setw(2) << r << "|";
        for (size_t c = 0; c < m_board.size(); c++) {
            cout << m_board[r][c] << " ";
        }
        cout << endl;

    }
    // Spaltennummer ausgeben
    cout << "----------------------" << endl;
    cout << "  ";
    for (int c = 0; c < m_board.size(); c++) {
        cout << std::setw(2) << c;
    }
    cout << endl << endl;
}
void GameBoard::printEnemyBoard()
{
    // Spielfeld ausgeben
    cout << "Spielfeld des Gegners" << endl;
    for (size_t r = 0; r < m_enemyBoard.size(); r++) {
        cout << std::setw(2) << r << "|";
        cout << ". ";
        for (size_t c = 0; c < m_enemyBoard.size()-1; c++){
            cout << m_enemyBoard[r][c] << " ";
        }
        cout << endl;

    }
    // Spaltennummer ausgeben
    cout << "----------------------" << endl;
    cout << "  ";
    for (int c = 0; c < m_enemyBoard.size(); c++) {
        cout << std::setw(2) << c;
    }
    cout << endl << endl;

}


bool GameBoard::hit(int row, int col)
{
    int counter = 0;
    for (Ship &ship : m_ships)
    {
        if (ship.hasPartIn(row, col))
        {
            Part &part = ship.getPartIn(row, col);
            //
            if (!part.isDamaged())
            {
                part.setDamaged();
                cout << "BOOM!\n\n";
                if (ship.isSunk())
                {
                    cout << "Ship" << counter << " of your enemy is sunk!\n";
                }
                return true;
            }
        }
        counter++;
    }
    cout << "MISS!\n\n";
    return false;
}

void GameBoard::mark(int row, int col, bool wasHit)
{
    m_enemyBoard[row][col] = wasHit ? 'X' : 'O';

}

void GameBoard::randomPlaceShips()
{
    int shipsPlaced = 0;
    // Schlachtschiff aus 5 Teilen

    // Original placement pattern extended to include 4 submarines (len=2)
    for (size_t i = 0; i < 5; i++)
    {
        int length = 6 - i; // length of the ship
        for (int j = 0; j < i; ++j)
        {
            int row, col, direction;
            do
            {
                row = getRandom(0, 9);
                col = getRandom(0, 9);
                direction = getRandom(0, 3);
                // check on overlap of battle field:
                bool overlap = false;
                switch (direction)
                {
                case 0:
                    // north
                    if ((row - length + 1) < 0)
                        overlap = true;
                    break;
                case 1:
                    // east
                    if ((col + length - 1) > 9)
                        overlap = true;
                    break;
                case 2:
                    // south
                    if ((row + length - 1) > 9)
                        overlap = true;
                    break;
                case 3:
                    // west
                    if ((col - length + 1) < 0)
                        overlap = true;
                    break;
                }

                for (Ship &ship : m_ships)
                {
                    for (int i = 0; i < length; ++i)
                    {
                        switch (direction)
                        {
                        case 0:
                            // north
                            if (ship.hasPartIn(row - i, col))
                                overlap = true;
                            break;
                        case 1:
                            // east
                            if (ship.hasPartIn(row, col + i))
                                overlap = true;
                            break;
                        case 2:
                            // south
                            if (ship.hasPartIn(row + i, col))
                                overlap = true;
                            break;
                        case 3:
                            // west
                            if (ship.hasPartIn(row, col - i))
                                overlap = true;
                            break;
                        }
                    }
                }

                if (!overlap)
                    break;

            } while (true);

            switch (direction)
            {
            case 0:
                m_ships[shipsPlaced] = Ship(row, col, length, Direction::north);
                for (int i = 0; i < length; ++i)
                    m_board[row - i][col] = '0' + shipsPlaced;
                break;
            case 1:
                m_ships[shipsPlaced] = Ship(row, col, length, Direction::east);
                for (int i = 0; i < length; ++i)
                    m_board[row][col + i] = '0' + shipsPlaced;
                break;
            case 2:
                m_ships[shipsPlaced] = Ship(row, col, length, Direction::south);
                for (int i = 0; i < length; ++i)
                    m_board[row + i][col] = '0' + shipsPlaced;
                break;
            case 3:
                m_ships[shipsPlaced] = Ship(row, col, length, Direction::west);
                for (int i = 0; i < length; ++i)
                    m_board[row][col - i] = '0' + shipsPlaced;
                break;
            default:
                break;
            }

            ++shipsPlaced;
        }

    }
}

bool GameBoard::allShipsSunk()
{
    for (Ship &ship : m_ships)
    {
        if (!ship.isSunk())
            return false;
    }
    return true;
}

