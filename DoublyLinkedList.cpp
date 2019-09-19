#include <bits/stdc++.h>
using namespace std;
//This Library is used mainly during programming contest to avoid importing libraries.

//This represents a basic node. A node is a crucial element of linked list data type, which contains
//the data and the element pointers.
struct node {
    node* prev;
    int data;
    //this pointer will point to another node type, hence {node*}
    node* next;
};

class DoublyLinkedList {
    private:
    //These two pointers are necessary in order to keep a track of head and tail of a LinkedList object.
    //So as to initially avoid the garbage value, initiate it to NULL, in the constructor.
    node *head,*tail;
    public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    //---------------------------------------------------
    //INSERTION
    //---------------------------------------------------
    void insertNode(int value) {
        //Create a temporary node pointer which will point to a new node.
        node *temporaryNode = new node;
        //Store the value in the new node's data section
        temporaryNode->data = value;
        
        //Check if this is the first element, by seeing if head is still pointing to NULL
        if (head==NULL) {
            head = temporaryNode;
            tail = temporaryNode;
            temporaryNode->next = NULL;
            temporaryNode->prev = NULL;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            //If not, exchange values with current tail
            temporaryNode->prev = tail;
            tail->next = temporaryNode;
            tail = temporaryNode;
            //As the inserted element is suppposed to be at the end, the {next} section should be pointing to NULL
            temporaryNode->next = NULL;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }
    }
    void insertNodeAtStart(int value) {
        node* temporaryNode = new node;
        temporaryNode->data = value;
        if (head==NULL) {
            head = temporaryNode;
            tail = temporaryNode;
            temporaryNode->next = NULL;
            temporaryNode->prev = NULL;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            //As the element is placed at the start it should point to null backwards
            temporaryNode->prev = NULL;
            temporaryNode->next = head;
            head->prev = temporaryNode;
            head = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }

    }
    void insertNodeAtPosition (int value,int position) {
        node* temporaryNode = new node;
        node* traverseNode = head;
        temporaryNode->data = value;
        //traverse till the position before required
        for (int i = 1;i < position - 1;i++) {
            traverseNode = traverseNode->next;
        }
        //set the { prev } of current element to traversed node
        temporaryNode->prev = traverseNode;
        //set the { next } of current element to { next } of traversed node
        temporaryNode->next = traverseNode->next;
        //set the { prev } of element next to traversed node to the current node
        traverseNode->next->prev = temporaryNode;
        //set the { next } of traversed node to current node
        traverseNode->next = temporaryNode;
        //Dilute the temporary node pointer
        temporaryNode = NULL;        
    }
    //---------------------------------------------------
    //DELETION
    //---------------------------------------------------
    void deleteNodeOfValue(int value) {
        node* traverseNode = head;
        while (traverseNode->data != value) {
            traverseNode = traverseNode->next;
        }
        //set the { prev } of element next to current node to element previous to current node
        traverseNode->prev->next = traverseNode->next;
        //set the { next } of element of previous node to element next to current node 
        traverseNode->next->prev = traverseNode->prev;
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    void traverseList() {
        node *temporaryNode;
        temporaryNode = head;
        while (temporaryNode != NULL) {
            cout<<temporaryNode->data<<"\t";
            temporaryNode = temporaryNode->next;
        }
        cout<<"\n";

    }
    void traverseListBack() {
        node* temporaryNode = tail;
        while (temporaryNode != NULL) {
            cout<<temporaryNode->data<<"\t";
            temporaryNode = temporaryNode->prev;
        }
        cout<<"\n";
    }
    //---------------------------------------------------
    //REVERSAL
    //---------------------------------------------------
    void reverseList() {
        int count = 0;
        node* traverseNode = head;
        tail = traverseNode;
        node* temporaryNode = traverseNode->next;
        while (temporaryNode != NULL) {
            traverseNode->next = traverseNode->prev;
            traverseNode->prev = temporaryNode;
            traverseNode = temporaryNode;
            temporaryNode = temporaryNode->next;
        }
        traverseNode->next = traverseNode->prev;
        traverseNode->prev = temporaryNode;
        head = traverseNode;
    }
};
