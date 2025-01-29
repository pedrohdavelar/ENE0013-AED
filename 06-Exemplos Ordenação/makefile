all: ordenaarrays

busca.o: busca.cpp busca.h
	g++ -std=c++17 -Wall -c busca.cpp

sort.o: sort.cpp sort.h
	g++ -std=c++17 -Wall -c sort.cpp

ordenaarrays.o: sort.h busca.h ordenaarrays.cpp
	g++ -std=c++17 -Wall -c ordenaarrays.cpp

ordenaarrays: ordenaarrays.o busca.o sort.o
	g++ -std=c++17 -Wall -o ordenaarrays ordenaarrays.o busca.o sort.o