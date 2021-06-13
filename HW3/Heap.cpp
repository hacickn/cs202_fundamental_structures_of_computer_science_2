/*
* Title: Heap
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a heap implementation
*/

#include "Heap.h"

/**
 * It is heap constructor with max size parameter
 * @param maxSize is the maximum size of the list
 */
Heap::Heap(int maxSize) {
    requests = new Request[maxSize];
    currentSize = 0;
    this->maxSize = maxSize;
}

/**
 * It is a method that shows whether heap is empty or not
 * @return bool is the emptiness of the heap
 */
bool Heap::heapIsEmpty() const {
    return currentSize == 0;
}

/**
 * It inserts new request to heap according to priority
 * @param newItem is the item that will be inserted
 */
void Heap::heapInsert(const Request& newItem) {
    if (currentSize < maxSize) {
        requests[currentSize] = newItem;
        int place = currentSize++;
        int parent = (place - 1) / 2;

        while ((place > 0 && requests[place].getPriority() > requests[parent].getPriority()) ||
               (place > 0 && requests[place].getPriority() == requests[parent].getPriority() &&
                requests[place].getArrivalTime() < requests[parent].getArrivalTime())) {
            Request temp = requests[parent];
            requests[parent] = requests[place];
            requests[place] = temp;
            place = parent;
            parent = (place - 1) / 2;
        }
    }
}

/**
 * It deletes the request from the heap
 * @param rootItem is the item that will be deleted
 */
void Heap::heapDelete(Request& rootItem) {
    if (heapIsEmpty()) {
        return;
    }
    rootItem.setId(requests[0].getId());
    rootItem.setPriority(requests[0].getPriority());
    rootItem.setTimeTaken(requests[0].getTimeTaken());
    rootItem.setArrivalTime(requests[0].getArrivalTime());
    requests[0] = requests[--currentSize];
    heapRebuild(0);
}

/**
 * It rebuilds the heap after deletions or additions
 * @param root is the root of the heap where algorithm starts
 */
void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;

    if (child < currentSize) {
        int rightChild = child + 1;

        if ((rightChild < currentSize && requests[rightChild].getPriority() > requests[child].getPriority()) ||
            (rightChild < currentSize && requests[rightChild].getPriority() == requests[child].getPriority() &&
             requests[rightChild].getArrivalTime() < requests[child].getArrivalTime())) {
            // assign right child.
            child = rightChild;
        }
        if ((requests[child].getPriority() > requests[root].getPriority()) ||
            (requests[child].getPriority() == requests[root].getPriority() &&
             requests[child].getArrivalTime() < requests[root].getArrivalTime())) {
            // swap nodes.
            Request temp = requests[child];
            requests[child] = requests[root];
            requests[root] = temp;
            heapRebuild(child);
        }
    }
}

/**
 * It is the method that gives item that has highest priority
 * @return Request is the request object.
 */
Request & Heap::getHighestOne() {
    return requests[0];
}