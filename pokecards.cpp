#include "pokecards.h"

PokeCards::PokeCards()
{
    currentSize = 0;
    maxSize = 1;
    allCards = new Pokemon[maxSize];
}

PokeCards::~PokeCards()
{
    delete [] allCards;
}

void PokeCards::Resize(int totalPoke)
{
    //cout << "*** Dynamic memomry allocated array being reconstructed . . ." << endl;
    //cout << "Current size was: " << currentSize << ". Max size was: " << maxSize << endl;

    if(totalPoke > 0) 
    {   
        Pokemon * tempy = new Pokemon[totalPoke];

        for(short int p = 0; p < maxSize; p++)           
        {
            tempy[p] = allCards[p];
        }

        delete [] allCards;

        allCards = tempy;

        maxSize = totalPoke;
    }

    if(totalPoke == 0) //in the first case, or n > 0, the answer of how many cards will be in the dma was known. in this case, we do not know that. so we increment by one
    {
        maxSize += 5;
        Pokemon * tempy = new Pokemon[maxSize];

        //cout << "what is the current size?? it is " << currentSize << endl;

        for(int p = 0; p < currentSize; p++)           
        {
            tempy[p] = allCards[p];
        }

        delete [] allCards;

        allCards = tempy;
    }

    /*
    cout << "advance testing: here's all the pokemon in the current thing: " << endl;

    ShowALLPokemon();

    */

   // cout << "Current size is now: " << currentSize << ". Max size is now: " << maxSize << endl;
   // cout << "*** Dynamic memomry allocated array has been reconstructed . . ." << endl;

   /* Future work below
   if(currentSize != 0)
    {
        if(maxSize - currentSize > 6)    
        //if the difference between maxsize and currentsize is over 6, then there is too much space. 
        //this is most likely because the player took out pokemon. in this case, the array's maxsize will get smaller by 5
        //i.e., if current size is 10 and maxsize is 16, this will make the current size still 10 but maxsize 11.
        
        this needs to be revisted
        {
            cout << "*** Dynamic memomry allocated array being reconstructed . . ." << endl;
            cout << "Current size was: " << currentSize << ". Max size was: " << maxSize << endl;
            maxSize -= 5;
            cout << "Current size is now: " << currentSize << ". Max size is now: " << maxSize << endl;
            cout << "*** Dynamic memomry allocated array has been reconstructed . . ." << endl;   
        }
    }
    */
}

PokeCards& PokeCards::operator= (const PokeCards &rightObject)
{
    if (this!= &rightObject)
    {
        delete [] allCards;
        // cout << "rightObject.currentSize is :" << endl;
        currentSize = rightObject.currentSize;
        allCards = new Pokemon[rightObject.maxSize];
        for (int i = 0; i < currentSize; i++)
	    allCards[i] = rightObject.allCards[i];
    }
    return *this;
}

bool PokeCards::SortandShowPokemonbyValue()
{
    if(currentSize==0 && maxSize == 1)
    {
        cout << "There is nothing to sort! The amount of cards in the pack is 0." << endl;
        return false;
    }
    /*
    else
    {
        int SMALLEST_VALUE = 0;
        int SECOND_SMALLEST= 0;
        int THIRD_SMALLEST= 0;
        int FOURTH_SMALLEST= 
        int HIGHEST_VALUE = 0;
        
        for(short int j = 0; j < maxSize; j++)
        {
            if(allCards[j].GetValue() < SMALLEST_VALUE)
            {
                SMALLEST_VALUE = j;


            }
        }

        
    }*/
}





bool PokeCards::ImportPokemon(const char* filename)
{
    bool success = true;           //creates a bool named success, default set to true. this will help later to see if function worked or not
    ifstream PokeGen1;             //creates an ifstream object named PokeGen1
    PokeGen1.open(filename);       //opens the ifstream object, assiging a text file which will have information of pokemon from gen 1
    
    if(!PokeGen1)                  //if file is bad, creates flag. this means I or user messed up, so it returns user to menu
    {
        cout << "\nFile has unsuccessfully opened. Exting import menu-function. Sorry . . . " << endl;
        success = false;
        return success;  
    } 

    short int tempID, totalNumber, j, q; 
    string tempName, tempType1, tempType2;

    PokeGen1 >> totalNumber;
    PokeGen1.ignore();

    Resize(totalNumber);                               
     
    //cout << "\n\n\n~~~~Entering for loop" << endl;

    for(j=0; j < totalNumber; j++)
    /*
    MaxSize = totalNumber. Array starts at 0. thus, if max = 3, then poke1 at slot 0, poke2 at slot 1, poke3 at slot 2. so currentSize, representing the
    index, should be at slot 2 if max = 3. This is done by starting currentSize at 0, then increment for 0 < 3, resulting in currentsize to be 2.
     */

    {
        //cout << "\n~~DMA information~~~" << endl;
        //cout << "What is maxsize at this point? Line 104, pokecards.cpp. It's : " << maxSize << endl;
        //cout << "What is currentsize at this point? Line 105, pokecards.cpp. It's: " << currentSize << endl;
        PokeGen1 >> tempID;

        //cout << "\n\n\ntempID gathered was: " << tempID << endl;
        PokeGen1.ignore();

        PokeGen1 >> tempName;
        //cout << "tempName gathered was: " << tempName << endl;
        PokeGen1.ignore();

        PokeGen1 >> tempType1;

        if( tempType1[tempType1.length()-1] == ',')  
        {

            tempType1 = tempType1.erase(tempType1.length()-1);        //getting rid of the comma before storing information
            //cout << "tempType1 gathered is: " << tempType1 << endl;

            PokeGen1 >> tempType2;

            //cout << "temp type 2 data is : " << tempType2 << endl;             

            allCards[currentSize].SetPokemonName(tempName);
            allCards[currentSize].SetPokeID(tempID);
            allCards[currentSize].SetType(tempType1);
            allCards[currentSize].SetSecondaryType(tempType2);


            // cout << allCards[currentSize].GetPokemonName();
            //cout << allCards[currentSize].GetPokeID();
            //cout << allCards[currentSize].GetType();
            //cout << allCards[currentSize].GetSecondaryType();

            //cout << tempName << " has just been loaded in allCards[" << currentSize << "]."<< endl;
        }

        else if (tempType1[tempType1.length()-1] != ',')    //no comma, no problem. info gets stored without modifications (this implies this pokemon has no secondary type)
        {
            //cout << "tempType1 gathered is: " << tempType1 << endl;

            allCards[currentSize].SetPokemonName(tempName);
            allCards[currentSize].SetPokeID(tempID);
            allCards[currentSize].SetType(tempType1);
            allCards[currentSize].SetSecondaryType("NONE");
            //cout << tempName << " has just been loaded in allCards[" << currentSize << "]."<< endl;
        }

        PokeGen1.ignore();
        currentSize++;       //notice the currentSize being incremented each time for loop runs. this ties in with what i said earlier from the for loop note
    }
    PokeGen1.close();
    return success;
}

PokeCards& PokeCards::ImportType(const PokeCards &d,string nameOFtype)
{
    /*
    cout << "allcards' currentSize is " << d.currentSize << endl;
    cout << "allcards' maxSize is " << d.maxSize << endl;
    cout << "The number of " << nameOFtype << " pokemon found was " << d.CountType(nameOFtype) << endl;
    */

    maxSize = d.CountType(nameOFtype);

    /*
    cout << "\nThe new dynamic array for the PokeCards object that called this function is now: " << maxSize << endl;
    cout << "What shoud the currentSize be? " << endl;
    */

    delete [] allCards;

    allCards = new Pokemon[maxSize];

    short int j = 0;

    for (int i = 0; i < d.currentSize; i++)
    {
        if(d.allCards[i].GetType() == nameOFtype || d.allCards[i].GetSecondaryType() == nameOFtype)
        {
            //cout << "match found from original dma at slot (i is): " << i << endl;
            allCards[j] = d.allCards[i];
            //cout << d.allCards[i].GetPokemonName() << " was just loaded in the new array slot " << j << "." << endl;
            j++;
            //cout << "j is now at " << j << endl;
        }
    }
    
    currentSize = maxSize; // it's like [o] [o] [o] [x], where x is currentsize and maxSize

    /*the new PokeCards object will always have the same amount of currentSize and maxSize. this is a special case where ReSize (making sure maxSize is more
    than currentSize) is not needed, because the packs will never be bigger. the packs will never gain additional cards. They're packs! They contain a constant
    number of cards, which is always equal to the count type function from the original dma. i.e., if 13 fire cards were counted from the original 151 pokemon, 
    then firecards pack will always have 13 cards.*/

    return *this;
}

void PokeCards::ShowALLPokemon() const
{
    if (currentSize == 0)
    {
        cout << "\nYou have no cards. Your binder is empty!\n";
        return;
    }

    cout << "\n\t***NAME***\t\t***TYPE***\t\t***ID***\t\t***Gender***\t\t***SHINY***\t\t***VALUE***";  

    for(short int i = 0; i < currentSize; i++ ) 
    {
        cout << allCards[i] << endl; //Since I overloaded the << operator from the Pokemon class, I am taking advantage of it here
    }

}



int PokeCards::CountType(string nameOfType) const                 //will count the amount of pokemon with a specific type 
{
    short int numOftypes = 0;

    for(short int k = 0; k < currentSize; k++)
    {
        if(allCards[k].GetType() == nameOfType || allCards[k].GetSecondaryType() == nameOfType)
        {
            numOftypes++;   
        }
    }

    /*
    cout << "There are " << numOftypes << " of " << nameOfType << " pokemon found." << endl; 
    for(short int k = 0; k < currentSize; k++)
    {
        if(allCards[k].GetType() == nameOfType || allCards[k].GetSecondaryType() == nameOfType)
        {
            cout << allCards[k].GetPokemonName() << endl;
        }
        
    }
    */
   return numOftypes;
}

int lottoNumber(short int n = 100, short int n2 = 1)     //returns a number between specified parameters. parameters = range
{
    unsigned lotteryNumber = 0;
    lotteryNumber = rand()% n + n2;     // if (100, 1), default parameters, then range is 1-100. if (25, 1), then range is 1-25.
    return lotteryNumber;               //if you are wondering what the seed is, i set it in the menu.cpp right before i call the open-pack function

    /* 
    the brief description of the system i came up with to determine rarity

    [1-61] = common card, prob = 61/100
    [62- 92)- = uncommon cards, prob= 32/100
    [93 - 100) = rare cards, prob 8/100
    [100]  = legendary (increased shiny odds to guaranteed shiny)
    */
}


const Pokemon& PokeCards::pullAPokemon(char whichHelper) 
{    
    //Refers to a specific helper pack-opener-function to pull a Pokemon Card!
    switch(whichHelper)
    {
        case 'F': PullFire(); break;
        case 'W': PullWater(); break;
        case 'G': PullGrass(); break;
    }
}

PokeCards& PokeCards::saveCardPulled(const Pokemon & pokemonCardpulledFrompack) //really should be called packType inistead of pokemoncardpulledfrompack
{
    //cout << "\nAt start of function, currentSize is " << currentSize << endl;
    //cout << "maxSize is " << maxSize << endl;
    //cout <<  "\nattempting to load the card in allCards[" << currentSize << "]" << endl;

    allCards[currentSize] = pokemonCardpulledFrompack;              //loading in the card to the current slot
    
    //cout << "allCards[" << currentSize << "] has been loaded with " << pokemonCardpulledFrompack.GetPokemonName() << endl;

    currentSize++;
    //cout << "after ++, cs is now " << currentSize << endl;

    if(currentSize == maxSize)
    {
        //cout << "need to regrow.\n" << endl;
        Resize(0);           //when 0 is placed in the parameter, the resize function does special instructions
    }
}

const Pokemon& PokeCards::PullGrass()
{
    short int diceRoll, secondDiceroll, isShiny, i;
    diceRoll = lottoNumber();
    isShiny = lottoNumber(12, 1);       //chances of getting a shiny is 1/12

    //cout << "isShiny (if 1, poke will be shiny. 8.3% chance): " << isShiny << endl;
    cout << "diceRoll: " << diceRoll;
    

    if(diceRoll >= 1 && diceRoll < 62)
    {
        //cout << "Player has entered sub-category common based on dice roll (61% chance). Depending on second dice roll, they can get 1 = Exeggcute, 2 = BellSprout, 3 = Oddish" << endl;
        secondDiceroll = lottoNumber(3, 1);  //1 = Exeggcute, 2 = BellSprout, 3 = Oddish
        cout << ", second dice roll: " << secondDiceroll;

        if(secondDiceroll == 1)  //Exeggcute
        {
            if(isShiny == 1)     //Player just pulled a shiny Exeggcute
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 102)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Exeggcute
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 102)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2)
        {
            if(isShiny == 1)     //Player just pulled a shiny Exeggcute
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 69)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 69)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled Oddish
        {
            if(isShiny == 1)     //Player just pulled a shiny Oddish
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 43)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 43)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }



    }

    if(diceRoll >= 62 && diceRoll < 93)
    {
        //cout << "Player has entered sub-category uncommon based on dice roll (30% chance). Depending on second dice roll, they can get 1 = Weepinbell, 2 = Gloom, 3 = Bulbasaur,\n4 = Ivysaur" << endl;
        secondDiceroll = lottoNumber(4, 1);  //1 = Weepinbell, 2 = Gloom, 3 = Bulbasaur, 4 = Ivysaur
        cout << ", second dice roll: " << secondDiceroll;

        if(secondDiceroll == 1)  //Player just pulled Weepinbell
        {
            if(isShiny == 1)     //Player just pulled a shiny Weepinbell
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 70)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player pulled a non-shiny Weepinbell
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 70)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled Gloom
        {
            if(isShiny == 1)     //Player just pulled a shiny Gloom
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 44)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Gloom
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 44)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled Bulbasaur
        {
            if(isShiny == 1)     //Player just pulled a shiny bulbasaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 1)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Bulbasaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 1)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled an Ivysaur
        {
            if(isShiny == 1)     //Player just pulled a shiny bulbasaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 2)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Ivysaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 2)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }
    }

    if(diceRoll >= 93 && diceRoll < 100)
    {
        //cout << "Player has entered sub-category epic based on dice roll (8% chance). Depending on second dice roll, they can get 1 = Venusaur, 2 = Vileplume, 3 = Tangela, \n4 = Exeggutor, 5 = Victreebel, 6 = Stephanie" << endl;

        secondDiceroll = lottoNumber(6, 1);  //1 = Venusaur, 2 = Vileplume, 3 = Tangela, 4 = Exegguter, 5 = Victreebel, 6 = Stephani

        //cout << "second dice roll is " << secondDiceroll << endl;
        cout << ", second dice roll: " << secondDiceroll;

        if(secondDiceroll == 1)  //Venusaur
        {
            if(isShiny == 1)     //Player just pulled a shiny Venusaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 3)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Venusaur
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 3)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled an Vileplume
        {
            if(isShiny == 1)     //Player just pulled a shiny Vileplume
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 45)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Vileplume
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 45)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled an Tangela
        {
            if(isShiny == 1)     //Player just pulled a shiny Tangela
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 114)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Tangela
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 114)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled a Exeggutor
        {
            if(isShiny == 1)     //Player just pulled a shiny Exeggutor
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 103)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Exeggutor
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 103)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 5) // Player just pulled a Victreebel
        {
            if(isShiny == 1)     //Player just pulled a shiny Victreebel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 71)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Victreebel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 71)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 6) // Player just pulled a Stephani
        {
            if(isShiny == 1)     //Player just pulled a shiny Stephani
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 153)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Stephani
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 153)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }      
    }

    if(diceRoll == 100) //guaranteed shiny grass pokemon
    {
        //cout << "Player has entered sub-category legendary (1% chance). Here, the player will be guranteed a shiny pokemon based on the second dice roll." << endl;
        //cout << "1 = Exeggcute, 2 = Bellsprout, 3 = Oddish, 4 = Weepinbell, 5 = Gloom, 6 = Bulbasaur, 7 = Ivysaur, 8 = Venusaur\n, 9 = Vileplume, 10 = Tangela, 11 = Exeggutor, 12 = Victreebel" << endl;
        
        secondDiceroll= lottoNumber(12, 1); // 1-12

        if(secondDiceroll == 1) // Exeggcute
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 102)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 2) // Bellsprout
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 69)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 3) // Oddish
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 43)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 4) // Weepinbell
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 70)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 5) // Gloom
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 44)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 6) // Bulbasaur
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 1)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 7) // Ivysaur
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 2)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 8) // Venusaur
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 3)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 9) // Vileplume
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 45)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 10) // Tangela
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 114)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 11) // Exegguter
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 103)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 12) // Victreebel
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 71)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }
    }
}

const Pokemon& PokeCards::PullFire()
{
    short int diceRoll, secondDiceroll, isShiny, i;
    diceRoll = lottoNumber();
    isShiny = lottoNumber(12, 1);       //chances of getting a shiny is 1/12

    //cout << "isShiny (if 1, poke will be shiny. 8.3% chance): " << isShiny << endl;
    //cout << "diceRoll: " << diceRoll << endl;
    
    if(diceRoll >= 1 && diceRoll < 62)
    {
        //cout << "Player has entered sub-category common based on dice roll (61% chance). Depending on second dice roll, they can get 1 = Vulplix, 2 = Growlithe, 3 = Arcanine,\n4 = Ponyta" << endl;
        secondDiceroll = lottoNumber(4, 1);  //1 = Vulplix, 2 = Growlithe, 3 = Arcanine, 4 = Ponyta
        //cout << "secondDiceroll = " << secondDiceroll << endl;

        if(secondDiceroll == 1)  //Vulpix
        {
            if(isShiny == 1)     //Player just pulled a shiny Vulpix
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 37)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Vulpix
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 37)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);    
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) //Growlithe
        {
            if(isShiny == 1)     //Player just pulled a shiny Growlithe
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 58)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);    
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 58)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);    
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Arcanine
        {
            if(isShiny == 1)     //Player just pulled a shiny Arcanine
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 59)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);    
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 59)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);    
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) //Ponyta
        {
            if(isShiny == 1)     //Player just pulled a shiny Ponyta
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 77)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 77)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }



    }   

    if(diceRoll >= 62 && diceRoll < 93)
    {
        //cout << "Player has entered sub-category uncommon based on dice roll (30% chance). Depending on second dice roll, they can get 1 = Charmander, 2 = Charmeleon, 3 = Rapidash,\n4 = Flareon" << endl;
        secondDiceroll = lottoNumber(4, 1);  //1 = Charmander, 2 = Charmeleon, 3 = Rapidash, 4 = Flareon
        //cout << "secondDiceroll = " << secondDiceroll << endl;

        if(secondDiceroll == 1)  //Player just pulled Charmander
        {
            if(isShiny == 1)     //Player just pulled a shiny Charmander
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 4)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player pulled a non-shiny Charmander
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 4)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled Charmeleon
        {
            if(isShiny == 1)     //Player just pulled a shiny Charmeleon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 5)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Charmeleon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 5)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled Rapidash
        {
            if(isShiny == 1)     //Player just pulled a shiny Rapidash
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 78)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Rapidash
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 78)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled a Flareon
        {
            if(isShiny == 1)     //Player just pulled a shiny Flareon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 136)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Flareon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 136)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }
    }

    if(diceRoll >= 93 && diceRoll < 100)
    {
        //cout << "Player has entered sub-category epic based on dice roll (8% chance). Depending on second dice roll, they can get 1 = Venusaur, 2 = Vileplume, 3 = Tangela, \n4 = Exeggutor, 5 = Victreebel" << endl;
        secondDiceroll = lottoNumber(5, 1);  //1 = Charizard, 2 = Ninetails, 3 = Magmar, 4 = Moltress, 5 = Dillon
        //cout << "secondDiceroll = " << secondDiceroll << endl;

        if(secondDiceroll == 1)  //Charizard
        {
            if(isShiny == 1)     //Player just pulled a shiny Charizard
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 6)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Charizard
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 6)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled a Ninetails
        {
            if(isShiny == 1)     //Player just pulled a shiny Ninetails
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 38)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Ninetails
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 38)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled an Magmar
        {
            if(isShiny == 1)     //Player just pulled a shiny Magmar
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 126)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Magmar
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 126)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled a Moltress
        {
            if(isShiny == 1)     //Player just pulled a shiny Moltress
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 146)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! WOAH!! This " << allCards[i].GetPokemonName() << " is shiny?!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Moltress
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 146)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 5) // Player just Dillon
        {
            if(isShiny == 1)     //Player just pulled a shiny Dillon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 152)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(10000000);  
                        cout << " . . . ! Woah! It's Uncle Dill! But he looks a bit different . . ." << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Dillon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 152)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(1000000); 
                        cout  << "Woah?! This is.. wait. . . This is Uncle " << allCards[i].GetPokemonName() << "!?" << endl;
                        return allCards[i];
                    }
                }
            }
        }
    
    }

    if(diceRoll == 100) //guaranteed shiny fire pokemon
    {
        //cout << "Player has entered sub-category legendary (1% chance). Here, the player will be guranteed a shiny pokemon based on the second dice roll." << endl;
        //cout << "1 = Vulplix, 2 = Growlithe, 3 = Arcanine, 4 = Ponyta, 5 = Charmander, 6 = Charmeleon,\n7 = Rapidash, 8 = Flareon, 9 = Charizard, 10 = Ninetails, 11 = Magmar, 12 = Moltress" << endl;
        
        secondDiceroll= lottoNumber(12, 1); // 1-12
        //cout << "secondDiceroll = " << secondDiceroll << endl;

        if(secondDiceroll == 1) // Vulplix
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 37)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 2) // Growlithe
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 58)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 3) // Arcanine
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 59)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 4) // Ponyta
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 77)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 5) // Charmander
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 4)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 6) // Charmeleon
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 5)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 7) // Rapidash
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 77)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 8) // Flareon
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 136)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 9) // Charizard
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 6)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 10) // Ninetails
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 38)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 11) // Magmar
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 126)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        if(secondDiceroll == 12) // Moltress
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 146)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }
    }
}

const Pokemon& PokeCards::PullWater()
{
    short int diceRoll, secondDiceroll, maleOrfemale, isShiny, i;
    diceRoll = lottoNumber();
    isShiny = lottoNumber(12, 1);       //chances of getting a shiny is 1/12

    //cout << "isShiny (if 1, poke will be shiny. 8.3% chance): " << isShiny << endl;
    cout << "diceRoll: " << diceRoll << endl;
    
    if(diceRoll >= 1 && diceRoll < 62) 
    {
        //cout << "Player has entered sub-category common based on dice roll (61% chance). Depending on second dice roll, they can get 1 = Poliwag, 2 = Tentacool, 3 = Slowpoke, \n4 = Seel, 5 = Shelder, 6= Krabby, 7 = Horsea, 8 = Goldeen, 9 = Staryu, 10 = Magikarp" << endl;
        secondDiceroll = lottoNumber(10, 1);  // 1 = Poliwag, 2 = Tentacool, 3 = Slowpoke, 4 = Seel, 5 = Shelder, 6= Krabby, 7 = Horsea, 8 = Goldeen, 9 = Staryu, 10 = Magikarp

        cout << "Player rolled: " << secondDiceroll << endl << endl;

        if(secondDiceroll == 1)  //Poliwag
        {
            if(isShiny == 1)     //Player just pulled a shiny Poliwag
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 60)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Poliwag
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 60)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) //Tentacool
        {
            if(isShiny == 1)     //Player just pulled a shiny Tentacool
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 72)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 72)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Slowpoke
        {
            if(isShiny == 1)     //Player just pulled a shiny Slowpoke
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 79)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 79)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) //Seel
        {
            if(isShiny == 1)     //Player just pulled a shiny Seel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 86)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 86)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 5) //Shelder
        {
            if(isShiny == 1)     //Player just pulled a shiny Shelder
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 90)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 90)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 6) //Krabby
        {
            if(isShiny == 1)     //Player just pulled a shiny Krabby
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 98)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 98)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 7) //Horsea 
        {
            if(isShiny == 1)     //Player just pulled a shiny Horsea
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 116)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 116)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 8) //Goldeen
        {
            if(isShiny == 1)     //Player just pulled a shiny Goldeen
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 118)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 118)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 9) //Staryu
        {
            if(isShiny == 1)     //Player just pulled a shiny Staryu
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 120)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 120)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 10) 
        {
            if(isShiny == 1)     //Player just pulled a shiny Magikarp
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 129)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else  
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 129)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

    }   

    if(diceRoll >= 62 && diceRoll < 93) 
    {
        
        //cout << "Player has entered sub-category uncommon based on dice roll (30% chance). Depending on second dice roll, they can get 1 = Squirtle, 2 = Wartotoile, 3 = Pscyduck, \n4 = Tentacruel, 5 = Slowbro, 6 = Dewong, 7 = Cloyster, 8 = Kingler, 9 = Seaking, 10 = Starmine, 11 = Vaporeon, 12 = Poliwhirl" << endl;
        secondDiceroll = lottoNumber(12, 1);  //1 = Squirtle, 2 = Wartotoile, 3 = Pscyduck, 4 = Tentacruel, 5 = Slowbro, 6 = Dewong, 7 = Cloyster, 8 = Kingler, 9 = Seaking, 10 = Starmine, 11 = Vaporeon, 12 = Poliwhirl

        cout << "Player rolled: " << secondDiceroll << endl << endl;


        if(secondDiceroll == 1)  //Player just pulled Squirtle
        {
            if(isShiny == 1)     //Player just pulled a shiny Squirtle
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 7)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player pulled a non-shiny Squirtle
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 7)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled Wartotoile
        {
            if(isShiny == 1)     //Player just pulled a shiny Wartotoile
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 8)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Wartotoile
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 8)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled Pscyduck
        {
            if(isShiny == 1)     //Player just pulled a shiny Pscyduck
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 54)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Pscyduck
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 54)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled a Tentacruel
        {
            if(isShiny == 1)     //Player just pulled a shiny Tentacruel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 73)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Tentacruel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 73)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 5) // Player just pulled a Slowbro
        {
            if(isShiny == 1)     //Player just pulled a shiny Slowbro
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 80)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Slowbro
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 80)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 6) // Player just pulled a Dewong
        {
            if(isShiny == 1)     //Player just pulled a shiny Dewong
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 87)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Dewong
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 87)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 7) // Player just pulled a Cloyster
        {
            if(isShiny == 1)     //Player just pulled a shiny Cloyster
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 91)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Cloyster
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 91)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 8) // Player just pulled a Kingler
        {
            if(isShiny == 1)     //Player just pulled a shiny Kingler
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 99)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Kingler
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 99)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 9) // Player just pulled a Seaking
        {
            if(isShiny == 1)     //Player just pulled a shiny Seaking
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 119)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Seaking
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 119)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 10) // Player just pulled a Starmine
        {
            if(isShiny == 1)     //Player just pulled a shiny Starmine
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 121)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Starmine
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 121)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 11) // Player just pulled a Vaporeon
        {
            if(isShiny == 1)     //Player just pulled a shiny Vaporeon
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 134)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Tentacruel
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 134)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 12) // Player just pulled a Poiwhirl
        {
            if(isShiny == 1)     //Player just pulled a shiny Poiwhirl
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 61)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        cout << "the odds of getting a shiny " << allCards[i].GetPokemonName() << " is 2.5% !" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Poiwhirl
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 61)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

    }

    if(diceRoll >= 93 && diceRoll < 100) 
    {
        //cout << "Player has entered sub-category epic based on dice roll (8% chance). Depending on second dice roll, they can get 1 = Blastoise, 2 = Golduck, 3 = Poliwrath, 4 = Seadra, 5 = Gyrados, 6 = Lapras" << endl;

        secondDiceroll = lottoNumber(6, 1);  //1 = Blastoise, 2 = Golduck, 3 = Poliwrath, 4 = Seadra, 5 = Gyrados, 6 = Lapras

        cout << "Player rolled: " << secondDiceroll << endl << endl;

        if(secondDiceroll == 1)  //Blastoise
        {
            if(isShiny == 1)     //Player just pulled a shiny Blastoise
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 9)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else                //Player did not pull a shiny Blastoise
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 9)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1)); 
                        allCards[i].SetValue(0);  
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 2) // Player just pulled a Golduck
        {
            if(isShiny == 1)     //Player just pulled a shiny Golduck
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 55)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Golduck
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 55)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 3) // Player just pulled a Poliwrath
        {
            if(isShiny == 1)     //Player just pulled a shiny Poliwrath
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 62)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Poliwrath
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 62)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 4) // Player just pulled a Seadra
        {
            if(isShiny == 1)     //Player just pulled a shiny Seadra
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 117)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! WOAH!! This " << allCards[i].GetPokemonName() << " is shiny?!!" << endl;
                        return allCards[i];
                    }
                }
            }

            else // player pulled a non-shiny Seadra
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 117)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0);   
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 5) // Player just Gyrados
        {
            if(isShiny == 1)     //Player just pulled a shiny Gyrados
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 130)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! Woah! It's a RED Gryados?!!" << endl;
                    }
                }
            }

            else // player pulled a non-shiny Gryados
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 130)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;
                        return allCards[i];
                    }
                }
            }
        }

        else if(secondDiceroll == 6) // Player just Lapras
        {
            if(isShiny == 1)     //Player just pulled a shiny Lapras
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 131)
                    {
                        allCards[i].SetShiny(1);
                        allCards[i].SetGender(lottoNumber(2,1));  
                        allCards[i].SetValue(0); 
                        cout << " . . . ! WOAH!! This " << allCards[i].GetPokemonName() << " is shiny?!!" << endl;
                    }
                }
            }

            else // player pulled a non-shiny Lapras
            {
                for(i = 0; i < currentSize; i++)
                {
                    if (allCards[i].GetPokeID() == 131)
                    {
                        allCards[i].SetShiny(0);
                        allCards[i].SetGender(lottoNumber(2,1));
                        allCards[i].SetValue(0); 
                        cout  << "The card pulled was " << allCards[i].GetPokemonName() << "!" << endl;  
                        return allCards[i];
                    }
                }
            }
        }
    
    }

    if(diceRoll == 100) //guaranteed shiny fire pokemon
    {
        //cout << "Player has entered sub-category legendary (1% chance). Here, the player will be guranteed a shiny pokemon based on the second dice roll." << endl;
        //cout << "1 = Poliwag, 2 = Tentacool, 3 = Slowpoke, 4 = Seel, 5 = Shelder, 6 = Krabby,\n7 = Horsea, 8 = Horsea, 9 = Staryu, 10 = Makikarp, 11 = Squirtle, 12 = Wartortle\n13 = Pscyduck, 14 = Tentacruel, 15 = Slowbro, 16= Dewong, ";
        //cout << "17 = Cloyster, 18= Kingler\n19= Seaking, 20 = Starmine, 21 = Vaporeon, 22 = Poliwhirl, 23= Blastoise, 24 = Golduck\n25= Poliwrath, 26 = Seadra, Gyrados = 27, Lapras = 28" << endl;
        
        secondDiceroll= lottoNumber(28, 1); // 1-28

        cout << "Player rolled: " << secondDiceroll << endl << endl;

        if(secondDiceroll == 1) // Poliwag
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 60)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 2) // Tentacool
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 72)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));
                    allCards[i].SetValue(0);   
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 3) // Slowpoke
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 79)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 4) // Seel
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 86)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 5) // Shelder
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 90)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 6) // Krabby
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 98)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 7) // Horsea
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 116)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 8) // Goldeen
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 118)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 9) // Staryu
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 120)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 10) // Magikarp
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 129)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 11) // Squirtle
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 7)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 12) // Wartotoile
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 8)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 13) // Pscyduck
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 54)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 14) // Tentacruel
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 73)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 15) // Slowbro
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 80)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 16) // Dewong
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 87)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 17) // Cloyster
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 91)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 18) // Kingler
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 99)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 19) // Seaking
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 119)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 20) // Starmine
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 121)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 21) // Vaporeon
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 134)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 22) // Poiwhirl
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 61)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 23) // Blastoise
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 9)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 24) // Golduck
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 55)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1)); 
                    allCards[i].SetValue(0);  
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 25) // Poliwrath
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 62)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 26) // Seadra
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 117)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 27) // Gyrados
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 130)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }

        else if(secondDiceroll == 28) // Lapras
        {
            for(i = 0; i < currentSize; i++)
            {
                if (allCards[i].GetPokeID() == 131)
                {
                    allCards[i].SetShiny(1);
                    allCards[i].SetGender(lottoNumber(2,1));  
                    allCards[i].SetValue(0); 
                    cout << " . . . ! Woah! This " << allCards[i].GetPokemonName() << " is shiny!!" << endl;
                    return allCards[i];
                }
            }
        }


    }

}
