#include <iostream>
#include "WordNetwork.h"
/**
* Title: Hw4 Main Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: It is a main class
*/
using namespace std;
int main() {
    WordNetwork wordNetwork("words_vertices.txt","words_edges.txt");
    cout << endl;
    wordNetwork.listNeighbors("roger");
    cout << endl;
    wordNetwork.listConnectedComponents();
    cout << endl;
    wordNetwork.listNeighbors("aided",2);
    //wordNetwork.findShortestPath("nodes","graph");
    return 0;
}
