#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
//Following is the structure of a binary tree node
struct node {
    //This contains the data of the node
    int data;
    //These will contain the left and right node of the tree
    node* left;
    node* right;
};
class BinaryTree {
    private:
    queue <node*> btNode;
    queue <node*> bstQueue;
    //initiate the root pointer
    node* root = NULL;
    //This method will have the logic to push elements in to the tree in a level order.
    void insertNode(node* leaf, node* newNode) {
        node* temporaryNode = NULL;
        //If ts the root element enqueue it
        if (leaf == root) {
            btNode.push(leaf);
        }
        while (!btNode.empty()) {
            //Get the first element of array and store it
            temporaryNode = btNode.front();
            //If its left is empty then assign it to the new node, else enqueue it
            if (temporaryNode->left == NULL) {
                temporaryNode->left = newNode;
                return;
            } else {
                btNode.push(temporaryNode->left);
            }
            //If its right is empty assign it to the new node, else enqueue it
            if (temporaryNode->right == NULL) {
                temporaryNode->right = newNode;
                return;
            } else {
                btNode.push(temporaryNode->right);
            }
            //Pop the front element
            btNode.pop();
        }
    }
    //Breadth First Search
    //This is different kind of traversal. This is also called level order traversals for tree. In this way
    //we travel each level from left to right. Just like a file directory.
    void levelOrderTraversal(node* leaf) {
        node* temporaryNode = NULL;
        //If its the root element there's no need to store. Just print the data inside it.
        if (leaf == root) {
            cout<<leaf->data<<"\t";
            //If there is a left node, enqueue it
            if (leaf->left != NULL) {
                bstQueue.push(leaf->left);
            }
            //If there is a right node, enqueue it
            if (leaf->right != NULL) {
                bstQueue.push(leaf->right);
            }
        } 
        while(!bstQueue.empty()) {
            //Get reference to the firts item in queue
            temporaryNode = bstQueue.front();
            //Print the data inside it
            cout<<temporaryNode->data<<"\t";
            //If there is a left node, enqueue it
            if (temporaryNode->left != NULL) {
                bstQueue.push(temporaryNode->left);
            }
            //If there is a right node, enqueue it
            if (temporaryNode->right != NULL) {
                bstQueue.push(temporaryNode->right);
            }
            //Pp the front element
            bstQueue.pop();
        }
    }
    //A regukar binary tree, unlike binary search tree doesn't need to traverse in depth mode to insert values.
    //Hence the target is to fill the element level wise, so as to form a complete binary tree.
    public:
    
    void insertNode(int value) {
        //Create a temporary node and initiate it.
        node* temporaryNode = new node;
        temporaryNode->data = value;
        //Nullify the left and right
        temporaryNode->left = NULL;
        temporaryNode->right = NULL;        
        if (root == NULL) {
            root = temporaryNode;
            //Dilute the temporary node
            temporaryNode = NULL;
        } else {
            insertNode(root, temporaryNode);
        }
        
    }
    void levelOrderTraversal() {
        if (root == NULL) {
            cout<<"[-] Tree is empty.\n";
            return;
        } else {
            levelOrderTraversal(root);
            cout<<"\n";
        }
    }
};