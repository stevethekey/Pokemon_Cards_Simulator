#include "player.h"

Player::Player()
{
    playerName = "John Doe";
    amountOfPlayerCards = 0;
    playerCash = 0;
}

void Player::SetplayerName(string inputName)
{
    playerName = inputName;
}

void Player::SetnumOfplayerCards(int pCards)
{
    amountOfPlayerCards = pCards;
}
void Player::SetplayerCash(long int pCash)
{
    playerCash = pCash;
}
    
string Player::GetplayerName() const
{
    return playerName;
}
int Player::GetnumOfplayerCards() const
{
    return amountOfPlayerCards;
}
int Player::GetplayerCash() const
{
    return playerCash; 
}

