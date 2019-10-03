#include <stdio.h>
#include <iostream>
//Queue can be used to merge sorted arrays
#include <queue>
using namespace std;
//This method is an utility method to merge two ascending sorted arrays
void mergeSortedArrays(int sortedArrayA[], int sortedArrayB[], int lengthA, int lengthB) {
    //Make a queue for elements of array A
    queue <int> queueA;
    for (int i = 0; i < lengthA; i++) {
        queueA.push(sortedArrayA[i]);
    }
    //Make a queue for elements of array A
    queue <int> queueB;
    for (int i = 0; i < lengthB; i++) {
        queueB.push(sortedArrayB[i]);
    }
    queue <int> queueC;
    //Run the loop untill both of the queues are empty
    while (!queueA.empty() || !queueB.empty()) {
        //If both the queues are not empty
        if (!queueA.empty() && !queueB.empty()) {
            if (queueA.front() < queueB.front()) {
                //If the front of A is lesser than that of B, push it
                queueC.push(queueA.front());
                //And then pop it.
                queueA.pop();
            } else {
                //If the front of B is lesser than that of A, push it
                queueC.push(queueB.front());
                //And then pop it.
                queueB.pop();
            }
        }
        if (!queueA.empty() && queueB.empty()) {
            queueC.push(queueA.front());
            //And then pop it.
            queueA.pop();
        }
        if (!queueB.empty() && queueA.empty()) {
            queueC.push(queueB.front());
            //And then pop it.
            queueB.pop();
        }
    }
    while (!queueC.empty()) {
        cout<<queueC.front()<<" ";
        queueC.pop();
    }
    cout<<"\n";
}
int main() {
    int arrA[] = {-22,4,76,81,98,109,177};
    int arrB[] = {1,32,52,71,2121,2132};
    int lenA = sizeof(arrA)/sizeof(arrA[0]);
    int lenB = sizeof(arrB)/sizeof(arrB[0]);
    mergeSortedArrays(arrA,arrB,lenA,lenB);
    return 0;
}