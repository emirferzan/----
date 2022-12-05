#include <stdlib.h>
#include <stdio.h>
#include "midterm.h"
#include <math.h>



int getCornStats(double radius, double height, double *volume, double *weight) {
  if(volume == NULL || weight == NULL) {
    return NULL_ERROR;
  } else if (radius <= 0) {
    return RADIUS_LESS;
  } else if (height <= 0) {
    return HEIGHT_LESS;
  } else {
    *volume = M_PI * (radius*radius) * height;
    *weight = *volume * 720.83;
  }
  return 0;
}
int fizzBuzzSum(const int *arr, int n, int *huskerTotal, int *mavTotal) {
  if(arr == NULL || huskerTotal == NULL || mavTotal == NULL) {
    return NULL_ERROR;
  } else if (n <= 0) {
    return SIZE_LESS;
  } else {
    int huskerScore = 0;
    int mavScore = 0;

    for(int i=0; i<n; i++) {
      if(arr[i] % 3 == 0 && arr[i] % 5 == 0) {
        huskerScore += arr[i];
        mavScore += arr[i];
      } else if(arr[i] % 3 == 0) {
        huskerScore += arr[i];
      } else if (arr[i] % 5 == 0) {
        mavScore += arr[i];
      }

    }
  *huskerTotal = huskerScore;
  *mavTotal = mavScore;
  }

  return 0;
}
int *merge(const int *a, int n, const int *b, int m) {
  if(a == NULL || b == NULL) {
    return NULL;
  } else if(n <= 0 || m <= 0) {
    return NULL;
  }
  int newSize = n + m;
  int *newArray = (int*) malloc( newSize * sizeof(int) );

  for(int i= 0; i<n; i++) {
    newArray[i] = a[i];
  }
  for(int j=n, k = 0; j<newSize && k<m; j++, k++) {
    newArray[j] = b[k];
  }

  return newArray;
}
void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}