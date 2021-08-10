run: pokemon.o menu.o packs.o pokecards.o player.o
	g++ -o run pokemon.o menu.o pokecards.o packs.o player.o

pokemon.o: pokemon.cpp pokemon.h
	g++ -c pokemon.cpp

menu.o: menu.cpp menu.h
	g++ -c menu.cpp

packs.o: packs.cpp packs.h
	g++ -c packs.cpp

pokecards.o: pokecards.cpp pokecards.h
	g++ -c pokecards.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

clean:
	rm -f *.o