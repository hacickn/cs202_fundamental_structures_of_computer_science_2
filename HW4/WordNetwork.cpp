/**
* Title: WordNetwork Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: WordNetwork class is to run operation on the graph
*/


#include "WordNetwork.h"

/**
 * It is a constructor with parameter
 * @param vertexFile is the file that contains vertex information
 * @param edgeFile is the file that contains edge information
 */
WordNetwork::WordNetwork(const string vertexFile, const string edgeFile) {
    string text = "";

    ifstream Vertex(vertexFile.c_str());
    ifstream Edge(edgeFile.c_str());

    int traceForVertex = 0;
    while (getline(Vertex, text)) {
        hashTable.insertItem(text.substr(0, 5), traceForVertex);
        traceForVertex++;
    }
    Vertex.close();
    words = new string[traceForVertex];


    ifstream VertexTwo(vertexFile.c_str());
    int traceForWords = 0;
    while (getline(VertexTwo, text)) {
        words[traceForWords] = text.substr(0, 5);
        traceForWords++;
    }
    VertexTwo.close();

    matrix = new int* [traceForVertex];
    for (int a = 0; a < traceForVertex; a++) {
        matrix[a] = new int[traceForVertex];
    }

    for (int a = 0; a < traceForVertex; a++) {
        for (int b = 0; b < traceForVertex; b++) {
            matrix[a][b] = -1;
        }
    }
    sizeOfMatrix = traceForVertex;

    string keywordOne;
    string keywordTwo;
    int keywordOneValue;
    int keywordTwoValue;
    int traceForEdges = 0;
    string delimiter = ",";
    int tempLoc;

    while (getline(Edge, text)) {
        tempLoc = text.find(delimiter);
        keywordOne = text.substr(0, tempLoc);
        keywordTwo = text.substr(tempLoc + 1, text.length() - tempLoc - 2);
        keywordOneValue = hashTable.getWordsIndex(keywordOne);
        keywordTwoValue = hashTable.getWordsIndex(keywordTwo);
        matrix[keywordOneValue][keywordTwoValue] = traceForEdges;
        matrix[keywordTwoValue][keywordOneValue] = traceForEdges;
        traceForEdges++;
    }

    Edge.close();
}

/**
 * It is a deconstructor
 */
WordNetwork::~WordNetwork() {
    for (int a = 0; a < sizeOfMatrix; a++) {
        delete[] matrix[a];
    }
    delete[] matrix;
    delete[] words;
}

/**
 * It shows the Neighbors of given word
 * @param word is the word whose Neighbors
 */
void WordNetwork::listNeighbors(const string word) {
    int keywordIndex = hashTable.getWordsIndex(word);

    if (keywordIndex == -1) {
        cout << "There is no word like " << word << endl;
    } else {
        cout << "Neighbors of " << word << endl;

        for (int a = 0; a < sizeOfMatrix; a++) {
            if (matrix[keywordIndex][a] != -1) {
                cout << words[a] << endl;
            }
        }
    }

}

/**
 * It shows the Neighbors of given word and given dsitance
 * @param word is the word whose Neighbors
 * @param distance is the distance that wanted
 */
void WordNetwork::listNeighbors(const string word, const int distance) {
    cout << "Neighbors of " << word << " in distance of " << distance << endl;
    bool* visited = new bool[sizeOfMatrix];
    for (int a = 0; a < sizeOfMatrix; a++) {
        visited[a] = false;
    }
    listNeighborsHelper(word, distance, visited);
    delete[] visited;
}


/**
 * It is a helper for neighbors method with distance
 * @param word is the word whose Neighbors
 * @param distance is the distance that wanted
 * @param visitList is the list that contains other words to count distance
 */
void WordNetwork::listNeighborsHelper(const string word, const int distance, bool* visitList) {
    if (distance == 0) {
        cout << word << endl;
    } else {
        int index = hashTable.getWordsIndex(word);
        visitList[index] = true;
        for (int a = 0; a < sizeOfMatrix; a++) {
            if (matrix[index][a] != -1 && !visitList[a]) {
                listNeighborsHelper(words[a], distance - 1, visitList);
            }
        }
    }
}


/**
 * It shows component words all together
 */
void WordNetwork::listConnectedComponents() {
    bool* isVisited = new bool[sizeOfMatrix];
    for (int a = 0; a < sizeOfMatrix; a++) {
        isVisited[a] = false;
    }
    int trace = 1;

    for (int a = 0; a < sizeOfMatrix; a++) {
        if (!isVisited[a]) {
            cout << "Connected compenent " << trace << endl;
            trace++;
            visit(a, isVisited);
            cout << endl;
        }
    }

    delete[] isVisited;
}

/**
 * It visits words
 * @param index is the current index
 * @param visitList is the list that saves previous matches
 */
void WordNetwork::visit(int index, bool* visitList) {
    visitList[index] = true;
    cout << words[index] << endl;
    for (int a = 0; a < sizeOfMatrix; a++) {
        if (matrix[index][a] != -1 && !visitList[a]) {
            visit(a, visitList);
        }
    }
}

/**
 * It find shortest path between two word
 * @param word1 is the location that is start point
 * @param word2 is the locaiton that is end point
 */
void WordNetwork::findShortestPath(const string word1, const string word2) {
    int path = 0;
    int minPath = sizeOfMatrix;
    int minPathArray[sizeOfMatrix];
    int pathArray[sizeOfMatrix];
    bool visited[sizeOfMatrix];
    for (int a = 0; a < sizeOfMatrix; a++) {
        minPathArray[a] = -1;
        pathArray[a] = -1;
        visited[a] = false;
    }

    int loc = hashTable.getWordsIndex(word1);
    int target = hashTable.getWordsIndex(word2);

}

/**
 * It prints all the matrix, I used it whether my methods are working or not
 */
void WordNetwork::printMatrix() {
    cout << "x- ";
    for (int a = 0; a < 5757; a++) {
        cout << a << " ";
    }
    cout << endl;
    for (int a = 0; a < 5757; a++) {
        cout << a << "- ";
        for (int b = 0; b < 5757; b++) {
            cout << matrix[a][b] << " ";
        }
        cout << endl;
    }
}