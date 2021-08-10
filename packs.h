#include "pokecards.h"

class PokePacks   //purpose of this class is to simplify everything. all the menu.cpp functions we have been testing will be utilized here

{
    public:
    PokePacks();

    
    const Pokemon& OpenPack(char firstLetterofType); //returns a Pokemon card


    private:

    PokeCards Generation1;      //creates the PokeCards object that will hold all the pokemon and their information from the text-file (all 151 pokemon!)

    PokeCards FireCards;        //creates objects with type PokeCards in accordance to a specific type of Pokemon
    PokeCards WaterCards;
    PokeCards GrassCards;  
    PokeCards BugCards;
    PokeCards PoisonCards;
};




