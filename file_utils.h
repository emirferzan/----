/**
this function get the contents of the file
and a returns a single string of all the contents
*/

char *getFileContents(const char *filePath);

/**
returns the contents of the file
as an array of strings
*/

char **getFileLines(const char *filePath, int *numLines);




void replaceChar(char *s, char oldChar, char newChar);


int removeAllWhiteSpace(char *s);



char **lengthSplit(const char *s, int n);