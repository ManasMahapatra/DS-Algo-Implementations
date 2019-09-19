#include <stdio.h>
#include <iostream>
using namespace std;
const int arraySize = 7;
struct node {
    node* prev;
    int data;
    node* next;
};
class HashMap {
    private:
    //Take an array of pointers which will point to node objects;
    node* primaryArray[arraySize];
    //another array which will point to the tails of the doubly linked lists
    node* tails[arraySize];
    bool checkExistenceInNode(int value, int nodePosition) {
        node* traverseNode;
        traverseNode = primaryArray[nodePosition];
        if (traverseNode == NULL) {
            return false;
        } else {
            while (traverseNode != NULL) {
                if (traverseNode->data == value) {
                    return true;
                    break;
                }
                traverseNode = traverseNode->next;
            }
        }
        return false;
    }
    int hashFunction(int key) {
        return key / (sizeof(primaryArray)/sizeof(primaryArray[0]));
    }
    public:
    HashMap() {
        for (int i = 0;i<arraySize;i++) {
            primaryArray[i] = NULL;
            tails[i] = NULL;
        }
    }
    //---------------------------------------------------
    //INSERTION
    //---------------------------------------------------
    void insertKeyValue(int key,int value) {
        int hashedKey = hashFunction(key);
        if (checkExistenceInNode(value, hashedKey)) {
            cout<<"[-]Duplicate Value Warning.Not appending.\n";
        } else {
            node* temporaryNode = new node;
            temporaryNode->data = value;
            if (primaryArray[hashedKey] == NULL) {
                temporaryNode->prev = primaryArray[hashedKey];
                primaryArray[hashedKey] = temporaryNode;
                temporaryNode->next = NULL;
                tails[hashedKey] = temporaryNode;
                //Dilute the temporary node pointer
                temporaryNode = NULL;
                cout<<"[+]Appended Element.\n";
                
                
            } else {
                tails[hashedKey]->next = temporaryNode;
                temporaryNode->prev = tails[hashedKey];
                temporaryNode->next = NULL;
                tails[hashedKey] = temporaryNode;
                //Dilute the temporary node pointer
                temporaryNode = NULL;
                cout<<"[+]Appended Element.\n";
                
            }
        }
    }
    //---------------------------------------------------
    //DELETION
    //---------------------------------------------------
    void filterMapByValue(int value) {
        node* traverseNode;
        for (int i=0;i<arraySize;i++) {
            traverseNode = primaryArray[i];
            if (traverseNode != NULL) {
                while (traverseNode != NULL) {
                    if (traverseNode->data == value) {
                        if (traverseNode->prev == NULL){
                            primaryArray[i] = traverseNode->next;
                            if (traverseNode->next != NULL) {
                                traverseNode->next->prev = NULL;
                            }
                            traverseNode = NULL;
                            break;
                        }
                        //set the { prev } of element next to current node to element previous to current node
                        traverseNode->prev->next = traverseNode->next;
                        if (traverseNode->next == NULL) {
                            traverseNode = NULL;
                            continue;
                        }
                        //set the { next } of element of previous node to element next to current node 
                        traverseNode->next->prev = traverseNode->prev;
                        traverseNode = NULL;
                        continue;
                    }
                    traverseNode = traverseNode->next;
                }
            }
        }
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    void traverseHashMap() {
        node* traverseNode;
        for (int i=0;i<arraySize;i++) {
            traverseNode = primaryArray[i];
            if (primaryArray[i] != NULL) {
                cout<<"[+] "<<i;
                while(traverseNode != NULL) {
                    cout<<"-->"<<traverseNode->data;
                    traverseNode = traverseNode->next;
                }
            } else {
                cout<<"[-] "<<i;
            }
            cout<<"\n";
        }
    }
    void findByValue(int value) {
        node* traverseNode;
        for (int i=0;i<arraySize;i++) {
            traverseNode = primaryArray[i];
            if(primaryArray[i] != NULL) {
                while(traverseNode != NULL) {
                    if (traverseNode->data == value) {
                        cout<<"[+]Value is found at index: "<<i<<"\n";
                        break;
                    }
                    traverseNode = traverseNode->next;
                }
            }
        }
        cout<<"[-]Value Not Found\n";
    }
    void findByKey(int key) {
        int hashedKey = hashFunction(key);
        node* traverseNode = primaryArray[hashedKey];
        if (traverseNode == NULL) {
            cout<<"[-]No Value inside key provided\n";
        } else {
            cout<<"[+]Value found are:";
            while (traverseNode != NULL) {
                cout<<traverseNode->data<<"\t";
                traverseNode = traverseNode->next;
            }
            cout<<"\n";
        }
    }
};
