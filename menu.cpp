#include "menu.h"
#include "packs.h"

int main()
{
    bool temp = false;
    string typeName;
    char option; 
    cout << "\nWARNING: This is the driver (testing) file. You MUST click 'Q' to quit the program after every function you are interested in testing out." << endl;
    cout << "Enter 'W' to start." << endl;

    PokeCards players_binder;
    PokePacks PokemonPacks;
    srand(unsigned (time(0)));        // setting this instance of time as the seed before the open-pack function (or any function for that matter) is called 
                
    while(temp == false)
    {
        cout << "\nyo, what u wanna do? " << endl;

        cin >> option;
        option = toupper(option);

        switch(option)
        {

            case 'Q':  cout << "goodbye!!" << endl; temp = true; break;

            case 'I': //tests the import pokemon from text file function
            {
                PokeCards Generation1;
                Generation1.ImportPokemon("Pokemon_Gen1.txt"); break;
            }
            case 'S': //tests the show all pokemon function
            {
                PokeCards Generation1;
                Generation1.ImportPokemon("Pokemon_Gen1.txt"); 
                cout << "\n\n\n" << endl;
                Generation1.ShowALLPokemon(); break; 
            }

            case 'C':  //testing the count type of Pokemon in a dma (PokeCards class) function
            {
                PokeCards Generation1;
                Generation1.ImportPokemon("Pokemon_Gen1.txt");
                cout << "\n\n\nThis is the count-total-number-of-desired-types function. Enter a name of type you are looking for: ";
                cin >> typeName;
                cout << Generation1.CountType(typeName);
                break;
            }
        

            case 'T':
            /*
            the import type function (belonging to class PokeCards). 

            This extracts all desired type of Pokemons from the original DMA (containing all 151 pokemon) and places them 
            into a new dma (still from the PokeCards class) devoted to that type and those pokemon. 

            i.e, if FireCards.ImportType(Generation1, "Fire"), then a new dma is created to hold all the fire pokemon in there.
            this will represent a pack of fire pokemon, in which the player will pull a fire pokemon from that pack if the 
            pull-a-pokemon function is used later on.
            */
            {
                PokeCards Generation1;
                Generation1.ImportPokemon("Pokemon_Gen1.txt");
                cout << "\nThis is the import type function. Enter a name of type, and the pack object will be sorted to hold only that type: ";
                cin >> typeName;

                PokeCards FireCards;
                FireCards.ImportType(Generation1, "Fire"); 
                
                cout << "A dma of " << typeName <<  " Pokemon has been created by the PokeCards class named " << typeName << " Cards." << endl; 
                cout << "This dma pack object will be used later on if the player wants to open a pack of " << typeName << " cards." << endl;

                FireCards.ShowALLPokemon();
                break;
            }
            

            case 'O': //testing the open-a-pack function (this function is called OpenPack and is from the PokePacks class)
            {            
                //in this class called PokePacks, the constructor uses the other classes of PokeCards and Pokemon to 
                //form the ideas of packs (exploiting the cs concept of a "has-a" relationship. i.e, a deck of cards HAS cards in it). 

                //from here, the PokePacks class offers a function named OpenPack, which uses functions from the 
                //PokeCards class- which, under a set of math algorithims (odds/loot system), releases elements from the start 
                //of it all- the Pokemon class. These elements are then returned as a PokeCard object.

                char packOption;
                cout << "\nWhat pack of cards do you want to open?" << endl;
                cout << "\n\tG = Open a pack of grass Pokemon" << endl;
                cout << "\n\tF = Open a pack of fire Pokemon" << endl;
                cout << "\n\tW = Open a pack of water Pokemon";

                cout << "\n\n\n\n\n\n\nSelection: ";

                cin >> packOption;
                cout << endl;
                PokemonPacks.OpenPack(packOption);
                break;
            }

            case 'W': 
            {
                cout << "\nThese are the options available for testing right now:" << endl;
                cout << "\n\t Q - quit" << endl;
                cout << "\n\t I - Import function. Import pokemon from the text file" << endl;
                cout << "\n\t S - Show Pokemon function. Shows all pokemon from the text file (basic information)" << endl;
                cout << "\n\t C - Count-a-type-of-Pokemon function. Counts the total amount of a specific types of a PokeCards object after user specifies the type" << endl;
                cout << "\n\t T - Import-Type function. Extracts all desired type of Pokemon from the original DMA and imports them in a new PokeCards object devoted to that\n\t type" << endl;
                cout << "\n\t O - Open pack function. A Pokemon Object is 'returned' from a dma PokeCards object. In other words, opens a pack and get a singular Pokemon\n\t card" << endl;
                cout << "\n\t A - Advance open pack function. Opens a pack and load the cards (5) in the player's binder collection." << endl;
                cout << "\n\t D- Disaster or success function. This function displays the player's inventory. Best used after L functoion." << endl;
                break;
            }

            case 'A':
            {
                cout << "The purpose of this test call is to use the functions to open a pack of cards, then save the card to the player's";
                cout << " 'inventory', so to speak." << endl << endl;  

                char packOption;
                cout << "\nWhat pack of cards do you want to open?" << endl;
                cout << "\n\tG = Open a pack of grass Pokemon" << endl;
                cout << "\n\tF = Open a pack of fire Pokemon" << endl;
                cout << "\n\tW = Open a pack of water Pokemon";

                cout << "\n\n\n\n\n\n\nSelection: ";

                cin >> packOption;
                packOption = toupper(packOption);

                while(packOption != 'G' && packOption != 'F' && packOption != 'W')
                {
                    cout << "Sorry, that is an invalid selection. . .\n" << endl;
                    cout << "\nWhat pack of cards do you want to open?" << endl;
                    cout << "\n\tG = Open a pack of grass Pokemon" << endl;
                    cout << "\n\tF = Open a pack of fire Pokemon" << endl;
                    cout << "\n\tW = Open a pack of water Pokemon";

                    cout << "\n\n\n\n\n\n\nSelection: ";
                    
                    cin >> packOption;
                    packOption = toupper(packOption);
                }
                

                const short int numOfCards = 5;

                cout << "\nA pack of " << numOfCards;
                switch(packOption)
                {
                    case 'G': cout << " grass"; break;
                    case 'F': cout << " fire"; break;
                    case 'W': cout << " water"; break;
                }

                cout << " Pokemon was opened!\n\n";

                for(short int j = 0; j < numOfCards; j++)
                {
                    cout << j +1 << ") ";
                    players_binder.playerOpenpack(PokemonPacks.OpenPack(packOption));
                }
                break;
            }

            case 'D':
            {
                cout << "Display function. The purpose of this function is to display the player's binder of cards acquired." << endl;
                players_binder.ShowALLPokemon();
                break;
            }

            case 'M':
            {
                cout << "The mold function. This function is to mold the pack of cards so that the most expensive card appears last." <<endl;
                break;

            }
            
            cout << "another test" << endl;
        }
    }
}









