#include<stdio.h>
#include<iostream>
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
    //This method will search for the proper position for the Value, so as the tree is sorted and append it
    //using recurssion. This is also called function overloading, using the same function name with different argument types.
    //---------------------------------------------------
    //INSERTION
    //---------------------------------------------------
    void insertElement(node* temporaryNode, node* leaf){
        //Two Possibilities:
        //(1) The current data is less than the value in leaf node:
        //If so, check if the left position is vacant, or pass the temporary node, and the left of the leaf node for another iteration
        if ((temporaryNode->data) <= (leaf->data)){
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
};
int main() {
    BinaryTree tree1;
    tree1.insertElement(2);
    tree1.insertElement(1);
    tree1.insertElement(3);
    tree1.insertElement(7);
    tree1.insertElement(4);
    tree1.insertElement(31);
    tree1.insertElement(5);
    tree1.inOrderTraversal();
    tree1.deleteChildrenOfNode(23);
    tree1.inOrderTraversal();

}