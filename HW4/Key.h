/**
* Title: Key Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: Key class is to use words and their indexex from oop perspective and it is used in linkedlist for chain hashing
*/

#ifndef HW4_KEY_H
#define HW4_KEY_H

#include <string>

using namespace std;

class Key {
private:
    string word;
    int uniqueIndex;

public:

    /**
    * It is a constructor with parameters
    * @param word is the string that will be keyword of the item
    * @param uniqueIndex is the int that is index of item in matrix
    */
    Key(const string& word, int uniqueIndex);

    /**
    * It is a simple default constructor
    */
    Key();

    /**
    * It is a simple getter for keyword properties
    * @return is the string
    */
    const string& getWord() const;

    /**
    * It is a simple setter for keyword properties
    * @param word is the string that will be changed
    */
    void setWord(const string& word);

    /**
    * It is a simple getter for index of words in matrices
    * @return is the int which is index of word
    */
    int getUniqueIndex() const;

    /**
    * It is a simple setter for index of words in matrices
    * @return is the int which is index of word
    */
    void setUniqueIndex(int uniqueIndex);
};


#endif //HW4_KEY_H
