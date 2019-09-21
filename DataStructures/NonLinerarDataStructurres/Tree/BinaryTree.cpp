#include<stdio.h>
#include<iostream>
#include <queue>
using namespace std;
struct node {
    //This will point to theleft child of the current node
    node* left;
    //This will contain the data
    int data;
    //This will point to the right child of current node
    node* right;
};
class BinaryTree {
    private:
    //This pointer will always keep track of the root node
    node *root;
    queue <node*> bfsQueue;
    //This method will search for the proper position for the Value, so as the tree is sorted and append it
    //using recurssion. This is also called function overloading, using the same function name with different argument types.
    //---------------------------------------------------
    //INSERTION
    //---------------------------------------------------
    void insertElement(node* temporaryNode, node* leaf){
        //Two Possibilities:
        //(1) The current data is less than the value in leaf node:
        //If so, check if the left position is vacant, or pass the temporary node, and the left of the leaf node for another iteration
        if ((temporaryNode->data) < (leaf->data)){
            if (leaf->left != NULL) {
                insertElement(temporaryNode,leaf->left);
            } else {
                leaf->left = temporaryNode;
                //Dilute the temporary node pointer
                temporaryNode = NULL;
            }
            //(2) The current data is greater than the value in leaf node
            //If so check if the right side is vacant, if not pass the temporary node and right node for another iteration
        } else if ((temporaryNode->data) > (leaf->data)){
            if (leaf->right != NULL) {
                insertElement(temporaryNode,leaf->right);
            } else {
                leaf->right = temporaryNode;
                //Dilute the temporary node pointer
                temporaryNode = NULL;
            }
        }
        //Inserting an element of same value doesn't make any sense for a binary tree.
        //Still if you want to add you can add it to your left element, however it would take more computational steps to traverse the tree.
    }
    void deleteChildrenOfNode(int value,node* leaf){
        //Three possibilities: Value in the provided node can be less than, equal to or greater than the 
        //value that needs to be deleted
        if (leaf == NULL) {
            cout<<"[-] No node found with specified value\n";
            return;
        } else if (value < leaf->data) {
            deleteChildrenOfNode(value, leaf->left);
        } else if (value > leaf->data) {
            deleteChildrenOfNode(value, leaf->right);
        } else if (value == leaf->data) {
            //If match found set the { left } and { right } to point to NULL
            leaf->right = NULL;
            leaf->left = NULL;
        }
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    //Depth First Search
    //3 Tupes: Inorder, Preorder and Postorder
    void inOrderTraversal(node* leaf) {
        if (leaf != NULL) {
            //Traversals are multi-level recursions. For better understanding consider a two tier tree and map the 
            //Iterations
            inOrderTraversal(leaf->left);
            cout<<leaf->data<<"\t";
            inOrderTraversal(leaf->right);
        }
    }
    void preOrderTraversal(node* leaf) {
        if (leaf != NULL) {
            //Traversals are multi-level recursions. For better understanding consider a two tier tree and map the 
            //Iterations
            cout<<leaf->data<<"\t";
            preOrderTraversal(leaf->left);
            preOrderTraversal(leaf->right);
        }
    }
    void postOrderTraversal(node* leaf) {
        if (leaf != NULL) {
            //Traversals are multi-level recursions. For better understanding consider a two tier tree and map the 
            //Iterations
            postOrderTraversal(leaf->left);
            postOrderTraversal(leaf->right);
            cout<<leaf->data<<"\t";
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
                bfsQueue.push(leaf->left);
            }
            //If there is a right node, enqueue it
            if (leaf->right != NULL) {
                bfsQueue.push(leaf->right);
            }
        } 
        while(!bfsQueue.empty()) {
            //Get reference to the firts item in queue
            temporaryNode = bfsQueue.front();
            //Print the data inside it
            cout<<temporaryNode->data<<"\t";
            //If there is a left node, enqueue it
            if (temporaryNode->left != NULL) {
                bfsQueue.push(temporaryNode->left);
            }
            //If there is a right node, enqueue it
            if (temporaryNode->right != NULL) {
                bfsQueue.push(temporaryNode->right);
            }
            //Pp the front element
            bfsQueue.pop();
        }
    }
    public:
    BinaryTree() {
        root = NULL;
    }
    //---------------------------------------------------
    //INSERTION
    //---------------------------------------------------
    void insertElement(int value) {
        //Create a temporary pointer to a node;
        node* temporaryNode = new node;
        //Store the value in its data;
        temporaryNode->data = value;
        //As its a new child initiate its { left } and { right } container to point NULL
        temporaryNode->left = NULL;
        temporaryNode->right = NULL;
        //If its the first element, or { root } is NULL
        if (root == NULL) {
            root = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            insertElement(temporaryNode, root);
        }
    }
    //---------------------------------------------------
    //DELETION
    //---------------------------------------------------
    void deleteChildrenOfNode(int value){
        if (root == NULL) {
            cout<<"[-] Tree is already empty\n";
            return;
        } else {
            deleteChildrenOfNode(value , root);
        }
    }
    //---------------------------------------------------
    //ITRAVERSAL
    //---------------------------------------------------
    void inOrderTraversal() {
        if (root == NULL) {
            cout<<"[-] Tree is empty.\n";
            return;
        } else {
            inOrderTraversal(root);
            cout<<"\n";
        }
    }
    void preOrderTraversal() {
        if (root == NULL) {
            cout<<"[-] Tree is empty.\n";
            return;
        } else {
            preOrderTraversal(root);
            cout<<"\n";
        }
    }
    void postOrderTraversal() {
        if (root == NULL) {
            cout<<"[-] Tree is empty.\n";
            return;
        } else {
            postOrderTraversal(root);
            cout<<"\n";
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
