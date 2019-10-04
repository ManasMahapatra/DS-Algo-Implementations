#include <stdio.h>
#include <iostream>
//Queue can be used to merge sorted arrays
#include <queue>
using namespace std;
//This method is an utility method to merge two ascending sorted arrays
//----------------------------
//MERGE SORTED ARRAYS - QUEUE
//----------------------------
void mergeTwoSortedArrays(int sortedArrayA[], int sortedArrayB[], int lengthA, int lengthB) {
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
//----------------------------
//MERGE SUBARRAYS 
//----------------------------

void mergeSubarrays(int originalArray[], int left, int middle, int right) {
    //First separate the elements of original array into two different queues
    //From left end to mid
    queue <int> leftMid;
    //Store elements from the right to the middle.
    //P.S. Left to middle is not 0 to mid, the left pointer wiill change
    for (int i = left; i <= middle; i++) {
        leftMid.push(originalArray[i]);
    }
    //From mid to right end
    queue <int> midRight;
    for (int i = middle + 1; i <= right; i++) {
        midRight.push(originalArray[i]);
    }
    //Start indexing from left, not from 0, as the left pointer will change, and setting it to zero will
    //overwrite existing sorted elements
    int indexCount = left;
    while (!leftMid.empty() || !midRight.empty()) {
        //If both queues qre non empty, check minimum, pop and increment the index
        if (!leftMid.empty() && !midRight.empty()) {
            if (leftMid.front() < midRight.front()) {
                originalArray[indexCount] = leftMid.front();
                leftMid.pop();
                indexCount++;
            } else {
                originalArray[indexCount] = midRight.front();
                midRight.pop();
                indexCount++;
            }
        }
        //If not then copy the elements one by one.
        if (!leftMid.empty() && midRight.empty()) {
            originalArray[indexCount] = leftMid.front();
            leftMid.pop();
            indexCount++;
        }
        if (!midRight.empty() && leftMid.empty()) {
            originalArray[indexCount] = midRight.front();
            midRight.pop();
            indexCount++;
        }
    }
}
//----------------------------
//MERGE SORT 
//----------------------------
void mergeSortArrays(int originalArray[], int left, int right) {
    //Base case
    //Only proceed if the legt index is lesser than the right end
    if (left < right) {
        int middle = (left + right) / 2;
        //Merge sort the left half
        mergeSortArrays(originalArray, left, middle);
        //Merge sort the right half
        mergeSortArrays(originalArray, middle + 1 ,right);
        //merge the subarrays
        mergeSubarrays(originalArray, left, middle, right);
    }
}
