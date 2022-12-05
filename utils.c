#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1000

#include "utils.h"

char * deepStringCopy(const char *str) {
    char *copy = (char *) malloc(sizeof(char) * strlen(str));
    return copy;
}

void getFileContents(char *filePath, char *fileOutput) {

    FILE *f = fopen(filePath, "r");
    FILE *output;
    output = fopen(fileOutput, "w");
    if(f == NULL || output == NULL) {
        exit(1);
    }

    int countC = 0;
    char c = fgetc(f);
    while( c != EOF) {
        countC++;
        c = fgetc(f);
    }
    rewind(f);
    fseek(f, -1, SEEK_END);
    while(countC > 0 ) {
        char character = fgetc(f);
        fputc(character, output);
        fseek(f, -2, SEEK_CUR);
        countC--;
    }

    fclose(f);
    fclose(output);
}

// char  *reverseChars(char *filePath) {
//     FILE *fc = fopen(filePath, "r");


//     char tempbuffer[1000];
//     char *buffer = fgets(tempbuffer, 1000, fc);

//     while(buffer != NULL) {
//         int len = (strlen(buffer));

//         for(int i=0; i<len/2; i++) {
//             char temp = buffer[i];
//             buffer[i] = buffer[len - 1 - i];
//             buffer[len - 1 - i] = temp;
//     }

//         buffer = fgets(tempbuffer, BUFFER_SIZE, fp);
//     }


//     fclose(fc);
//     return fc;
// }

// char *lastLine(char *filePath) {
//     FILE *p = fopen(filePath, "r")
//     char tempbuffer[1000];
//     char *buffer = fgets(tempbuffer, 1000, fp);
//     while(buffer != NULL) {
//         buffer = fgets(tempbuffer, BUFFER_SIZE, fp);
//     }
//     return buffer;
// }

// char *reverseLines(char *filePath) {
//     FILE *rc = reverseChars(filePath, "r");

//     char tempbuffer[1000];
//     char *buffer = fgets(tempbuffer, 1000, rc);
//     int count = 0;

//     while(buffer != NULL) {
//         count++;
//         buffer = fgets(tempbuffer, 1000, rc);
//     }

//     rewind(rc);
//     char tb[1000];
//     char *newLine = fgets(tb, 1000, rc);

//     for(int i = 0; i<count/2; i++) {
//         int lenghtof = strlen(newline);
//         char *tempLine = (char *) malloc(sizeof(char) * lenghtof);
//         strcpy(tempLine, newLine);

//     }
// }