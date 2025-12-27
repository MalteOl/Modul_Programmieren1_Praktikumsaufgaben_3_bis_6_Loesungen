#include "battleship.h"

//Battleship ist die „Hauptklasse“ des Spiels und verwaltet
//zwei PlayerObjekte sowie die jeweils dazugehörigen GameBoardObjekte.

Battleship::Battleship(const string &player1Name, const string &player2Name)
    :m_players{Player(player1Name),Player(player2Name)}
{

}

void Battleship::play()
{
    //  creating new GameBoard objects and storing them in m_boards, overwriting
    // the old boards which may be there already
    m_boards[0] = GameBoard();
    m_boards[1] = GameBoard();

    bool b_player = false;
    int i_active_player = 0;
    int i_inactive_player = 1;

    while (!m_boards[0].allShipsSunk() && !m_boards[1].allShipsSunk()) {

        // active first player player1Name always gets to start

        if (b_player)
        {
            i_active_player = 1;
            i_inactive_player = 0;
        }
        else
        {
            i_active_player = 0;
            i_inactive_player = 1;
        }

        cout << "Now is the turn of " << m_players[i_active_player].getName() << ": " << endl;

        // Print both the game board and the 'cheat sheet' for the active player
        m_boards[i_active_player].printBoard();
        m_boards[i_active_player].printEnemyBoard();

        // active first player is asked a location where to shoot at
        int x, y;

        if (i_active_player==0) {
            cout << "Bitte geben Sie nun die Koordinaten Ihren naechsten Schusses ein." << endl;
            cout << "Zeile (0-9)_Leerzeichen_ Spalte (0-9): ";

            cin >> x >> y;

            // Adjust to 0-based indexing
//            x--;
//            y--;

            // Validate input
            if(!(x >= 0 && x < 10 && y >= 0 && y < 10)) {
                cout << "Eingabe nicht im Feld. Bitte erneut eingeben" << endl;
                continue;
            }


        } else {
            cout << "Bitte geben Sie nun die Koordinaten Ihren naechsten Schusses ein." << endl;
            cout << "Zeile (0-9)_Leerzeichen_ Spalte (0-9): ";

            cin >> x >> y;

            // Adjust to 0-based indexing
//            x--;
//            y--;

            // Validate input
            if(!(x >= 0 && x < 10 && y >= 0 && y < 10)) {
                cout << "Eingabe nicht im Feld. Bitte erneut eingeben" << endl;
                continue;
            }



        }
        // Treffer
        bool b = m_boards[i_inactive_player].hit(x, y);
        // bool c = m_boards[i_inactive_player].hitCaptain(x, y);
        // deckt das Feld, das getroffen wurde, auf
        m_boards[i_active_player].mark(x, y, b);
        // m_boards[i_active_player].mark(x, y, c);
        // sorgt dafür, dass in dem Gegner-Spielfeld die beschossenen Koordinaten aufgedeckt werden
        m_boards[i_active_player].printEnemyBoard();
        // Spielwechsel
        b_player = !b_player;

    }

    cout << "\nThis game is over!\n";
    if (m_boards[0].allShipsSunk())
    {
        cout << "\nThe Player " << m_players[1].getName() << " has won!\n";
        m_players[0].addGameLost();
        m_players[1].addGameWon();
    }
    else
    {
        cout << "\nThe Player " << m_players[0].getName() << " has won!\n";
        m_players[1].addGameLost();
        m_players[0].addGameWon();
    }


}
