#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "string_utils.h"




int main(int argc, char **argv) {

    char test[] = "University";
    char expectedOutput[] = "Univarsity";
    char *actualOutput = replaceCharCopy(test, 'e', 'a');
    if( strcmp(expectedOutput, actualOutput) == 0) {
        printf("replaceCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", expectedOutput, actualOutput);
    }
    free(actualOutput);

    char testtwo[] = "nebraska";
    char testtwoexpected[] = "nebreske";
    char *testtwoactual = replaceCharCopy(testtwo, 'a', 'e');
    if( strcmp(testtwoexpected, testtwoactual) == 0) {
        printf("replaceCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", testtwoexpected, testtwoactual);
    }
    free(testtwoactual);

    char testthree[] = "school";
    char tte[] = "schaal";
    char *tta = replaceCharCopy(testthree, 'o', 'a');
    if( strcmp(tte, tta) == 0) {
        printf("replaceCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", tte, tta);
    }

    free(tta);


    char teststringfour[] = "computer";
    char tempfour[] = "cumputer";
    replaceChar(teststringfour, 'o', 'u');
    if( strcmp(tempfour, teststringfour) == 0) {
        printf("replaceChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", tempfour, teststringfour);
    }


    char teststringtwo[] = "lincoln";
    char temp[] = "oincoon";
    replaceChar(teststringtwo, 'l', 'o');
    if( strcmp(temp, teststringtwo) == 0) {
        printf("replaceChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", temp, teststringtwo);
    }



    char teststringthree[] = "univerisy";
    char temptwo[] = "univsrisy";
    replaceChar(teststringthree, 'e', 's');
    if( strcmp(temptwo, teststringthree) == 0) {
        printf("replaceChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", temptwo, teststringthree);
    }



    char removeTest[] = "computer";
    char expectedChar[] = "comuter";
    char *actualChar = removeCharCopy(removeTest, 'p');
    if( strcmp(expectedChar, actualChar) == 0) {
        printf("removeCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", expectedChar, actualChar);
    }
    free(actualChar);

    char removeTestTwo[] = "library";
    char expectedChartwo[] = "libay";
    char *actualChartwo = removeCharCopy(removeTestTwo, 'r');
    if( strcmp(expectedChartwo, actualChartwo) == 0) {
        printf("removeCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", expectedChartwo, actualChartwo);
    }
    free(actualChartwo);

    char removeTestThree[] = "emirferzan";
    char expectedCharThree[] = "mirfrzan";
    char *actualCharThree = removeCharCopy(removeTestThree, 'e');
    if( strcmp(expectedCharThree, actualCharThree) == 0) {
        printf("removeCharCopy function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", expectedCharThree, actualCharThree);
    }
    free(actualCharThree);


    char testRemove[] = "computer science";
    char tempremove[] = "omputer siene";
    removeChar(testRemove, 'c');
    if( strcmp(testRemove, tempremove) == 0) {
        printf("removeChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", tempremove, testRemove);
    }


    char testRemoveTwo[] = "I love computer science";
    char tempremoveTwo[] = "I lve cmputer science";
    removeChar(testRemoveTwo, 'o');
    if( strcmp(testRemoveTwo, tempremoveTwo) == 0) {
        printf("removeChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", tempremoveTwo, testRemoveTwo);
    }



    char testRemoveThree[] = "hello world my name is emir";
    char tempremoveThree[] = "heo word my name is emir";
    removeChar(testRemoveThree, 'l');
    if( strcmp(testRemoveThree, tempremoveThree) == 0) {
        printf("removeChar function PASSED!\n");
    } else {
        printf("Failed. Expected: %s, returned: %s\n", tempremoveThree, testRemoveThree);
    }




    char *s = "hello world, how are you?";
    char **output = lengthSplit(s, 3);
    char **expectedSplit = lengthSplit(s, 3);
    int length = strlen(s);
    int total = length/3 + (length%3 == 0 ? 0 : 1);
    int passed = 0, failed = 0;


    for(int i=0; i<total; i++) {
        if(strcmp(output[i], expectedSplit[i]) == 0) {
            passed = 1;
        } else {
            failed = 1;
        }

    }
    if(passed == 1) {
        printf("lengthSplit function PASSED!\n");
    } else if (failed ==  1) {
        printf("FAILED! noob\n");
    }

    char *a = "My name is emir, I love computers";
    char **outputOne = lengthSplit(a, 4);
    char **expectedSplitOne = lengthSplit(a, 4);
    int lengthOne = strlen(a);
    int totalOne = lengthOne/4 + (lengthOne % 4 == 0 ? 0 : 1);
    int passedOne = 0, failedOne = 0;


    for(int i=0; i<totalOne; i++) {
        if(strcmp(outputOne[i], expectedSplitOne[i]) == 0) {
            passedOne = 1;
        } else {
            failedOne = 1;
        }

    }
    if(passedOne == 1) {
        printf("lengthSplit function PASSED!\n");
    } else if (failedOne ==  1) {
        printf("FAILED! noob\n");
    }

    char *h = "This is a splitted function";
    char **outputTwo = lengthSplit(h, 2);
    char **expectedSplitTwo = lengthSplit(h, 2);
    int lengthTwo = strlen(h);
    int totalTwo = lengthTwo/5 + (lengthTwo % 2 == 0 ? 0 : 1);
    int passedTwo = 0, failedTwo = 0;


    for(int i=0; i<totalTwo; i++) {
        if(strcmp(outputTwo[i], expectedSplitTwo[i]) == 0) {
            passedTwo = 1;
        } else {
            failedTwo = 1;
        }

    }
    if(passedTwo == 1) {
        printf("lengthSplit function PASSED!\n");
    } else if (failedTwo ==  1) {
        printf("FAILED! noob\n");
    }

 return 0;
}