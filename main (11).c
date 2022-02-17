#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

long int countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    int64_t MOD=1e9+7;
    int64_t eq_x = 0;
    int64_t neq_x = 0;
    if (x == 1) {
        eq_x = 1;
        neq_x = 0;
    } else {
        eq_x = 0;
        neq_x = 1;
    }
    for (int i = 1; i < n; i++) {
        int64_t eq_x1 = neq_x;
        int64_t neq_x1 = (k-1) * eq_x + (k-2) * neq_x;

        eq_x = eq_x1 % MOD;
        neq_x = neq_x1 % MOD;
    }
    return eq_x;
}

int main() {
    int n; 
    int k; 
    int x; 
    scanf("%i %i %i", &n, &k, &x);
    long int answer = countArray(n, k, x);
    printf("%ld\n", answer);
    return 0;
}
