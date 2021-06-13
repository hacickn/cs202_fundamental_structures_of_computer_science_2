/**
* Title: ChainHashTable Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: HashTable class to increase efficiency using hashing
*/

#include "ChainHashTable.h"

/**
 * It is a simple default constructor
 */
ChainHashTable::ChainHashTable() {
    size = 503;
}

/**
 * It is a deconstructor
 */
ChainHashTable::~ChainHashTable() {
    for(int a = 0; a < size; a++){
        if(!hashTable[a].isEmpty()){
            hashTable[a].remove(1);
        }
    }
}

/**
 * It inserts item into the hastTable by hashing item
 * @param item is the word which will be inserted
 * @param uniqueIndex is the item's unique index in matrix
 */
void ChainHashTable::insertItem(const string& item, int uniqueIndex) {
    int hashValue = hash(item);
    hashTable[hashValue].insert(Key(item, uniqueIndex));
}

/**
 * It is hashing the elements so that we can find elements faster
 * @param item is the string that is used in the hashing
 * @return is the hash value of the given item(string)
 */
int ChainHashTable::hash(const string& item) {
    int hashVal = 0;
    for(int i = 0; i < item.length(); i++){
        hashVal = 37 * hashVal + item[i];
    }

    hashVal %= size;
    if(hashVal < 0)
        hashVal += size;

    return hashVal;
}


/**
 * It returns index of the word which is necessary in matrices
 * @param word is the string whose index is wanted
 * @return int is the index of the given word
 */
int ChainHashTable::getWordsIndex(const string& word) {
    int hashValue = hash(word);

    return hashTable[hashValue].getIndexOfWord(word);
}

/**
 * It prints all hashTable. I used it whether My hashTable is working or not
 */
void ChainHashTable::printHash() const {
    for(int a = 0; a < size; a++){
        cout << a << "----"<<endl;
        KeyList current = hashTable[a];
        current.print();
    }
}

