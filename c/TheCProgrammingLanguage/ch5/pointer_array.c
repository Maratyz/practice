#include <stdio.h>

int main() {
    int a[] = {1,3,5};
    int *p ;
    p = a;
    printf("p: %p, *p: %d, a: %p, a[0]: %d, p+1: %p, *(p+1): %d, a[1]:%d, *(p+5): %d\n ", p, *p, a, a[0], p+1, *(p+1), a[1], *(p+5));
    return 0;
    
}