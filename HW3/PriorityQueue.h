/*
* Title: PriorityQueue
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a PriorityQueue h file implementation
*/

#ifndef HW3_PRIORITYQUEUE_H
#define HW3_PRIORITYQUEUE_H
#include "Heap.h"
#include "Request.h"

class PriorityQueue {
private:
    Heap *heap;
public:
    PriorityQueue(int maxSize);
    bool pqIsEmpty() const;
    Request& getPriorOne();
    void pqInsert(const Request& newItem);
    void pqDelete(Request& priorityItem);
};


#endif //HW3_PRIORITYQUEUE_H
