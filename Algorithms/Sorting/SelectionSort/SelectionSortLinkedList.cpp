#include <stdio.h>
#include <iostream>
#include "../../../DataStructures/LinearDataStructures/LinkedList/LinkedList.cpp"

class SortedLinkedList : public LinkedList {
    public:
    int yz = 0;
};

int main() {
    SortedLinkedList list;
    list.insertNode(10);
    list.insertNode(23);
    list.traverseList();
    return 0;
}
