#include "pokemon.h"

Pokemon::Pokemon()
{
    pokeName = "Zero";
    pokeID = 0;
    pokeType = "None";
    pokeType2 = "None";
    pokeGender = 0; // 0 = n/a, 1= male, 2 = female, 
    pokeShiny = 0;  //  0 = not shiny, 1 = shiny
    pokeValue = 0; 
    
}

Pokemon::Pokemon(string pName, int pID, string pType, string pType2, short int pGender, short int pShiny, double pValue)
{
    SetPokemonName(pName);
    SetPokeID(pID);
    SetType(pType);
    SetSecondaryType(pType2);
    SetGender(pGender);
    SetShiny(pShiny);
    SetValue(pValue);
}

ostream& operator<< (ostream& os, const Pokemon& x)
{   
    os << "\n\t" << x.GetPokemonName();

    for (short int j = (x.GetPokemonName()).length(); j < 25; j++)
    {
        cout.put(' ');
    }

    cout << x.GetType();

    for (short int j = (x.GetType()).length(); j < 25; j++)
    {
        cout.put(' ');
    }

    cout << x.GetPokeID();

    short int counter=0, dummyHolder;

    dummyHolder = x.GetPokeID();

    while(dummyHolder != 0)
    {
        dummyHolder  = dummyHolder / 10;
        counter++;
    }

    for(short int j = counter; j < 25; j++)
    {
        cout.put(' ');
    }

    string girlOrboy;
    if(x.GetGender()==0)
    {
        girlOrboy = "N/A";
    }
    else if(x.GetGender()== 1)
    {
        girlOrboy = "Male";
    }
    else if(x.GetGender()==2)
    {
        girlOrboy = "Female";
    }

    cout << girlOrboy;

    for(short int j = girlOrboy.length(); j <25; j++)
    {
        cout.put(' ');
    }

    string yesOrno;
    if(x.GetShiny() == 1)
    {
        yesOrno = "YES!!";
    }
    else
    {
        yesOrno = "No";
    }

    cout << yesOrno;

    for(short int j = yesOrno.length(); j < 23; j++)
    {
        cout.put(' ');
    }

    int oldPrecision = cout.precision(); //captures the default amount of precisions. i will use this to return the settings to this value
                             
    cout.setf(ios::fixed);          //tells complier that numbers on output needs to be printed with decimals by setting a flag named fixed
    cout.precision(2);              //tells complier that the number of precision (deci values) is 2. i.e., 13.23, 25.00, 113.21, etc.

    cout << '$' << x.GetValue();           //complier shows a number with the two rules from above. so, 25-> 25.00, 13.75->13.75, 8.2-> 8.20, etc.

    cout.precision(oldPrecision);   //takes default precision and passes it in the parameter to restore things to the way it was
    cout.unsetf(ios::fixed);        //unsets the flag that made numbers be printed in fixed notation


    /*
    Q: why bother restoring things back to the way it was? Reason: after you set a flag or alter precision, it is permanent. meaning the settings will
    continue to appear in other parts of the program. i.e., if user's age is 12, it would show 12.00 on the output screen. 
    so to make things normal, i restore things the way it was after i am done
    */    
    return os;
}

//setter functions below

void Pokemon::SetPokemonName(string pName)
{
    pokeName = pName;
}
void Pokemon::SetPokeID(int pID )
{
    pokeID = pID;
}
void Pokemon::SetType(string pType)
{
    pokeType = pType;
}

void Pokemon::SetSecondaryType(string pType2)
{
    pokeType2 = pType2;
}


void Pokemon::SetGender(short pGender)
{
    pokeGender = pGender;
}

void Pokemon::SetShiny(short int pShiny)
{
    pokeShiny = pShiny;
}

void Pokemon::SetValue(double pValue)   
{   
    if(pValue == 0)
    {
        if(GetType()=="Fire")
        {
            switch(GetPokeID())
            {
                //common
                case 37: pokeValue = 50; break;
                case 58: pokeValue = 18.70; break;
                case 59: pokeValue = 25; break;
                case 77: pokeValue = 6.50; break;

                //uncommon 
                case 4: pokeValue = 200; break;
                case 5: pokeValue = 83.93; break;
                case 78: pokeValue = 110.25; break;
                case 136: pokeValue = 95; break;
                //epic
                case 6: pokeValue = 30000; break;
                case 38: pokeValue = 620.36; break;
                case 126: pokeValue = 1000.11; break;
                case 146: pokeValue = 500000; break;
            }
        }
        else if(GetType()=="Water")
        {
            switch(GetPokeID())
            {
                //common water pokemon
                case 72: pokeValue = 25.00; break;
                case 79: pokeValue = 37.50; break;
                case 86: pokeValue = 20.00; break;
                case 90: pokeValue = 8; break;
                case 98: pokeValue = 5.00; break;
                
                case 116: pokeValue = 15.00; break;
                case 118: pokeValue = 5.25; break;
                case 120: pokeValue = 10.00; break;
                case 129: pokeValue = 0.01; break;

                //uncommon water pokemon
                case 7: pokeValue = 200; break;
                case 8: pokeValue = 87.42;
                case 54: pokeValue = 55; break;
                case 73: pokeValue = 51; break;
                case 80: pokeValue = 85.50; break;
                case 87: pokeValue = 200; break;
                case 91: pokeValue = 60.13; break;
                case 99: pokeValue = 55; break;
                case 119: pokeValue = 51; break;
                case 121: pokeValue = 100; break;
                case 134: pokeValue = 95; break;
                case 61: pokeValue = 150; break;

                //epic water pokemon
                case 55: pokeValue = 300; break;
                case 62: pokeValue = 1000; break;
                case 117: pokeValue = 500; break;
                case 130: pokeValue = 50000; break;
                case 131: pokeValue = 25000; break;
            }
        }

        else if(GetType()=="Grass")
        {
            switch(GetPokeID())
            {
                //common
                case 102: pokeValue = 3;
                case 69: pokeValue = 10;
                case 43: pokeValue = 25;
                //uncommon
                case 70: pokeValue = 55;
                case 44: pokeValue = 60;
                case 1: pokeValue = 75;
                case 2: pokeValue = 100;
                //epic
                case 3: pokeValue = 50000;
                case 45: pokeValue = 210;
                case 114: pokeValue = 2000;
                case 103: pokeValue = 25000;
                case 71: pokeValue= 800;
            }
        }
        

    }

    if(pValue != 0)     //this means i have special plans for the value of that pokemon object
    {
        pokeValue = pValue;
    }

    if(GetShiny()==1)
    {
        pokeValue+= pokeValue*10,000;   //yep. if bulbasaur = $50, and it is shiny, then 50 + 50*10,000 = $500,050
    }
}

// getter functions below

string Pokemon::GetPokemonName() const
{
    return pokeName;
}

int Pokemon::GetPokeID() const
{
    return pokeID;
}

string Pokemon::GetType() const
{
    return pokeType;
}

string Pokemon::GetSecondaryType() const
{
    return pokeType2;
}


short int Pokemon::GetGender() const
{
    return pokeGender;
}

short int Pokemon::GetShiny() const
{
    return pokeShiny;
}

double Pokemon::GetValue() const
{
    return pokeValue;
}



