#include "player.h"

// Player stellt eine Spielerin dar und speichert den Namen sowie
// jeweils die Anzahl der gewonnenen und verlorenen Spiele.

Player::Player(const string &playerName): m_gamesLost(0),m_gamesWon(0),m_playerName(playerName),m_hitCounter(0),m_missCounter(0)
{

}

int Player::getGamesWon() const
{
    return m_gamesWon;
}

int Player::getGamesLost() const
{
    return m_gamesLost;
}

/**
 * @brief Get games played.
 * @return The total number of games this player has played.
 *
 * \see getGamesWon
 * \see getGamesLost
 */
// The total number of games this player has played.
int Player::getGamesPlayed() const
{
    return m_gamesLost+m_gamesWon;
}

int Player::getHitCounter() const
{
    return m_hitCounter;
}

int Player::getMissCounter() const
{
    return m_missCounter;
}

int Player::getShootCounter() const
{
    return m_hitCounter + m_missCounter;
}

void Player::addGameWon()
{
    m_gamesWon++;
}


void Player::addGameLost()
{
    m_gamesLost++;
}

string Player::getName()
{
    return m_playerName;
}

void Player::addHit()
{
    m_hitCounter++;
}

void Player::addMiss()
{
    m_missCounter++;
}
