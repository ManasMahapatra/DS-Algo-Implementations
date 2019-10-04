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
//MERGE & SORT SUBARRAYS 
//----------------------------
void mergeSubarrays(int originalArray[], int left, int middle, int right) {
    //First separate the elements of original array into two different queues
    //From left end to mid
    queue <int> leftMid;
    for (int i = 0; i <= middle; i++) {
        leftMid.push(originalArray[i]);
    }
    //From mid to right end
    queue <int> midRight;
    for (int i = middle + 1; i <= right; i++) {
        midRight.push(originalArray[i]);
    }
    int indexCount = 0;
    while (!leftMid.empty() || !midRight.empty()) {
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
int main() {
    int arr[] = {1,3,4,5,6,7,8};
    mergeSubarrays(arr,0,3,6);
    for (int i = 0; i < 7; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}