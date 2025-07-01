a.out: main.o Node.o Graph.out

main.o: main.cpp Node.h Graph.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Graph.out: Graph.cpp Graph.h Node.h
	g++ -c Graph.cpp

