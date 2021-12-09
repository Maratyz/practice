#include <stdio.h>

int main() {
    int a[10] = {1,1,2,2,3,3,5} ;
    int i, x ;
    x = 0;
    for (i= 0 ; i < 10 ; i++) 
        x ^= a[i]; 
    ;
    printf("duplicated number : %d\n", x);
    return 0;
}