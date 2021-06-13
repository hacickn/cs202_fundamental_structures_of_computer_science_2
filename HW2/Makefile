# Make file to compile source code

CC=g++
CFLAGS=-c -Wall

all: hw

hw: main.o BinarySearchTree.o BinaryNode.o 
	$(CC) main.o BinarySearchTree.o BinaryNode.o -o 21802641_hw2


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CC) $(CFLAGS) BinarySearchTree.cpp

BinaryNode.o: BinaryNode.cpp
	$(CC) $(CFLAGS) BinaryNode.cpp

clean:
	rm *o 21802641_hw2