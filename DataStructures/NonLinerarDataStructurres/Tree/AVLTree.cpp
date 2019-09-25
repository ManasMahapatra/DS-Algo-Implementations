#include <stdio.h>
#include <iostream>
using namespace std;
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
    //This is a utility function to check balance
    int checkBalance(node* leaf) {
        return (leaf == NULL) ? 0 : (height(leaf->left)-height(leaf->right));
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
        //Perform the rotation
        //set the temporary node's left to the unbalanced element
        temporaryNode->left = unbalancedElement;
        //set the right unbalaced element to the left subtree of temporary node
        unbalancedElement->right = leftSubtree;
        //set the heights
        unbalancedElement->height = max(height(unbalancedElement->left),height(unbalancedElement->right));
        temporaryNode->height = max(height(temporaryNode->left),height(temporaryNode->right));
        //return the new root
        return temporaryNode;
    }

    node* insertNode(node* leaf,int value) {
        //Why recurssion?
        //As tree node doesn't have a way to traverse upwards the tree, recurrsion is used perform 
        //operations in bottom-top direction. In this way each of the operation programmed will first happen
        //in the bottom nodes and gradualluy move up the tree performing checks and rotations.
        //Perform normal BST insertion
        if (leaf == NULL) {
            return initNode(value);
        }
        if (value < leaf->data) {
            leaf->left = insertNode(leaf->left,value);
        } else if (value > leaf->data) {
            leaf->right = insertNode(leaf->right, value);
        } else {
            //BST doesn't contain duplicates.
            return leaf;
        }
        //After normal insertion perform the balance check and rotations
        //1)Update height of the current ancestor
        leaf->height = max(height(leaf->left),height(leaf->right)) + 1;
        //2) fetch the balance to determine if this node has become imbalanced
        int balance = checkBalance(leaf);
        //3) If the node gets imbalanced there are four possibilities
        //Left left rotation
        if (balance > 1 && value < leaf->left->data) {
            return rightRotate(leaf);
        }
        //Right right rotation
        if (balance < -1 && value > leaf->right->data) {
            return leftRotate(leaf);
        }
        //Left right rotation
        if (balance > 1 && value > leaf->left->data) {
            leaf->left = leftRotate(leaf->left);
            return rightRotate(leaf);
        }
        //Right left rotation
        if (balance < -1 && value < leaf->right->data) {
            leaf->right = rightRotate(leaf->right);
            return leftRotate(leaf);
        }
        return leaf;
    }
    //In order traversal method
    void inOrderTraversal(node* leaf) {
        if (leaf != NULL) {
            //Traversals are multi-level recursions. For better understanding consider a two tier tree and map the 
            //Iterations
            inOrderTraversal(leaf->left);
            cout<<leaf->data<<"\t";
            inOrderTraversal(leaf->right);
        }
    }
};
