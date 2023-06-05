CC=g++ -g -Wall 
all: Main
Main: main.o interface.o utils.o topology.o dvrp.o lsrp.o
	$(CC) main.o utils.o interface.o topology.o dvrp.o lsrp.o -o main.exe

dvrp.o: dvrp.cpp dvrp.hpp
	$(CC) -c dvrp.cpp -o dvrp.o -lstdc++

lsrp.o: lsrp.cpp lsrp.hpp
	$(CC) -c lsrp.cpp -o lsrp.o -lstdc++

main.o: main.cpp
	$(CC) -c main.cpp -o main.o -lstdc++ 

topology.o: topology.cpp
	$(CC) -c topology.cpp -o topology.o -lstdc++

interface.o: interface.cpp 
	$(CC) -c interface.cpp -o interface.o -lstdc++

utils.o: utils.cpp utils.hpp
	$(CC) -c utils.cpp -o utils.o -lstdc++

.PHONY: clean
clean:
	rm *.o 
	rm *.exe
	rm ./output/*
