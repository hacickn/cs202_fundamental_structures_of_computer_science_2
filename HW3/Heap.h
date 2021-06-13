/*
* Title: Heap
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a heap h file implementation
*/

#ifndef HW3_HEAP_H
#define HW3_HEAP_H
#include <iostream>
#include "Request.h"

using namespace std;
class Heap {
private:
    Request *requests;
    int currentSize;
    int maxSize;
protected:
    void heapRebuild(int root);
public:
    Heap(int maxSize);
    bool heapIsEmpty() const;
    void heapInsert(const Request& newItem);
    void heapDelete(Request& rootItem);
    Request& getHighestOne();
};


#endif //HW3_HEAP_H
