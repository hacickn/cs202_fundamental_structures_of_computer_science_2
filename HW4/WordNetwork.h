/**
* Title: WordNetwork Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: WordNetwork class is to run operation on the graph
*/

#ifndef HW4_WORDNETWORK_H
#define HW4_WORDNETWORK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "ChainHashTable.h"

using namespace std;

class WordNetwork {
public:
    /**
     * It is a constructor with parameter
     * @param vertexFile is the file that contains vertex information
     * @param edgeFile is the file that contains edge information
     */
    WordNetwork(const string vertexFile, const string edgeFile);

    /**
     * It is a deconstructor
     */
    ~WordNetwork();

    /**
     * It shows the Neighbors of given word
     * @param word is the word whose Neighbors
     */
    void listNeighbors(const string word);

    /**
     * It shows the Neighbors of given word and given dsitance
     * @param word is the word whose Neighbors
     * @param distance is the distance that wanted
     */
    void listNeighbors(const string word, const int distance);

    /**
     * It is a helper for neighbors method with distance
     * @param word is the word whose Neighbors
     * @param distance is the distance that wanted
     * @param visitList is the list that contains other words to count distance
     */
    void listNeighborsHelper(const string word, const int distance, bool visitList[]);

    /**
     * It shows component words all together
     */
    void listConnectedComponents();

    /**
     * It find shortest path between two word
     * @param word1 is the location that is start point
     * @param word2 is the locaiton that is end point
     */
    void findShortestPath(const string word1, const string word2);

    /**
     * It prints all the matrix, I used it whether my methods are working or not
     */
    void printMatrix();

    /**
     * It visits words
     * @param index is the current index
     * @param visitList is the list that saves previous matches
     */
    void visit(int index, bool visitList[]);

private:
    int** matrix;
    ChainHashTable hashTable;
    int sizeOfMatrix;
    string* words;
};


#endif //HW4_WORDNETWORK_H
