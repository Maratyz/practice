
#include <stdio.h>

void testRegister(int);

int main() {
    testRegister(1000000);
}

void testRegister(int n) {
    register double pos ;
    int i ;
    for (i = 0 ; i < n ; i++) {
        pos += i ;
    }
    printf("pos: %g\n", pos);
}