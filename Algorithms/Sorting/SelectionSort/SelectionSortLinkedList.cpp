#include <stdio.h>
#include <iostream>
#include "../../../DataStructures/LinearDataStructures/LinkedList/LinkedList.cpp"

class SortedLinkedList : public LinkedList {
    public:
    void selectionSort() {
        //Variable to store current minimum value
        int newMinimumValue;
        //Pointer to point at the new minimum index
        node* newMinimumNode = NULL;
        //Variable to store current minimum Node
        node* currentMinimumNode;
        //Inner and outer traverse Node
        node* innerTraverseNode;
        //Start the outer loop from head
        node* traverseNode = head;
        while (traverseNode != NULL) {
            //set the current node as minimum
            currentMinimumNode = traverseNode;
            //Store the minimuym considered data
            newMinimumValue = currentMinimumNode->data;
            //Start the inner lop from the next node onwards
            innerTraverseNode = traverseNode->next;
            while(innerTraverseNode != NULL) {
                //change the new minimum only when the traversing node's data will be less than the current minimum data
                if (innerTraverseNode->data < newMinimumValue) {
                    newMinimumValue = innerTraverseNode->data;
                    newMinimumNode = innerTraverseNode;
                }
                innerTraverseNode = innerTraverseNode->next;
            }
            //Swap only if theres a node and then reset the minimum node to NULL
            if (newMinimumNode != NULL) {
                newMinimumNode->data = currentMinimumNode->data;
                currentMinimumNode->data = newMinimumValue;
                newMinimumNode = NULL;
            }
            traverseNode = traverseNode->next;
        }
    }
};

