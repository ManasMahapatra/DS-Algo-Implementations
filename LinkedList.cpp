#include <bits/stdc++.h>
using namespace std;
//This Library is used mainly during programming contest to avoid importing libraries.

//This represents a basic node. A node is a crucial element of linked list data type, which contains
//the data and the element pointers.
struct node {
    int data;
    //this pointer will point to another node type, hence {node*}
    node* next;
};
class LinkedList {
    private:
    //These two pointers are necessary in order to keep a track of head and tail of a LinkedList object.
    //So as to initially avoid the garbage value, initiate it to NULL, in the constructor.
    node *head, *tail ;
    public:
    LinkedList() {
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
        //As the inserted element is suppposed to be at the end, the {next} section should be pointing to NULL
        temporaryNode->next = NULL;
        //Check if this is the first element, by seeing if head is still pointing to NULL
        if (head==NULL) {
            head = temporaryNode;
            tail = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            //If not, exchange values with current tail
            tail->next = temporaryNode;
            tail = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }
    }
    void insertNodeAtStart(int value) {
        //Create a temporary node pointer and point it to a new node
        node *temporaryNode = new node;
        //Check if this is the first element, by seeing if head is tsill pointing to NULL
        if (head==NULL) {
            //If yes proceed like regular insertion
            head = temporaryNode;
            temporaryNode->data = value;
            tail = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            //If no, first insert the value into the new node
            temporaryNode->data = value;
            //Assign the value of next to the address pointed by the head pointer
            temporaryNode->next =  head;
            //Point the head pointer to the new node
            head = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }     
    }
    void insertNodeAtPosition(int value,int position) {
        if (position == 1) {
            insertNodeAtStart(value);
        } else {
            node* traverseNode;
            node* temporaryNode = new node;
            temporaryNode->data = value;
            traverseNode = head;
            for(int i = 1;i < position-1;i++) {
                traverseNode = traverseNode->next;      
            }
            temporaryNode->next = traverseNode->next++;
            traverseNode->next = temporaryNode;
            temporaryNode = NULL;
            
        }
    }
    //---------------------------------------------------
    //DELETION
    //---------------------------------------------------
    void deleteNodeAtPosition(int position) {
        node* traverseNode = head;
        for (int i = 1;i < position-1;i++) {
            traverseNode = traverseNode->next;
        }
        deleteNodeOfValue(traverseNode->next->data);
    }
    void deleteNodeOfValue(int value) {
        if (head->data == value) {
            node* temporaryNode = head->next;
            head = temporaryNode;
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        } else {
            node* traverseNode;
            node* temporaryNode;
            traverseNode = head;
            while (traverseNode->next->data != value ) {
                traverseNode = traverseNode->next;
            }
            temporaryNode = traverseNode->next->next;
            traverseNode->next = temporaryNode; 
            //Dilute the temporary node pointer
            temporaryNode = NULL;
        }
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
    int accessPosition(int position) {
        node* traverseNode = head;
        if (position == 1) {
            return traverseNode->data;
        } else {
            for (int i = 1;i<position;i++) {
                traverseNode = traverseNode->next;
            }
            return traverseNode->data;
        }
    }
    int length() {
        if (head==NULL){
            return 0;
        }
        node* traverseNode = head;
        int count = 0;
        while (traverseNode != NULL){
            count++;
            traverseNode=traverseNode->next;
        }
        return count;
    }
    int keyCount(int key) {
        int frequency = 0;
        node* traverseNode = head;
        if(traverseNode == NULL) {
            return frequency;
        }
        while(traverseNode != NULL) {
            if (traverseNode->data == key) {
                frequency++;
            }
            traverseNode = traverseNode->next;
        }
        return frequency;
    }
    bool checkPalindrome(int low, int high) {
        if (low == high) {
            return true;
        }
        if (low > high) {
            return true;
        }
        if (accessPosition(low) == accessPosition(high)) {
            checkPalindrome(low + 1,high - 1);
        } else {
            return false;
        }

    }
    //---------------------------------------------------
    //REVERSAL
    //---------------------------------------------------
    void reverseLinkedList() {
        node* current = head;
        node* prev = NULL;
        node* next = NULL;
        //loop untill current head points to null (becomes the tail)
        while(current != NULL) {
            //assign the { next } pointer to the element next to { current }
            next = current->next;
            //assign the next part of current node to prev.
            //Initiallt at NULL, which means the head will point to NULL as a result
            current->next = prev;
            //point the { prev } pointer to the current node;
            prev = current;
            //shift the current node to point to the next one
            current = next;
        }
        //Assign the { head } to the final prev element
        head = prev;
    }
    void swapValue (int position1, int position2) {
        node* traverseNode1 = head;
        for (int i = 1;i < position1;i++) {
            traverseNode1 = traverseNode1->next;
        }
        node* traverseNode2 = head;
        for (int i = 1;i < position2;i++) {
            traverseNode2 = traverseNode2->next;
        }
        int temp = traverseNode1->data;
        traverseNode1->data = traverseNode2->data;
        traverseNode2->data =temp;
    }
    void reverseFromTo(int start,int end) {
        if (start != end && start < end) {
            swapValue(start,end);
            reverseFromTo(start + 1, end - 1);
        }
    }
};
int main() {
    LinkedList list1;
    //Use methods on { list1 } object.
    return 0;
}