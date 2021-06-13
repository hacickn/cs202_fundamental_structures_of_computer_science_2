
simulator: main.o Printer.o Request.o PriorityQueue.o Heap.o Simulator.o
	g++ main.o Printer.o Request.o PriorityQueue.o Heap.o Simulator.o -o simulator -std=c++11
	
main.o: main.cpp
	g++ -c main.cpp -std=c++11

Printer.o: Printer.cpp
	g++ -c Printer.cpp

Request.o: Request.cpp
	g++ -c Request.cpp

PriorityQueue.o:	PriorityQueue.cpp
	g++ -c PriorityQueue.cpp
	
Heap.o:	Heap.cpp
	g++ -c Heap.cpp

Simulator.o: Simulator.cpp
	g++ -c Simulator.cpp

clean:
	rm *.o simulator