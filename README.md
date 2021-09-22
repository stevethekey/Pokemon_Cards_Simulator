# Pokemon_Cards_Simulator
A card simulator game of the original Pokémon cards!

This program is something I made not really because I like Pokemon, but because I wanted to challenge myself and create a program over the summer to use as many programming
concepts I learned from the previous course I took at Florida State University. That course was data Structures I with genergic and object orientated programming.

This project consists of many classes, and they all work together. I started off with the class Pokemon. This class stores and handle details of a Pokemon like its name, ID, type, 
and its value (becaome some Pokemon cards are worth more than others!)

The second most imporant class is the PokeCards class. This is where I handled my data structure approach. In data structures I, we learn about dynamic memory allocated arrays before
vectors to help us understand what a vector is and how it works. So instead of using a vector in this project, I stuck with creating the memory allocated array as my data structure 
for this project. The dynamic memory allocated array is really just a pointer with the type Pokemon (the first class I made). This lets me put the memory address of a new Pokemon 
object in the array and I can reference them later because they are stored in the array. Most of the functions that enable gameplay are functions I built in this class. 
For example, sorting them into respective type of packs (fire pokemon in fire packs, water pokemon in water packs, etc.) occurs from a function I made in this class. The player
opening a pack is also caused by functions here.

There are other classes I made like player.h and packs.h, but the two most important are the Pokemon class and the PokeCard class- as these create the objects and stores 
them in a data structure, respectively. 
