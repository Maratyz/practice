#include <stdio.h>
#define SIZE 10

// extern int e;

int main() {
    int i ;
    static int s;
    register int r;
    int a[SIZE], n;
    // printf("automatic: %d\nstatic: %d\nregister: %d\nextern: %d", i, s, r, e);
    printf("automatic: %d\nstatic: %d\nregister: %d\n", i, s, r);
    for (n = 0 ; n < SIZE ; n++) {
        printf("a[%d]: %d\n", n, a[n]);
    }

    return 0;
}