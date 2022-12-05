
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "array_utils.h"

int contains(const int *arr, int size, int x) {

    for(int i=0; i<size; i++) {
        if(arr[i] == x) {
            return 1;
        }
    }
    return 0;
}



int containsWithin(const int *arr, int size, int x, int i, int j) {

    int k;
    for(k=i; k<=j; k++ ) {
        if(arr[k] == x) {
            return 1;
        }
    }
    return 0;
}


int * paddedCopy(const int *arr, int oldSize, int newSize) {

    if(arr == NULL || oldSize < 0 || newSize < 0) {
        return NULL;
    }

    int *newArray = (int *) malloc(newSize * sizeof(int));
    for(int i=0; i<newSize; i++) {
        newArray[i] = arr[i];
    }

    if(newSize < oldSize) {
        for(int i=0; i<newSize; i++) {
            newArray[i] = arr[i];
        }
    } else {
        for(int i=0; i<newSize; i++) {
            if(i<oldSize) {
            newArray[i] = arr[i];
            } else {
                newArray[i] = 0;
            }
       }

    }


    return newArray;
}





void reverse(int *arr, int size) {
    int *newArray = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
        newArray[size - 1 - i] = arr[i];
    }
    for(int i=0; i<size; i++) {
        arr[i] = newArray[i];
    }
}




int * reverseCopy(const int *arr, int size) {
    if(arr == NULL || size<=0) {
        return NULL;
    }

    int *newArray = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
        newArray[size - 1 - i] = arr[i];
    }
    return newArray;

}