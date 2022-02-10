#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = "hello world";
    printf("%g\n", atof(s));
    printf("%.20f\n", atof(s));
    return 0;
}