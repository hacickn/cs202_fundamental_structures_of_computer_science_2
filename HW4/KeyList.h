//
// Created by Hacı Çakın on 12.05.2021.
//
/**
* Title: KeyList Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: KeyList class is a linkedList to use chain in the HashTable
*/

#ifndef HW4_KEYLIST_H
#define HW4_KEYLIST_H
#include <string>
#include "Key.h"
#include <iostream>
#include <cstddef>
using namespace std;

typedef Key Key;

class KeyList {

public:
    /**
     * It is a simple default constructor
     */
    KeyList();

    /**
     * It is copy constructor with parameter
     * @param secondList is copied item
     */
    KeyList(const KeyList& secondList);

    /**
     * It is a simple deconstructor
     */
    ~KeyList();

    /**
     * It return whether list is empty or not
     * @return is the bool
     */
    bool isEmpty() const;

    /**
     * It returns length of the list
     * @return is int which is length of the list
     */
    int getLength() const;

    /**
     * It inserts new item to list
     * @param key is the item that is wanted to insert
     * @return is the result of the process(in this case it always true in this hw)
     */
    bool insert( Key key);

    /**
     * It deletes item from the list
     * @param index is the index of the item that will be deleted
     * @return is the result of the process
     */
    bool remove(int index);

    /**
     * It returns word's index for the matrix
     * @param word is the word
     * @return int is the index of the word in matrix
     */
    int getIndexOfWord(const string word);

    /**
     * It prints linkedList. I used it to see whether my methods are working or not
     */
    void print();
private:


    struct ListNode{
        Key key;
        ListNode* next;
    };

    int size;
    ListNode* head;
    /**
     * It finds element of given index
     * @param index is the location of element
     * @return is the listNode which consist of the wanted element
     */
    ListNode* find(int index) const;
};


#endif //HW4_KEYLIST_H
