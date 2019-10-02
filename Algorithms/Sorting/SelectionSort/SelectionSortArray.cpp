#include <stdio.h>
#include <iostream>
using namespace std;

//Don't calculate the array size inside the fuction using sizeof operator, as the array passed
//is an integer pointer, and wont give proper size.
void SelectionSortArray(int originalArray[],int arraySize) {
    //Variable to store the new minimum values while iterating through the inner loop.
    int newMinimum;
    //Variable to store the new minimum index while iteating through the inner loop
    int newMinimumIndex = -1;
    //Loop through the array
    for (int i = 0;i < arraySize;i++) {
        //Select the current element is the minimum element
        int currentMinimum = originalArray[i];
        int newMinimum = currentMinimum;
        //Loop through the elements right to the current element
        for (int j = i + 1;j< arraySize; j++) {
            if (newMinimum > originalArray[j]) {
                newMinimum = originalArray[j];
                newMinimumIndex = j;
            }
        }
        //Swap the currentMinimum with newMinimum if the new Minimum index is updated
        if (newMinimumIndex != -1) {
            originalArray[i] = originalArray[newMinimumIndex];
            originalArray[newMinimumIndex] = currentMinimum;
        }
        //Reset the new Minimum index to 1
        newMinimumIndex = -1;
    }
}