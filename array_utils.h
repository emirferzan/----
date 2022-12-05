/**
this array returns true if in the given array contains x anywhere
*/


int contains(const int *arr, int size, int x);

/**
determines if the array contains x within the range of i and j
return true if it does, false if not
*/

int containsWithin(const int *arr, int size, int x, int i, int j);

/**
given an array of integers, its size and a "new size" creates a new deep copy of the array.
However, instead of its original size, the new array should be of the new size.
If the new size is less than the old size, only the first newSize elements
should be copied over
*/

int * paddedCopy(const int *arr, int oldSize, int newSize);

/**
reverses the elements in an array
*/

void reverse(int *arr, int size);

/**
actually returns the new array that is reversed
*/

int * reverseCopy(const int *arr, int size);