/*
 * Title: Binary Node
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 2
 * Description: this is a part of the Binary node cpp implementation.
 */
#include "BinaryNode.h"

BinaryNode::BinaryNode() {
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

BinaryNode::BinaryNode(const int& anItem) {
    item = anItem;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

BinaryNode::BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr) {
    item = anItem;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}

