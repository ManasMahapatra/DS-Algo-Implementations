#include<stdio.h>
#include<iostream>
using namespace std;
//This represents a basic node. A node is a crucial element of linked list data type, which contains
//the data and the element pointers.
struct node {
    node* prev;
    int data;
    //this pointer will point to another node type, hence {node*}
    node* next;
};
class PriorityQueueLinkedList {
    private:
    node *front,*rear;
    public:
    PriorityQueueLinkedList() {
        front = NULL;
        rear = NULL;
    }
    //---------------------------------------------------
    //ENQUEUE
    //---------------------------------------------------
    void enqueuePriorityElement(int value){
        node* temporaryNode = new node;
        temporaryNode->data = value;
        temporaryNode->prev = NULL;
        temporaryNode->next = NULL;
        if (front == NULL){
            front = temporaryNode;
            rear = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            int count = 0;
            node* traverseNode = rear;
            while(traverseNode != NULL){
                if (traverseNode->data > value) {
                    node* traverseNodeOut = traverseNode->prev;
                    count++;
                    //First detach and reconfigure the preceding and succeding elements
                    if (temporaryNode->next != NULL) {
                        temporaryNode->next->prev = temporaryNode->prev;
                    }
                    if (temporaryNode->prev != NULL) {
                        temporaryNode->prev->next = temporaryNode->next;
                    }
                    //Then switch the temporry node to the new position
                    //Set the { next } of temp node to the new element
                    temporaryNode->next = traverseNode;
                    //Set the { prev } of temp node to the { prev } of new element
                    temporaryNode->prev = traverseNode->prev;
                    //Set the { next } of element precedding the new element to temp node
                    if (traverseNode->prev != NULL) {
                        traverseNode->prev->next = temporaryNode;
                    } else {
                        front = temporaryNode;
                    }
                    //Set the { prev } of new element to the temp node;
                    traverseNode->prev = temporaryNode;
                    traverseNode = traverseNodeOut;
                } else {
                    traverseNode = traverseNode->prev;
                }
            }
            if (count == 0){
                temporaryNode->prev = rear;
                rear->next = temporaryNode;
                rear = temporaryNode;
            }
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }
    }
    //---------------------------------------------------
    //DEQUEUE
    //---------------------------------------------------
    int deque() {
        if (front == NULL){
            cout<<"[-] Queue Underflow Warning\n";
            return 0;
        } else {
            node* temporaryNode = front->next;
            int dequeValue = front->data;
            front = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
            return dequeValue;
        }
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    int size() {
        int count = 0;
        node* traverseNode = front;
        while(traverseNode != NULL){
            count++;
            traverseNode = traverseNode->next;
        }
        return count;
    }
    int getFront() {
        return front->data;
    }
    void traverseQueue() {
        if (front == NULL) {
            cout<<"[-]Empty Queue.\n";
        } else if(front == rear) {
            node* traverseNode = front;
            cout<<"[front] "<<traverseNode->data<<" [rear]";
        } else {
            node* traverseNode = front->next;
            cout<<front->data<<" [front]";
            while(traverseNode->next != NULL){
                cout<<"\t"<<traverseNode->data;
                traverseNode = traverseNode->next;
            }
            cout<<"\t"<<traverseNode->data<<" [rear]";
        } 
        cout<<"\n";      
    }
};