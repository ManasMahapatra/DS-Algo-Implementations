#include <stdio.h>
#include <iostream>
//This is the node structure for an AVL Tree.
struct node {
    //This will contain the data of the node
    int data;
    //These will contain the left and right child node's address
    node* left;
    node* right;
    //This will contain the height of the node. As a parent node.
    int height;
};
class AVLTree {
    private:
    //This is a utility function to compare two integers and return the greater one
    int max(int a, int  b) {
        //This is a one liner statement to represent, if a > b return a else b.
        return (a > b) ? a : b;
    }
    //This is a utility function to return the height of the provided node
    int height(node* element) {
        return (element == NULL) ? 0 : element->height;
    }
    //This is not mandatory
    node* initNode (int value) {
        node* temporaryNode = new node;
        //Initiate the data as the key provided
        temporaryNode->data = value;
        //Nullify the left and right poiinter
        temporaryNode->left = NULL;
        temporaryNode->right = NULL;
        //As a new node will always be a leaf, initiate its height to 1
        temporaryNode->height = 1;
    }

    node* rightRotate(node* unbalancedElement) {
        //Store the left subtree of the unbalanced element to a node
        node* temporaryNode = unbalancedElement->left;
        //Store the right subtree of the temporary Node to another pointer
        node* rightSubtree = temporaryNode->right;
        //Perform the rotation
        //set the temporary node's right pointer to point to point at the unbalanced element.
        temporaryNode->right = unbalancedElement;
        //set the left pointer of unbalanced item to point at the right subtree of temporary node
        unbalancedElement->left = rightSubtree;
        //Set the heights
        unbalancedElement->height = max(height(unbalancedElement->left),height(unbalancedElement->right));
        temporaryNode->height = max(height(temporaryNode->left),height(temporaryNode->right));
        //return the new root
        return temporaryNode;
    }

    node* leftRotate(node* unbalancedElement) {
        //Store the right subtree of the unbalanced element to a node
        node* temporaryNode = unbalancedElement->right;
        //Store the left subtree of the temporaryNode to another pointer
        node* leftSubtree = temporaryNode->left;
    }
};