#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binomial.h"

int main(int argc, char **argv) {

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    long **cache = (long **) malloc(sizeof(long *) * (n+1));
    for(int i=0; i<n+1; i++) {
    cache[i] = (long *) malloc((k+1) * sizeof(long));
    for(int j=0; j<k+1; j++) {
        cache[i][j] = -1;
      }
  }


    long resultPascal = chooseMemoization(n, k, cache);
    printf("%ld\n", resultPascal);

    return 0;
}