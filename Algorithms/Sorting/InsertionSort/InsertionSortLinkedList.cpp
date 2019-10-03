#include <stdio.h>
#include <iostream>
//As insertion sort requires bacwards traversal we will use our doubly linked list.
#include "../../../DataStructures/LinearDataStructures/LinkedList/DoublyLinkedList.cpp"
using namespace std;

class SortedDoublyLinkedList : public DoublyLinkedList {
    public:
    void insertionSort() {
        //initiate a traverse node from head
        node* traverseNode = head;
        //initiate a traverse node for the inner loop
        node* innerTraverseNode = NULL;
        node* currentNode = NULL;
        while (traverseNode != NULL) {
            currentNode = traverseNode;
            //------------------
            //Case: If the element is smaller then the head itself then simply insert it before at 
            //the head
            //------------------
            if (traverseNode->data < head->data) {
                //Shift the traversing node to the next element before reconfiguration
                traverseNode = traverseNode->next;
                //Reconfigure the whole element properly
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                currentNode->next = head;
                currentNode->prev = NULL;
                head->prev = currentNode;
                //Set the head at the new element
                head = currentNode;
                //Continue to the next loop
                //Dont break the whole loop, as it wont operate for next elements.
                continue;    
            }
            //set the inner traverse node to the previous of current node
            innerTraverseNode = traverseNode->prev;
            while (innerTraverseNode != NULL) {
                if (innerTraverseNode->data <= traverseNode->data && traverseNode->data <= innerTraverseNode->next->data && innerTraverseNode->next != traverseNode) {
                    //Set the { next } of previous element to the next element
                    traverseNode->prev->next = traverseNode->next;
                    if (traverseNode->next != NULL) {
                        //If there exists a next element configure its { prev }
                        traverseNode->next->prev = traverseNode->prev;
                        //Then shift it
                        traverseNode = traverseNode->next;
                    } else {
                        //Else set it to NULL
                        traverseNode = NULL;
                    }
                    //Reconfigure nodes
                    currentNode->prev = innerTraverseNode;
                    currentNode->next = innerTraverseNode->next;
                    innerTraverseNode->next->prev = currentNode;
                    innerTraverseNode->next = currentNode;
                    //set currentNode to NULL
                    currentNode = NULL;
                    break;
                }
                innerTraverseNode = innerTraverseNode->prev;
            }
            if (currentNode != NULL) {
                traverseNode = traverseNode->next;
            } 
        }
        //Traverse to the last element so as to set the tail properly for backward traversal.
        traverseNode = head;
        while(traverseNode->next != NULL){
            traverseNode = traverseNode->next;
        }
        //Set the tail to the traversed node.
        tail = traverseNode;
    }
};