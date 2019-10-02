#include <stdio.h>
#include <iostream>
#include "../../../DataStructures/LinearDataStructures/LinkedList/LinkedList.cpp"

class SortedLinkedList : private LinkedList {
    public:
    void selectionSort() {
        //Variable to store new minimum value
        int newMinimum;
        node* traverseNode = head;
    }
};

int main() {
    SortedLinkedList list;
    list.insertNode(10);
    list.insertNode(23);
    list.traverseList();
    return 0;
}
