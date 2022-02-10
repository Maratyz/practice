#include <stdio.h>
#include <unistd.h>


#define forever for (;;) /* infinite loop */
#define myprint(expr) printf(#expr " = %g\n", expr)
#define swap(t,x,y) { \
    t temp ; \
    temp = x ; \
    x = y ; \
    y = temp ; }

int main() {
    int a = 1;
    int b = 2; 
    swap(int, a, b);
    printf("a: %d, b: %d\n", a, b);
    return 0;
}