CC = g++
CFLAGS = -std=c++2a -Ox

dna_filter: main.o cell.o
	$(CC) $(CFLAGS) -o dna_filter main.o cell.o

main.o: main.cpp cell.o

cell.o: cell.cpp cell.hpp