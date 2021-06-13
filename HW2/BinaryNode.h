/*
 * Title: Binary Node
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 2
 * Description: this is a part of the Binary node which is h file.
 */

#ifndef CS202_HW2_BINARYNODE_H
#define CS202_HW2_BINARYNODE_H

#include <iostream>

/**
 * It is a BinaryNode class to use it in BST
 */
class BinaryNode {
public:
    int item;
    BinaryNode* leftChildPtr;
    BinaryNode* rightChildPtr;

    /**
     * It is a default constructor of binaryNode, it gives 0 to item
     */
    BinaryNode();

    /**
     * It is an overloaded constructor which gives item value
     * @param anItem is the item value
     */
    BinaryNode(const int& anItem);

    /**
     * It is an overloaded constructor which has all the possible values
     * @param anItem is the item value
     * @param leftPtr is the left child of the node
     * @param rightPtr is the right child of the node
     */
    BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr);
};


#endif //CS202_HW2_BINARYNODE_H
