/*
 * Title: Binary Search Trees
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 2
 * Description: this is a part of the Binary search tree which is a h file.
 */
#ifndef CS202_HW2_BINARYSEARCHTREE_H
#define CS202_HW2_BINARYSEARCHTREE_H

#include <iostream>
#include "BinaryNode.h"

using namespace std;

/**
 * It is a BinarySearchTree class to perform BST operations
 */
class BinarySearchTree {
private:
    BinaryNode* root;
protected:

    /**
     * It is an insert method that added value to suitable place
     * @param subTreePtr is the current tree
     * @param newNode is the value that will be added
     * @return BinaryNode is the node that is added
     */
    BinaryNode* insertInorder(BinaryNode*& subTreePtr,
                              int newNode);

    /**
     * It is a removeValue method to help the removing. It finds the location of the node that will be deleted
     * @param subTreePtr is the current tree
     * @param target is the value that will be deleted
     * @param success is the result of deletion
     * @return BinaryNode is the node that will be deleted which is NULL
     */
    BinaryNode* removeValue(BinaryNode*& subTreePtr,
                            const int target, bool& success);

    /**
     * It is helper for the removing which deletes the node without breaking BST rules
     * @param nodePtr is the node that will be deleted
     * @return BinaryNode is the node that will be deleted which is NULL
     */
    BinaryNode* removeNode(BinaryNode*& nodePtr);

    /**
     * It is a method to find the successor of the deleted item to palace it to deleted item location
     * @param keyItem is the value of the successor
     * @param node is the current node
     */
    void processLeftMost(int& keyItem, BinaryNode*& node);

    /**
     * It is to find node which is value is desired
     * @param treePtr is the current tree
     * @param target is the value of the target
     * @return BinaryNode is the node whose value is equal to target(if not then it is NULL)
     */
    BinaryNode* findNode(BinaryNode* treePtr, const int& target) const;

public:
    /**
     * It is default constructor of the BST
     */
    BinarySearchTree();

    /**
     * It is an overloaded constructor which takes root item value
     * @param rootItem is the root value
     */
    BinarySearchTree(const int& rootItem);

    /**
     * It is a deconstructer to delete BST
     */
    ~BinarySearchTree();

    /**
     * It is a method that says whether BST is empty or not
     * @return bool is the answer of is Empty?
     */
    bool isEmpty() const;

    /**
     * It is a method that gives height of the tree
     * @return int is the height of the tree
     */
    int getHeight() const;

    /**
     * It is a helper method to find height of the tree which works recursively
     * @param node is the current node
     * @return int is the current maximum
     */
    int getHeight(BinaryNode* node) const;

    /**
     * It is a method to find number of nodes that is in the BST
     * @return int is the number of nodes
     */
    int getNumberOfNodes() const;

    /**
     * It is a helper method to find number of the nodes which works recursively
     * @param node is the current node
     * @return int is the current node number
     */
    int getNumberOfNodes(BinaryNode* node) const;

    /**
     * It is for adding new element to BST
     * @param newEntry is the value of new element
     * @return bool is the result of addition
     */
    bool add(const int& newEntry);

    /**
     * It is for removing element from the list
     * @param anEntry is the value that will be deleted
     * @return bool is the result of deletion
     */
    bool remove(const int& anEntry);

    /**
     * It is for checking whether value is exist or not
     * @param anEntry is the value that will be checked
     * @return bool is the result of existence
     */
    bool contains(const int& anEntry) const;

    /**
     * It is a method to print BST in preorder
     */
    void preorderTraverse() const;

    /**
     * It is a helper method to print BST in preorder which works recursively
     * @param node is the current node
     */
    void preorderTraverse(BinaryNode* node) const;

    /**
     * It is a method to print BST in inorder
     */
    void inorderTraverse() const;

    /**
    * It is a helper method to print BST in inorder which works recursively
    * @param node is the current node
    */
    void inorderTraverse(BinaryNode* node) const;

    /**
     * It is a method to print BST in postorder
     */
    void postorderTraverse() const;

    /**
    * It is a helper method to print BST in postorder which works recursively
    * @param node is the current node
    */
    void postorderTraverse(BinaryNode* node) const;

    /**
     * It is a method to print BST in level order
     */
    void levelorderTraverse();

    /**
    * It is a helper method to print BST in postorder which works recursively
    * @param node is the current node
    * @param level is the current level of the tree
    */
    void levelorderTraverse(BinaryNode* node, int level);

    /**
     * It is a helper method works recursively to calculate how many values in range a-b
     * @param node is the current node
     * @param min is the minimum value
     * @param max is the maximum value
     * @return int is the current number of values which are in this range
     */
    int span(BinaryNode* node, const int min, const int max);

    /**
     * It is a method to calculate how many values in range a-b
     * @brief It visits exactly same with the result
     * @param a is the minimum value
     * @param b is the maximum value
     * @return int is the total number of the values which are in this range
     */
    int span(const int a, const int b);

    /**
     * It is a method that takes mirror of the BST
     * It works recursively and it start to replace from the leaves(which is a result of recursion).
     * Then It goes to up and change to main subtree(All levels are replaced).
     */
    void mirror();

    /**
     * It is a helper method to takes mirror of the BST
     * @param node is the current node
     */
    void mirror(BinaryNode* node);

};

#endif //CS202_HW2_BINARYSEARCHTREE_H
