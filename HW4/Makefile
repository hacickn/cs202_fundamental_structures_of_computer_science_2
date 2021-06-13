
WordNetwork: main.o ChainHashTable.o Key.o KeyList.o WordNetwork.o
	g++ main.o ChainHashTable.o Key.o KeyList.o WordNetwork.o -o WordNetwork -std=c++11
	
main.o: main.cpp
	g++ -c main.cpp -std=c++11

ChainHashTable.o: ChainHashTable.cpp
	g++ -c ChainHashTable.cpp

Key.o: Key.cpp
	g++ -c Key.cpp

KeyList.o: KeyList.cpp
	g++ -c KeyList.cpp
	
WordNetwork.o: WordNetwork.cpp
	g++ -c WordNetwork.cpp

clean:
	rm *.o WordNetwork