#include <string>
#include <iostream>
using namespace std;


//this class is setting up infomration categories about a pokemon. for example, a pokemon has a name and a type
class Pokemon 
{
    friend ostream& operator<< (ostream& os, const Pokemon& x); //overloading the << operator to display the contents of the Pokemon better. will be useful later in PokeCards class

    public:
    Pokemon();
    Pokemon(string pName, int pID, string pType, string pType2, short int pGender, short int pShiny, double pValue); //optional constructor, used for testing purposes

    
    //setter functions
    void SetPokemonName(string pokeName);
    void SetPokeID(int pID );
    void SetType(string pType);
    void SetSecondaryType(string pType2);
    void SetGender(short int pGender);
    void SetShiny(short int pShiny);
    void SetValue(double pValue = 0);      /*this just means i have certain plans for the card when i set the value to 0(looking at shiny and id). 
    for certain cards, let's say bulbasaur (my favorite pokemon), i may use this function and manually set a function. i.e., pValue = 200 for 200 bucks*/

    //getter functions
    string GetPokemonName() const;
    int GetPokeID() const;
    string GetType() const;
    string GetSecondaryType() const;
    short int GetGender() const;
    short int GetShiny() const;
    double GetValue() const;


    private:
    string pokeName, pokeType, pokeType2;
    short int pokeGender, pokeShiny;
    double pokeValue;

    int pokeID;    
};