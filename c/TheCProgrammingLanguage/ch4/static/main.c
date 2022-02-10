#include <stdio.h>

void testStatic(int);

int main() {
    testStatic(1000000);
}

void testStatic(int n) {
    static double pos ;
    int i ;
    for (i = 0 ; i < n ; i++) {
        pos += i ;
    }
    printf("pos: %g\n", pos);
}