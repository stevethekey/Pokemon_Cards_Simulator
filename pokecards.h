//storage and maintance code for the actual pokemon cards themselves. 
// let "dma" = dynamic memory allocated array

#include "pokemon.h" 
#include <fstream>
#include <cstdlib>
#include <ctime>

class PokeCards
{
    public:
    PokeCards();
    ~PokeCards();

    PokeCards& operator= (const PokeCards &rightObject);     /* i am overloading the "operator =". It will be reconfigured to a similiar sense of this
    equivalent scenario: int y = 10; int x = y. Reason| I usually do this out of habit when I create a class for testing purposes.*/

    //these functions below are for the packs class in the future

    bool ImportPokemon(const char* filename);          //reads a textfile to gather information and places stuff in the dma
    void ShowALLPokemon() const;                       //prints out only the pokemons' names
    int CountType(string nameOfType) const;            //will count the amount of pokemon with a specific type. 
    
    PokeCards& ImportType(const PokeCards &d,string nameOFtype);   
    /*returns altered information of the pokecard object that called this function. this "new" object is a collection of cards with the type based 
    on the second parameter. the first parameter is just the original PokeCards object after the importPokemon function happens 
    (the object with the original 151.) So, it reads the 151 original pokemon, then picks out the pokemon with the type specificed in the second 
    parameter, and finally creates a new pokeCards object with those cards */

    const Pokemon& pullAPokemon();                    // returns a pokemon from a PokeCard object (picks it from the object's dma)

    //this function below is for the player class in the future

    PokeCards& playerOpenpack(const Pokemon & pokemonCardpulledFrompack);   /*. this alters the PokeCards object that called this function. 
    This function will store whatever the function "pullAPokemon" spawns, and saves it in this object's dma.*/

    private:
    int currentSize, maxSize;
    Pokemon * allCards;                          //creates a pointer named "all cards", with type "Pokemon. this is to create a dynamic memory allocated array

    // the functions below are helper functions

    void Resize(int totalPoke);                  //helps resize dma as needed

    // the rest are still helper functions, with the idea of making the packs class run smooth
    const Pokemon& PullGrass();
    const Pokemon& PullFire();
    const Pokemon& PullWater();
};