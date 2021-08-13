#include "packs.h"


PokePacks::PokePacks()
{             
    Generation1.ImportPokemon("Pokemon_Gen1.txt");
    GrassCards.ImportType(Generation1, "Grass");
    FireCards.ImportType(Generation1, "Fire");
    WaterCards.ImportType(Generation1, "Water");
    //BugCards.ImportType(Generation1, "Bug");
    //PoisonCards.ImportType(Generation1, "Poison");   
};

const Pokemon& PokePacks::OpenPack(char firstLetterofType)  //if you already know what are in the pack of cards, why are you looking at the last card
{
    if(firstLetterofType == 'G')
    {
        GrassCards.pullAPokemon(firstLetterofType);
    }

    else if (firstLetterofType == 'F')
    {
        FireCards.pullAPokemon(firstLetterofType);
    }

    else if(firstLetterofType=='W')
    {
        WaterCards.pullAPokemon(firstLetterofType);
    }
}

