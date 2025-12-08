#include "board.h"
#include <iostream>
#include <iomanip>
#include <random>

Tile field[ROWS][COLS];

namespace
{
std::size_t countAdjacentMines(std::size_t r, std::size_t c)
{

    std::size_t count = 0;
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc) {
            if (!dr && !dc) continue;
            std::size_t nr = r + dr, nc = c + dc;
            if (nr < ROWS && nc < COLS &&
                field[nr][nc].state == Allocation::Mine)
                ++count;
        }
    return count;
}
}
void initialize(std::size_t mineCount) {
    for (auto &row : field)
        for (auto &t : row) {
            t.state = Allocation::Hidden;
            t.nachbarminen = 0;
            t.hasExtraLife = false;
        }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> distR(0, ROWS - 1);
    std::uniform_int_distribution<std::size_t> distC(0, COLS - 1);

    std::size_t placed = 0;
    while (placed < mineCount)
    {
        std::size_t r = distR(gen), c = distC(gen);
        if (field[r][c].state != Allocation::Mine)
        {
            field[r][c].state = Allocation::Mine;
            ++placed;
        }
    }

    //Extraleben setzen
    std::size_t livesPlaced = 0;
    while (livesPlaced < 3)
    {
        std::size_t r = distR(gen), c = distC(gen);
        if (!field[r][c].hasExtraLife)
        {
            field[r][c].hasExtraLife = true;
            ++livesPlaced;
        }
    }

    for (std::size_t r = 0; r < ROWS; ++r)
    {
        for (std::size_t c = 0; c < COLS; ++c)
        {
            if (field[r][c].state != Allocation::Mine)
            {
                field[r][c].nachbarminen = countAdjacentMines(r, c);
            }
        }
    }
}

void display(bool debug) {
    std::cout << "   ";
    for (std::size_t c = 0; c < COLS; ++c)
    {
        std::cout << std::setw(2) << (c + 1);
    }
    std::cout << '\n';

    for (std::size_t r = 0; r < ROWS; ++r)
    {
        std::cout << std::setw(2) << (r + 1) << "|";
        for (std::size_t c = 0; c < COLS; ++c)
        {
            const Tile &t = field[r][c];
            char symbol = '*';
            if (t.state == Allocation::Revealed)
            {
                symbol = t.nachbarminen ? char('0' + t.nachbarminen) : '.';
            }
            else if (debug && t.state == Allocation::Mine)
            {
                symbol = 'X';
            }
            std::cout << ' ' << symbol;
        }
        std::cout << '\n';
    }
}


bool playerMove(std::size_t &remaining, std::size_t &extraLives)
{
    std::size_t r, c;
    std::cout << "\nBitte geben Sie Zeile (1-" << ROWS << ") und Spalte (1-" << COLS << ") ein: ";
    if (!(std::cin >> r >> c) || r == 0 || r > ROWS || c == 0 || c > COLS)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Ungültige Eingabe!\n";
        return true;
    }

    --r; --c;
    Tile &t = field[r][c];

    if (t.state == Allocation::Revealed)
    {
        std::cout << "Dieses Feld wurde bereits aufgedeckt.\n";
        return true;
    }

    //inkrement
    if (t.hasExtraLife)
    {
        extraLives++;
        std::cout << "\n*** Extraleben gefunden! Jetzt haben Sie " << extraLives << " Extraleben. ***\n";

    }
    std::cout << "Du hast noch " << extraLives << " Extraleben \n";
    if (t.state == Allocation::Mine)
    {
        std::cout << "Test:   " << extraLives << "\n";
        if (extraLives > 0)
        {
            --extraLives;
            std::cout << "\n*** Mine getroffen, aber ein Extraleben wurde verwendet! Verbleibende Extraleben: " << extraLives << "\n";
            t.state = Allocation::Revealed;
            return true;
        }
        else
        {
            for (std::size_t i = 0; i < ROWS; ++i)
                for (std::size_t j = 0; j < COLS; ++j)
                    if (field[i][j].hasExtraLife)
                    {
                        field[i][j].state = Allocation::Revealed;
                    }

            display(true);
            std::cout << "\n**** BOOOOM ****\nKeine Extraleben mehr übrig.\n";
            return false;
        }
    }

    t.state = Allocation::Revealed;

    --remaining;
    while (checkNeighbours(remaining)) {}
    return true;
}






bool revealedEmptyNeighbour(std::size_t r, std::size_t c) {
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc) {
            if (!dr && !dc) continue;
            std::size_t nr = r + dr, nc = c + dc;
            if (nr < ROWS && nc < COLS) {
                const Tile &n = field[nr][nc];
                if (n.state == Allocation::Revealed && n.nachbarminen == 0)
                {
                    return true;
                }
            }
        }
    return false;
}

bool checkNeighbours(std::size_t &remaining) {
    bool changed = false;
    for (std::size_t r = 0; r < ROWS; ++r)
        for (std::size_t c = 0; c < COLS; ++c) {
            Tile &t = field[r][c];
            if (t.state == Allocation::Hidden &&
                revealedEmptyNeighbour(r, c)) {
                t.state = Allocation::Revealed;
                --remaining;
                changed = true;
            }
        }
    return changed;
}

