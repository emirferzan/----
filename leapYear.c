/**
 * This program determines if various years are leap
 * years or not.
 *
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Returns true (1) if the given year is a leap year,
 * false (0) if it is not a leap year.
 */
int isLeapYear(int year);

int main(int argc, char **argv) {

  int year;
  int numPassed = 0;
  int numFailed = 0;

  //Hard-coded ad-hoc test cases
  //Do not change these, add your own test cases
  //below.  All test cases should pass.

  year = 2000;
  printf("Test Case 1: year = %d: ", year);
  if(!isLeapYear(year)) {
    printf("FAILED!\n");
    numFailed = numFailed + 1;
  } else {
    printf("PASSED!\n");
    numPassed = numPassed + 1;
  }

  year = 2001;
  printf("Test Case 2: year = %d: ", year);
  if(isLeapYear(year)) {
    printf("FAILED!\n");
    numFailed = numFailed + 1;
  } else {
    printf("PASSED!\n");
    numPassed = numPassed + 1;
  }

  year = 2100;
  printf("Test Case 3: year = %d: ", year);
  if(isLeapYear(year)) {
    printf("FAILED!\n");
    numFailed = numFailed + 1;
  } else {
    printf("PASSED!\n");
    numPassed = numPassed + 1;
  }


  year = 2020;
  if(year % 400 == 0) {
    printf("Test Case 4: year = %d: ", year);
    printf("PASSED!\n");
  } else if(year % 100 == 0) {
    printf("Test Case 4: year = %d: ", year);
    printf("FAILED!\n");
  } else if(year % 4 == 0) {
    printf("Test Case 4: year = %d: ", year);
    printf("PASSED!\n");
  } else {
    printf("Test Case 4: year = %d: ", year);
    printf("FAILED!\n");
  }

  year = 2024;
  if(year % 400 == 0) {
    printf("Test Case 5: year = %d: ", year);
    printf("PASSED!\n");
  } else if(year % 100 == 0) {
    printf("Test Case 5: year = %d: ", year);
    printf("FAILED!\n");
  } else if(year % 4 == 0) {
    printf("Test Case 5: year = %d: ", year);
    printf("PASSED!\n");
  } else {
    printf("Test Case 5: year = %d: ", year);
    printf("FAILED!\n");
  }

  year = 2028;
  if(year % 400 == 0) {
    printf("Test Case 6: year = %d: ", year);
    printf("PASSED!\n");
  } else if(year % 100 == 0) {
    printf("Test Case 6: year = %d: ", year);
    printf("FAILED!\n");
  } else if(year % 4 == 0) {
    printf("Test Case 6: year = %d: ", year);
    printf("PASSED!\n");
  } else {
    printf("Test Case 6: year = %d: ", year);
    printf("FAILED!\n");
  }




  printf("\n\n");
  printf("Summary:\n");
  printf("Number of test cases passed: %d\n", numPassed);
  printf("Number of test cases failed: %d\n", numFailed);
  printf("Percentage Passed: %.2f%%\n", (double) numPassed / (numPassed + numFailed) * 100.0);

  return 0;
}

int isLeapYear(int year) {

if(year % 4 == 0) {
    if(year % 100 == 0) {
      if(year % 400 == 0) {
        return 1;
      } else {
        return 0;
      }
    } else if(year % 400 == 0) {
      return 1;
    } else {
      return 0;
    }

  } else {
    return 0;
  }

}