//This priority queue implementatio is in a way more efficient than linked List implementations, as the for N sequential operations
//complexity will be O(n^3/2).
//However there are major drawbacks:
//(1) Fixed size of array

//(2) If  there is are spaces left, and in case the next value is lesser than the max values of each row, the queue
//will overflow, meaning all the space is not efficiently used.
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
class PriorityQueue {
    public:
    int arrayLength = 5;
    int primaryArray[5][5];
    int monitorArray[5];
    PriorityQueue() {
        for (int i = 0;i<arrayLength;i++) {
            monitorArray[i] = 0;
        }
        for(int i=0;i<arrayLength;i++){
            for (int j=0;j<arrayLength;j++) {
                primaryArray[i][j] = 0;
            }
        }
        return;
    }
    //---------------------------------------------------
    //ENQUEUE
    //---------------------------------------------------
    void insertPriorityElement(int value) {
        int correctRow = -1;
        int numberOfElements = 0;
        //Find the correct row to append element
        for(int i = 0;i<arrayLength;i++) {
            //If the row is not full then proceed
            if (monitorArray[i] != 5) {
                //store the number of elements in that row
                numberOfElements = monitorArray[i];
                //store the last integer as the maximum integer in the row
                int maxInRow = primaryArray[i][numberOfElements - 1];
                //If provided value is greater than the maximum found, append it to that row
                if (value > maxInRow) {
                    correctRow = i;
                    //increment the number of elements
                    monitorArray[i]++;
                    break;
                }
            }
        }
        //If there's no available space: Overflowing
        if (correctRow == -1) {
            cout<<"Queue Overflow Warning\n";
            return;
        }
        //Append the element
        primaryArray[correctRow][numberOfElements] = value;
    }
    //---------------------------------------------------
    //DEQUEUE
    //---------------------------------------------------
    int dequeue() {
        //Store the row ,column,and the max value of the correct element
        int correctRow = -1;
        int correctColumn = -1;
        int maxValue = -1;
        for (int i = 0; i < arrayLength;i++) {
            //Proceed if there is any element in the row
            if (monitorArray[i] != 0) {
                //Store the number of elements in the row
                int numberOfElements = monitorArray[i];
                //Store if the max value of current row is more than the existing maxValue
                if (primaryArray[i][numberOfElements - 1] > maxValue) {
                    correctRow = i;
                    correctColumn = numberOfElements - 1;
                    maxValue = primaryArray[i][numberOfElements - 1];
                }
            }
        }
        primaryArray[correctRow][correctColumn] = 0;
        //Decrement the monitoring element
        monitorArray[correctRow]--;
        //return the dequeued value
        return maxValue;
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    void traverseQueue() {
        for (int i = 0;i<arrayLength;i++) {
            cout<<monitorArray[i]<<"\t";
        }
        cout<<"\n\n";
        for(int i=0;i<arrayLength;i++){
            for (int j=0;j<arrayLength;j++) {
                cout<<primaryArray[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
};
