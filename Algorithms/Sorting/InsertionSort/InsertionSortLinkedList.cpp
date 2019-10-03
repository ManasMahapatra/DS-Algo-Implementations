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
            //Case - 1: 
            if (traverseNode->data < head->data) {
                traverseNode = traverseNode->next;
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                currentNode->next = head;
                currentNode->prev = NULL;
                head->prev = currentNode;
                head = currentNode;
                continue;    
            }
            //set the inner traverse node to the previous of current node
            innerTraverseNode = traverseNode->prev;
            while (innerTraverseNode != NULL) {
                if (innerTraverseNode->data <= traverseNode->data && traverseNode->data <= innerTraverseNode->next->data && innerTraverseNode->next != traverseNode) {
                    traverseNode->prev->next = traverseNode->next;
                    if (traverseNode->next != NULL) {
                        traverseNode->next->prev = traverseNode->prev;
                        traverseNode = traverseNode->next;
                    } else {
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
        traverseNode = head;
        while(traverseNode->next != NULL){
            traverseNode = traverseNode->next;
        }
        tail = traverseNode;
    }
};
int main() {
    SortedDoublyLinkedList list;
    list.insertNode(4);
    list.insertNode(21);
    list.insertNode(6);
    list.insertNode(-2);
    list.insertNode(2);
    list.insertNode(2343);
    list.insertNode(2389);
    list.insertNode(13);
    list.insertNode(23);
    list.insertNode(232);
    list.insertNode(23);
    list.insertNode(123);
    list.insertNode(3);
    list.insertNode(5454);
    list.insertNode(-98);
    list.insertNode(93);
    list.insertNode(983);
    list.insertNode(-123);
    list.insertNode(23098);
    list.traverseList();
    list.insertionSort();
    list.traverseListBack();
    return 0;
}