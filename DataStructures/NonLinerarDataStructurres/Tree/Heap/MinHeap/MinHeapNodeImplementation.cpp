#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
//This will be the node structure of a Max Heap
struct node {
    //This will contain the value of the node
    int data;
    //These two will point to the left and right child nodes respectively
    node* left;
    node* right;
    //This will point to the parent element. As in heap, there will be continous swapping with the parent elements
    //We need a way to traverse upwards as well.
    node* parent;
};
class MinHeapNode {
    private:
    //Initiate the root element
    node* root;
    //A pointer to point to the new tail of the tree
    node* newTail;
    queue <node*> insertQueue;
    queue <node*> bstQueue;
    //Perform a regular Binary tree insertion first
    void insertElement(node* root,node* newNode) {
        node* topElement;
        insertQueue.push(root);
        while(!insertQueue.empty()) {
            //Store the top element of the queue
            topElement = insertQueue.front();
            //Check if left is empty 
            if (topElement->left == NULL) {
                //Store the new node at the left
                topElement->left = newNode;
                //Store the parent of new node as top element
                newNode->parent = topElement;
                //Assign the newTail
                newTail = newNode;
                return;
            } else {
                //Enqueue the left element
                insertQueue.push(topElement->left);
            }
            //Check if right is empty
            if (topElement->right == NULL) {
                //Store the new node at the right
                topElement->right = newNode;
                //Store the parent of new node as top element
                newNode->parent = topElement;
                //Assign the newTail
                newTail = newNode;
                return;
            } else {
                //Enqueue the right element
                insertQueue.push(topElement->right);
            }
            insertQueue.pop();
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
    //This method, after a regular Binary tree insertion will perform a check if the tree is a min heap.
    //If not it will make necessary swaps.
    void minifyHeap() {
        int store = 0;
        while (newTail->parent != NULL) {
            //If the child value is lesser than parent value
            if (newTail->data < newTail->parent->data) {
                //Swap the value
                store = newTail->parent->data;
                newTail->parent->data = newTail->data;
                newTail->data = store;
            }
            newTail = newTail->parent;
        }
    }
    public:
    MinHeapNode() {
        //Nullify the root and tail eleement at initiation
        root = NULL;
        newTail = NULL;
    }
    int getMinimum() {
        return root->data;
    }
    void insertElement(int value) {
        //Create a new node and a temporary node pointer to point to it.
        node* temporaryNode = new node;
        //Store the value in the new node
        temporaryNode->data = value;
        //Nullify the left , right and parent pointers of the new node
        temporaryNode->left = NULL;
        temporaryNode->right = NULL;
        temporaryNode->parent = NULL;
        if (root == NULL) {
            //If its the first element coming in, make it root
            root = temporaryNode;
            //Dilute the temporary node
            temporaryNode = NULL;
            return;
        } else {
            //if not insert add it to next level
            insertElement(root,temporaryNode);
            //Minify the tree
            minifyHeap();
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
int main() {
    MinHeapNode heap;
    heap.insertElement(3);
    heap.insertElement(5);
    heap.insertElement(6);
    heap.insertElement(4);
    heap.insertElement(2);
    heap.insertElement(1);
    heap.levelOrderTraversal();
    return 0;
}