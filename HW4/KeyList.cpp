/**
* Title: KeyList Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 4
* Description: KeyList class is a linkedList to use chain in the HashTable
*/

#include "KeyList.h"
#include "Key.h"

/**
 * It is a simple default constructor
 */
KeyList::KeyList() {
    size = 0;
    head = NULL;
}

/**
 * It is copy constructor with parameter
 * @param secondList is copied item
 */
KeyList::KeyList(const KeyList& secondList) {
    if(secondList.head == NULL){
        head = NULL;
        size = 0;
    }else{
        head = new ListNode;
        (*head).key = (*secondList.head).key;

        ListNode* newPtr = head;

        for (ListNode* ptr = (*secondList.head).next; ptr != NULL; ptr = (*ptr).next) {
            (*newPtr).next = new ListNode;
            newPtr = (*newPtr).next;
            (*newPtr).key = (*ptr).key;
        }
        (*newPtr).next = NULL;
        size = secondList.size;
    }
}


/**
 * It return whether list is empty or not
 * @return is the bool
 */
bool KeyList::isEmpty() const {
    return size == 0;
}

/**
 * It returns length of the list
 * @return is int which is length of the list
 */
int KeyList::getLength() const {
    return size;
}

/**
 * It inserts new item to list
 * @param key is the item that is wanted to insert
 * @return is the result of the process(in this case it always true in this hw)
 */
bool KeyList::insert(Key key) {

    ListNode* newPtr = new ListNode;
    size = getLength() + 1;
    int index = size ;
    (*newPtr).key = key;

    if (index == 1) {
        (*newPtr).next = head;
        head = newPtr;
    } else {
        ListNode* prev = find(index - 1);
        (*newPtr).next = (*prev).next;
        (*prev).next = newPtr;
    }
    return true;
}

/**
 * It deletes item from the list
 * @param index is the index of the item that will be deleted
 * @return is the result of the process
 */
bool KeyList::remove(int index) {
    ListNode* cur;

    if ((index < 1) || (index > getLength())) {
        return false;
    }

    size--;
    if (index == 1) {
        cur = head;
        head = head->next;
    } else {
        ListNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

/**
 * It is a simple deconstructor
 */
KeyList::~KeyList() {
    while (!isEmpty()) {
        remove(1);
    }
}

/**
 * It finds element of given index
 * @param index is the location of element
 * @return is the listNode which consist of the wanted element
 */
KeyList::ListNode * KeyList::find(int index) const {
    if ((index < 1) || (index > getLength())) {
        return NULL;
    } else {
        ListNode* cur = head;
        for (int skip = 1; skip < index; ++skip) {
            cur = (*cur).next;
        }
        return cur;
    }
}

/**
 * It returns word's index for the matrix
 * @param word is the word
 * @return int is the index of the word in matrix
 */
int KeyList::getIndexOfWord(const string word) {
    ListNode* current = head;
    while(current != NULL){
       if(current->key.getWord() == word){
           return current->key.getUniqueIndex();
       }
       current = current->next;
    }
    return -1;
}

/**
 * It prints linkedList. I used it to see whether my methods are working or not
 */
void KeyList::print() {
    ListNode* current = head;
    while(current != NULL){
        cout << current->key.getWord()<< endl;
        current = current->next;
    }
    cout << endl;
}