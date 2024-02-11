//storage and maintance code for the actual pokemon cards themselves. 
// let "dma" = dynamic memory allocated array

#include "pokemon.h" 
#include <fstream>
#include <cstdlib>
#include <ctime>

class PokeCards
{
    public:
    PokeCards();                                       //creates DMA
    ~PokeCards();                                      //deletes stuff when i am done

    bool ImportPokemon(const char* filename);         //loads in og pokemon to the PokeCards object (!) that called it(! = this specific object= OG)
    int CountType(string nameOfType) const;           //will count the amount of pokemon of a desired type from the dma
    void ShowALLPokemon() const;                      //prints out only the pokemons' names from the dma
    bool SortandShowPokemonbyValue();                 //Sorts the cards based on values currently in a DMA, then display them in order


    PokeCards& ImportType(const PokeCards &d,string nameOFtype);   //this function will be used for the PokePacks class later
    /*
    This function turns the PokeCard object that called it into a specifc pokemon-type pack of cards. 
    It loads in the OG object in the first parameter, then picks cards out of it based on the desired type from the second parameter.
    */


    const Pokemon& pullAPokemon(char whichHelper);        //this is the open a pack function
    /*
    It will refer to specific helper functions, found below under private, to correctly open a pack of desired pokemon cards
    */

   PokeCards& saveCardPulled(const Pokemon & pokemonCardpulledFrompack);  // this stores a card from a parameter into the calling object's dma
    /* 
    Specifically, the card that will be passed in this function is the card that will be pulled from the pullAPokemon funciton. 
    */

    private:
    int currentSize, maxSize;
    Pokemon * allCards;                          //creates a pointer named "all cards", with type Pokemon. this is to create a dynamic memory allocated array

    void Resize(int totalPoke);                  //helps resize dma as needed

    //these functions are helpers in the pack function. they all have their own odds and indivual hierarchy based on the type of pokemon cards
    const Pokemon& PullGrass();
    const Pokemon& PullFire();
    const Pokemon& PullWater();

    
    //potential extra stuff / other 
    PokeCards& operator= (const PokeCards &rightObject);     
    /* i am overloading the "operator =". It will be reconfigured to a similiar sense of this
    equivalent scenario: int y = 10; int x = y. Reason| I usually do this out of habit when I create a class for testing purposes.*/
};