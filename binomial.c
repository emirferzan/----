#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binomial.h"




long choose(int n, int k) {
    if(k == 0 || n == k) {
        return 1;
    } else {
        return choose(n-1, k) + choose(n-1, k-1);
    }
}

long chooseMemoization(int n, int k, long **cache) {
    if(cache[n][k] != -1) {
        return cache[n][k];
    } else if (k == 0 || n == k) {
        return 1;
    } else {
        long a = chooseMemoization(n-1, k, cache);
        long b = chooseMemoization(n-1, k-1, cache);
        long result = a + b;
        cache[n][k] = result;
        return result;
    }


}