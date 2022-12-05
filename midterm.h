
typedef enum {
    NO_ERROR,
    NULL_ERROR,
    RADIUS_LESS,
    HEIGHT_LESS,
    SIZE_LESS
}ErrorCode;



/**
 * takes radius and height as inputs and computes the volume and weight
 */
int getCornStats(double radius, double height, double *volume, double *weight);
/**
 * TODO: documentation
 */
int fizzBuzzSum(const int *arr, int n, int *huskerTotal, int *mavTota);
/**
 * TODO: documentation
 */
int *merge(const int *a, int n, const int *b, int m);
/**
 * This function has been provided for you
 */
void printArray(const int *arr, int n);