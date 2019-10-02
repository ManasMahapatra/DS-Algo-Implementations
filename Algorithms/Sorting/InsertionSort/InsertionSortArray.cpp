#include <stdio.h>
#include <iostream>
using namespace std;

void InsertionSort(int originalArray[], int arraySize) {
    for (auto i = 0;i <arraySize; i++) {
        //Store the current eleemnt
        int currentElement = originalArray[i];
        //Iterate backwards the array
        for (auto j = i-1;j >= 0; j--) {
            //If the current element is greater than the element on left side
            if (currentElement > originalArray[j]) {
                //Insert the current element in the right side and break from loop
                originalArray[j+1] = currentElement;
                break;
            //Else if its lesser than the value less
            } else {
                //Shift the element previous to it by one right
                originalArray[j+1] = originalArray[j];
                //Insert the current element there and loop again
                originalArray[j] = currentElement;
            }
        }
    }
}
