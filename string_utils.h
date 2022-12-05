/**
This function takes one letter as input
goes through the string and replaces the letter input
with the new letter in the string it is going through
*/

void replaceChar(char *s, char oldChar, char newChar);

/**
this function make a copy of the changed string
*/

char * replaceCharCopy(const char*s, char oldChar, char newChar);

/**
this function removes the given letter from the string
*/

void removeChar(char *s, char c);

/**
this function makes and returns a copy of the string that
we changed and removed all the character from
*/

char * removeCharCopy(const char *s, char c);

/**
this function divided an array of string into
n size of strings*/

char **lengthSplit(const char *s, int n);

