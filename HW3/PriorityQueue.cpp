/*
* Title: PriorityQueue
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a PriorityQueue implementation that using the max heap
*/
#include "PriorityQueue.h"

/**
 * It a constructor that takes max size of the heap
 * @param maxSize is the max size
 */
PriorityQueue::PriorityQueue(int maxSize) {
    heap = new Heap(maxSize);
}

/**
 * It determines whether pq is empty or not
 * @return bool is the whether pq is empty or not
 */
bool PriorityQueue::pqIsEmpty() const {
    return heap->heapIsEmpty();
}

/**
 * It is a method that inserts the new object to pq
 * @param newItem is the request that will be inserted
 */
void PriorityQueue::pqInsert(const Request &newItem) {
    heap->heapInsert(newItem);
}

/**
 * It is a method that deletes the wanted object from the pq
 * @param priorityItem is the request object that will be deleted
 */
void PriorityQueue::pqDelete(Request &priorityItem) {
    heap->heapDelete(priorityItem);
}

/**
 * It is a method that gives first element of the pq
 * @return is the request object is at the beginning of pq
 */
Request & PriorityQueue::getPriorOne() {
    return heap->getHighestOne();
}