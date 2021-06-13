/*
 * Title: Binary Search Trees
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 2
 * Description: this is a part of the Binary search tree cpp implementation
 */

#include "BinarySearchTree.h"

/**
 * It is default constructor of the BST
 */
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

/**
  * It is an overloaded constructor which takes root item value
  * @param rootItem is the root value
  */
BinarySearchTree::BinarySearchTree(const int& rootItem) {
    root = new BinaryNode(rootItem);
}

/**
 * It is a deconstructer to delete BST
 */
BinarySearchTree::~BinarySearchTree() {
    removeNode(root);
}

/**
 * It is an insert method that added value to suitable place
 * @param subTreePtr is the current tree
 * @param newNode is the value that will be added
 * @return BinaryNode is the node that is added
 */
BinaryNode* BinarySearchTree::insertInorder(BinaryNode*& subTreePtr, int newNode) {
    if (!subTreePtr) {
        subTreePtr = new BinaryNode(newNode, NULL, NULL);
        return subTreePtr;
    } else {
        BinaryNode* temp;
        if (newNode < subTreePtr->item) {

            temp = insertInorder(subTreePtr->leftChildPtr, newNode);

        } else if (newNode > subTreePtr->item) {

            temp = insertInorder(subTreePtr->rightChildPtr, newNode);

        } else {
            return NULL;
        }
        return temp;
    }
}

/**
 * It is to find node which is value is desired
 * @param treePtr is the current tree
 * @param target is the value of the target
 * @return BinaryNode is the node whose value is equal to target(if not then it is NULL)
 */
BinaryNode* BinarySearchTree::findNode(BinaryNode* treePtr, const int& target) const {
    if (treePtr == NULL) {
        return NULL;
    } else if (treePtr->item == target) {
        return treePtr;
    } else {
        BinaryNode* node;
        if (treePtr->item > target) {
            node = findNode(treePtr->leftChildPtr, target);
        } else if (treePtr->item < target) {
            node = findNode(treePtr->rightChildPtr, target);
        }
        return node;
    }
}

/**
 * It is a method to find the successor of the deleted item to palace it to deleted item location
 * @param keyItem is the value of the successor
 * @param node is the current node
 */
void BinarySearchTree::processLeftMost(int& keyItem, BinaryNode*& node) {
    if (!(node->leftChildPtr)) {
        // found the in order successor
        keyItem = node->item;
        // delete the node
        delete node;
        node = NULL; // safe-check
    } else {
        // recurse left
        processLeftMost(keyItem, node->leftChildPtr);
    }
}

/**
 * It is helper for the removing which deletes the node without breaking BST rules
 * @param nodePtr is the node that will be deleted
 * @return BinaryNode is the node that will be deleted which is NULL
 */
BinaryNode* BinarySearchTree::removeNode(BinaryNode*& nodePtr) {
    if ((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)) {
        delete nodePtr;
        nodePtr = NULL;
    } else if (nodePtr->leftChildPtr == NULL) {
        // Case 2) node has only the right child
        // copy the value to current node
        nodePtr->item = nodePtr->rightChildPtr->item;
        // deallocate the left child
        delete nodePtr->rightChildPtr;
        nodePtr->rightChildPtr = NULL;
    } else if (nodePtr->rightChildPtr == NULL) {
        // Case 2) node has only the left child
        // copy the value to current node
        nodePtr->item = nodePtr->leftChildPtr->item;

        // deallocate the left child
        delete nodePtr->leftChildPtr;
        nodePtr->leftChildPtr = NULL;
    } else {
        // Case 3) node has 2 children
        // helper function to deal with 2 children case
        // Find the in order succsessor
        int keyItem = -1;
        processLeftMost(keyItem, nodePtr->rightChildPtr);
        nodePtr->item = keyItem;// write back the value obtained
    }
}

/**
 * It is a removeValue method to help the removing. It finds the location of the node that will be deleted
 * @param subTreePtr is the current tree
 * @param target is the value that will be deleted
 * @param success is the result of deletion
 * @return BinaryNode is the node that will be deleted which is NULL
 */
BinaryNode* BinarySearchTree::removeValue(BinaryNode*& subTreePtr, const int target, bool& success) {
    if (subTreePtr == NULL) {
        success = false;
    } else {
        if (subTreePtr->item == target) {
            removeNode(subTreePtr);
            success = true;
        } else if (subTreePtr->item > target) {
            removeValue(subTreePtr->leftChildPtr, target, success);
        } else {
            removeValue(subTreePtr->rightChildPtr, target, success);
        }
    }
    return NULL;
}

/**
 * It is a method that says whether BST is empty or not
 * @return bool is the answer of is Empty?
 */
bool BinarySearchTree::isEmpty() const {
    return (root == NULL);
}

/**
 * It is a method that gives height of the tree
 * @return int is the height of the tree
 */
int BinarySearchTree::getHeight() const {
    return getHeight(root);
}

/**
 * It is a helper method to find height of the tree which works recursively
 * @param node is the current node
 * @return int is the current maximum
 */
int BinarySearchTree::getHeight(BinaryNode* node) const {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + max(getHeight(node->rightChildPtr), getHeight(node->leftChildPtr));
    }
}

/**
 * It is for adding new element to BST
 * @param newEntry is the value of new element
 * @return bool is the result of addition
 */
bool BinarySearchTree::add(const int& newEntry) {
    BinaryNode* tempNode = insertInorder(root, newEntry);
    if (tempNode == NULL) {
        return false;
    } else {
        return true;
    }
}

/**
 * It is for checking whether value is exist or not
 * @param anEntry is the value that will be checked
 * @return bool is the result of existence
 */
bool BinarySearchTree::contains(const int& anEntry) const {
    BinaryNode* temp = findNode(root, anEntry);
    if (temp == NULL) {
        return false;
    }
    return true;
}

/**
 * It is a method to find number of nodes that is in the BST
 * @return int is the number of nodes
 */
int BinarySearchTree::getNumberOfNodes() const {
    return getNumberOfNodes(root);
}

/**
 * It is a helper method to find number of the nodes which works recursively
 * @param node is the current node
 * @return int is the current node number
 */
int BinarySearchTree::getNumberOfNodes(BinaryNode* node) const {
    if (node != NULL) {
        return 1 + getNumberOfNodes(node->leftChildPtr) + getNumberOfNodes(node->rightChildPtr);
    } else {
        return 0;
    }
}

/**
 * It is a method to print BST in inorder
 */
void BinarySearchTree::inorderTraverse() const {
    if (isEmpty()) {
        cout << "Empty" << endl;
    } else {
        inorderTraverse(root);
        cout << endl;
    }
}

/**
 * It is a helper method to print BST in inorder which works recursively
 * @param node is the current node
 */
void BinarySearchTree::inorderTraverse(BinaryNode* node) const {
    if (node == NULL) {
        return;
    }
    inorderTraverse(node->leftChildPtr);
    cout << node->item << " ";
    inorderTraverse(node->rightChildPtr);
}

/**
 * It is a method to print BST in postorder
 */
void BinarySearchTree::postorderTraverse() const {
    if (isEmpty()) {
        cout << "Empty" << endl;
    } else {
        postorderTraverse(root);
        cout << endl;
    }
}

/**
* It is a helper method to print BST in postorder which works recursively
* @param node is the current node
*/
void BinarySearchTree::postorderTraverse(BinaryNode* node) const {
    if (node == NULL) {
        return;
    }
    postorderTraverse(node->leftChildPtr);
    postorderTraverse(node->rightChildPtr);
    cout << node->item << " ";
}

/**
 * It is a method to print BST in preorder
 */
void BinarySearchTree::preorderTraverse() const {
    if (isEmpty()) {
        cout << "Empty" << endl; // tree empty
    } else {
        preorderTraverse(root);
        cout << endl;
    }
}

/**
 * It is a helper method to print BST in preorder which works recursively
 * @param node is the current node
 */
void BinarySearchTree::preorderTraverse(BinaryNode* node) const {
    if (node == NULL) {
        return;
    }
    cout << node->item << " ";
    preorderTraverse(node->leftChildPtr);
    preorderTraverse(node->rightChildPtr);
}


/**
 * It is a method to print BST in level order
 */
void BinarySearchTree::levelorderTraverse() {
    for (int a = 1; a <= getHeight(); a++) {
        levelorderTraverse(root, a);
    }
    cout << endl;
}

/**
* It is a helper method to print BST in postorder which works recursively
* @param node is the current node
* @param level is the current level of the tree
*/
void BinarySearchTree::levelorderTraverse(BinaryNode* node, int level) {

    if (node == NULL)
        return;
    if (level == 1)
        cout << node->item << " ";
    else if (level > 1) {
        levelorderTraverse(node->leftChildPtr, level - 1);
        levelorderTraverse(node->rightChildPtr, level - 1);
    }
}

/**
 * It is for removing element from the list
 * @param anEntry is the value that will be deleted
 * @return bool is the result of deletion
 */
bool BinarySearchTree::remove(const int& anEntry) {
    bool result;
    removeValue(root, anEntry, result);
    return result;
}

/**
 * It is a method to calculate how many values in range a-b
 * @brief It visits exactly same with the result
 * @param a is the minimum value
 * @param b is the maximum value
 * @return int is the total number of the values which are in this range
 */
int BinarySearchTree::span(const int a, const int b) {
    return span(root, a, b);
}

/**
 * It is a helper method works recursively to calculate how many values in range a-b
 * @param node is the current node
 * @param min is the minimum value
 * @param max is the maximum value
 * @return int is the current number of values which are in this range
 */
int BinarySearchTree::span(BinaryNode* node, const int min, const int max) {
    if (node == NULL) {
        return 0;
    } else {
        if (node->item == min) {
            return 1 + span(node->rightChildPtr,min,max);
        } else if (node->item == max) {
            return 1 + span(node->leftChildPtr,min,max);
        } else if (node->item > min && node->item < max) {
            return 1 + span(node->leftChildPtr, min, max) + span(node->rightChildPtr, min, max);
        } else if (node->item > max) {
            return span(node->leftChildPtr, min, max);
        } else if (node->item < min) {
            return span(node->rightChildPtr, min, max);
        } else {
            return 0;
        }
    }

}

/**
  * It is a method that takes mirror of the BST
  * It works recursively and it start to replace from the leaves(which is a result of recursion).
  * Then It goes to up and change to main subtree(All levels are replaced).
  */
void BinarySearchTree::mirror() {
    mirror(root);
}

/**
 * It is a helper method to takes mirror of the BST
 * @param node is the current node
 */
void BinarySearchTree::mirror(BinaryNode* node) {
    if (node == NULL) {
        return;
    } else {
        BinaryNode* temp;

        mirror(node->leftChildPtr);
        mirror(node->rightChildPtr);

        temp = node->leftChildPtr;
        node->leftChildPtr = node->rightChildPtr;
        node->rightChildPtr = temp;
    }
}