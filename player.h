#include "pokecards.h"

class Player
{
    public: 

    Player();

    void SetplayerName(string inputName);
    void SetnumOfplayerCards(int pCards);
    void SetplayerCash(long int pCash);
        
    string GetplayerName() const;
    int GetnumOfplayerCards() const;
    int GetplayerCash() const;


    private:
    string playerName;
    int amountOfPlayerCards;
    long int playerCash;
};



