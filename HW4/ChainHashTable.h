/**
* Title: ChainHashTable Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: HashTable class h file to increase efficiency using hashing in matrix operations
*/

#ifndef HW4_CHAINHASHTABLE_H
#define HW4_CHAINHASHTABLE_H
#include <string>
#include "KeyList.h"
#include <iostream>
using namespace std;

class ChainHashTable {

private:
    int size;
    KeyList hashTable[503];

    /**
     * It is hashing the elements so that we can find elements faster
     * @param item is the string that is used in the hashing
     * @return is the hash value of the given item(string)
     */
    int hash(const string &item);

public:
    /**
     * It is a simple default constructor
     */
    ChainHashTable();

    /**
     * It is a deconstructor
     */
    ~ChainHashTable();

    /**
     * It inserts item into the hastTable by hashing item
     * @param item is the word which will be inserted
     * @param uniqueIndex is the item's unique index in matrix
     */
    void insertItem(const string &item, int uniqueIndex);

    /**
     * It prints all hashTable. I used it whether My hashTable is working or not
     */
    void printHash() const;

    /**
     * It returns index of the word which is necessary in matrices
     * @param word is the string whose index is wanted
     * @return int is the index of the given word
     */
    int getWordsIndex(const string& word);

};


#endif //HW4_CHAINHASHTABLE_H
