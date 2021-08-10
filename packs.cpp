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

const Pokemon& PokePacks::OpenPack(char firstLetterofType)
{
    if(firstLetterofType == 'G')
    {
        GrassCards.pullAPokemon();
    }

    else if (firstLetterofType == 'F')
    {
        FireCards.pullAPokemon();
    }

    else if(firstLetterofType=='W')
    {
        WaterCards.pullAPokemon();
    }
}

