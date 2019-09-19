#include<stdio.h>
#include<iostream>
using namespace std;
struct node {
    //the data section will contain the enqueued value
    int data;
    //this section will point to the next element in queue
    node* next;
};
class QueueLinkedList {
    private:
    node *front,*rear;
    public:
    QueueLinkedList() {
        front = NULL;
        rear = NULL;
    }
    //---------------------------------------------------
    //ENQUEUE
    //---------------------------------------------------
    void enqueueElement(int value) {
        //Create a temporary node pointer which will point to a new node.
        node* temporaryNode = new node;
        //Store the value in the new node's data section
        temporaryNode->data = value;
        //As the inserted element is suppposed to be at the end, the {next} section should be pointing to NULL
        temporaryNode->next = NULL;
        if (front == NULL) {
            front = temporaryNode;
            rear = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            rear->next = temporaryNode;
            rear = temporaryNode;
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
    int front() {
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
