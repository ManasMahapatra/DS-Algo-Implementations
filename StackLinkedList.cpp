#include<stdio.h>
#include<iostream>
using namespace std;
struct node {
    //data will contain the elements
    int data;
    //this pointer will point to the next element
    node* next;
};

class StackLinkedList {
    private:
    node *head,*tail;
    public:
    StackLinkedList() {
        //Iitiate both to NULL so as to avoid Garbage Values
        tail = NULL;
        head = NULL;
    }
    //---------------------------------------------------
    //PUSH
    //---------------------------------------------------
    void push(int value) {
        node* temporaryNode = new node;
        temporaryNode->data = value;
        if (head == NULL) {
            head = temporaryNode;
            tail = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            temporaryNode->next = head;
            head = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }
    }
    //---------------------------------------------------
    //POP
    //---------------------------------------------------
    int pop() {
        if (head == NULL) {
            cout<<"[-]Stack Underflow Warning\n";
            return 0;
        } else {
            //store the { next } value in a temporary node
            node* temporaryNode = head->next;
            //Store the current data before deleting and shift the head
            int popValue = head->data;
            head = temporaryNode;
            //return the popped value
            return popValue;
        }
        
    }
    //---------------------------------------------------
    //TOP
    //---------------------------------------------------
    int top() {
        return head->data;
    }
    //---------------------------------------------------
    //DISPLAY
    //---------------------------------------------------
    void traverseStack() {
        node* traverseNode = head;
        while (traverseNode != NULL) {
            cout<<traverseNode->data<<"\t";
            traverseNode = traverseNode->next;
        }
        cout<<"\n";
    }
};
