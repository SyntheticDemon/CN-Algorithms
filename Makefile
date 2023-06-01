all: Main
Main: main.o interface.o utils.o topology.o dvrp.o
	g++ main.o utils.o interface.o topology.o dvrp.o -o main.exe

dvrp.o: dvrp.cpp 
	g++ -c dvrp.cpp -o dvrp.o -lstdc++

main.o: main.cpp
	g++ -c main.cpp -o main.o -lstdc++ 

topology.o: topology.cpp
	g++ -c topology.cpp -o topology.o -lstdc++

interface.o: interface.cpp 
	g++ -c interface.cpp -o interface.o -lstdc++

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp -o utils.o -lstdc++

.PHONY: clean
clean:
	rm *.o 
	rm *.exe