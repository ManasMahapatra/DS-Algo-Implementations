#include<stdio.h>
#include<iostream>
using namespace std;
const int arraySize = 6;
//Circular queue Imlementation using Arrays. As there's actually no need of Circular Queue if we use Linked List.
class CircularQueue{
    private:
    //For keeping the front element in track
    int front = -1;
    //For keeping the rear element in track
    int rear = -1;
    public:
    //This will be the primary array which we will use as Queue
    int primaryArray[arraySize];
    //---------------------------------------------------
    //ENQUEUE
    //---------------------------------------------------
    void enqueueElement(int value){
        //Overflow Conditions:
        //(1) If the { front } is at the first element and { rear } at the last element;
        //----->{ front == 0 && rear ==arraySize - 1 }
        //(2) As we are recycling vacant places, the next condition when the queue will overflow when { rear }
        //is just before { front }.
        if ((front == 0 && rear == arraySize-1) || rear == front - 1) {
            cout<<"[+] Queue Overflow Warning\n";
            return;
        }
        //If not overflowing Possible Conditions:
        //(1)Empty Queue: { front } is -1.
        //(2){} front } is not at the 0th position but { rear } is at the last position
        //(3) { rear } is behind { front } but there is gap in between as its not overflowing
        else if (front == -1) {
            front = rear = 0;
            primaryArray[rear] = value;
        }
        else if (rear == arraySize - 1 && front != 0) {
            rear = 0;
            primaryArray[rear] = value;
        }
        else {
            rear++;
            primaryArray[rear] = value;
        }
    }
    //---------------------------------------------------
    //DEQUEUE
    //---------------------------------------------------
    int deque() {
        //Underflow Condition: The queue will be underflowing only when the { front } is negative
        if (front == -1) {
            cout<<"[-]Queue Underflow Warning\n";
            return 0;
        }
        //Store the dequeued value so that we can shift the position of { front }
        int dequeuedValue = primaryArray[front];
        //Set the value of the vacated position to be -1
        primaryArray[front] = -1;
        //Three possible Condition:
        //(1) { front } == { rear }:If there's only one element in qeue
        //(2) { front } is the last element of array, and rear is somewhere behind. So we need to shift the
        //{ front } to the 0th index
        //(3) { front } is just somewhere in the middle of array, so we just need to increment.

        //If front equals rear it means, the queue is empty after dequeueing, so revert it back to initial position
        if (front == rear){
            front = rear = -1;
        }
        //If the front is at the last element of array shift it to the first element of array
        else if (front == arraySize - 1){
            front = 0;
        }
        //Else just increment the value to the next element.
        else {
            front ++;
        }
        return dequeuedValue;
    }
    //---------------------------------------------------
    //TRAVERSAL
    //---------------------------------------------------
    void traverseQueue() {
        if (front == -1){
            cout<<"[-] Queue is empty.\n";
            return;
        }
        //Possible Cases:
        //(1) Rear is ahead of the Front: rear > front
        //(2) Rear is behind the front: rear < front
        if (rear > front) {
            cout<<"[front] "<<primaryArray[front];
            for (int i = front + 1;i<rear;i++) {
                cout<<"\t"<<primaryArray[i];
            }
            cout<<"\t"<<primaryArray[rear]<<" [rear]\n";
        } else if (rear == front) {
            cout<<"[front] "<<primaryArray[front]<<" [rear]\n";
        } else if (rear < front) {
            for(int i = 0; i < rear ; i++) {
                cout<<primaryArray[i]<<"\t";
            }
            cout<<primaryArray[rear]<<" [rear]\t";
            for (int i = rear + 1;i < (front - rear); i++) {
                cout<<"[-]\t";
            }
            cout<<"[front] "<<primaryArray[front]<<"\t";
            for (int i = front+1;i<arraySize;i++){
                cout<<primaryArray[i]<<"\t";
            }
        }
    }
};