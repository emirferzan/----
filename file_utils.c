#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000

#include "file_utils.h"



char *getFileContents(const char *filePath) {

    FILE *f = fopen(filePath, "r");
    if(f == NULL) {
        return NULL;
    }

    int countC = 0;
    char c = fgetc(f);
    while( c != EOF) {
        countC++;
        c = fgetc(f);
    }

    char *newString = (char *) malloc(sizeof(char) * (countC+1));

    rewind(f);
    int i=0;
    char d = fgetc(f);
    while( d != EOF) {
        newString[i] = d;
        d = fgetc(f);
        i++;
    }
        newString[i] = '\0';
        fclose(f);

    return newString;

}

char **getFileLines(const char *filePath, int *numLines) {

    FILE *fp = fopen(filePath, "r");

    if(fp == NULL || numLines == NULL) {
        return NULL;
    }

    int countLines = 0;
    char tempbuffer[BUFFER_SIZE];
    char *buffer = fgets(tempbuffer, BUFFER_SIZE, fp);
    while(buffer != NULL) {
        countLines++;
        buffer = fgets(tempbuffer, BUFFER_SIZE, fp);
    }
    *numLines = countLines;

     char **linesString = (char **) malloc(sizeof(char *) * countLines);
     rewind(fp);
     int len = 0;
     char buffertwo[BUFFER_SIZE];

        for(int i=0; i<countLines; i++) {
            fgets(buffertwo, BUFFER_SIZE, fp);
            len = strlen(buffertwo);
            if (buffertwo[len-1] == '\n') {
                buffertwo[len-1] = '\0';
            }
            linesString[i] = (char *) malloc(sizeof(char) * len);
            strcpy(linesString[i], buffertwo);

        }


    fclose(fp);

    return linesString;
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



int removeAllWhiteSpace(char *s) {
    
    int n = strlen(s);
    char *temp = (char *) malloc(sizeof(char) * (n+1));
    int j=0;
    for(int i=0; i<n; i++) {
        if(!isspace(s[i])) {
            temp[j] = s[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(s, temp);
    return 0;
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