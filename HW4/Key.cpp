/**
* Title: Key Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: Key class is to use words and their indexex from oop perspective and it is used in linkedlist for chain hashing
*/

#include "Key.h"

/**
 * It is a simple getter for keyword properties
 * @return is the string
 */
const string& Key::getWord() const {
    return word;
}

/**
 * It is a simple setter for keyword properties
 * @param word is the string that will be changed
 */
void Key::setWord(const string& word) {
    Key::word = word;
}

/**
 * It is a simple getter for index of words in matrices
 * @return is the int which is index of word
 */
int Key::getUniqueIndex() const {
    return uniqueIndex;
}

/**
 * It is a simple setter for index of words in matrices
 * @return is the int which is index of word
 */
void Key::setUniqueIndex(int uniqueIndex) {
    Key::uniqueIndex = uniqueIndex;
}

/**
 * It is a constructor with parameters
 * @param word is the string that will be keyword of the item
 * @param uniqueIndex is the int that is index of item in matrix
 */
Key::Key(const string& word, int uniqueIndex) {
    this->word = word;
    this->uniqueIndex = uniqueIndex;
}

/**
 * It is a simple default constructor
 */
Key::Key() {
    word = "";
    uniqueIndex = -1;
}

