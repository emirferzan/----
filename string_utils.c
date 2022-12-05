#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#include "string_utils.h"


char *deepStringCopy(const char *s) {
    char *copy = (char *) malloc( sizeof(char) * (strlen(s) +1 ) );
    strcpy(copy, s);


    return copy;


}

void replaceChar(char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return;
    }
    int n = strlen(s);
    for(int i=0; i<n; i++) {
        if(s[i] == oldChar) {
            s[i] = newChar;
        }
    s[n] = '\0';
    }
    return;
}

char * replaceCharCopy(const char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return NULL;
    }

    char *newCopy = deepStringCopy(s);
    replaceChar(newCopy, oldChar, newChar);

    return newCopy;

}

void removeChar(char *s, char c) {
    if(s == NULL) {
        return;
    }
    int n = strlen(s);
    char *temp = (char *) malloc(sizeof(char) * n+1);
    int j = 0;
    for(int i=0; i<n; i++) {
    if(s[i] != c) {
        temp[j] = s[i];
        j++;
        }
    }
    temp[j] = '\0';
    strcpy(s, temp);


    return;

}


char * removeCharCopy(const char *s, char c) {
    if(s == NULL) {
        return NULL;
    }
    char *copyOne = deepStringCopy(s);
    removeChar(copyOne, c);

    return copyOne;
}

char **lengthSplit(const char *s, int n) {

    if(s == NULL || n <= 0) {
        return NULL;
    }

    int length = strlen(s);

    int count = 0;
    int totSize = (length/n) + (length % n == 0 ? 0 : 1);

    char **newStringArray = (char **) malloc(sizeof(char *) * totSize);
    for(int i=0; i<totSize; i++) {
        newStringArray[i] = (char *) malloc(sizeof(char) * n);
    }

    // if(length % n == 0 ) {
    //     for(int i=0; i<totSize; i++) {
    //         for(int j=0; j<n; j++) {
    //         newStringArray[i][j] = s[count];
    //         count++;
    //         }
    //     }
    // } else {
        for(int i=0; i<totSize; i++) {
            for(int j=0; j<=n; j++) {
                if(j == n) {
                newStringArray[i][j] = '\0';
                } else {
                newStringArray[i][j] = s[count];
                count++;
                }
        }
    }
 return newStringArray;
}


