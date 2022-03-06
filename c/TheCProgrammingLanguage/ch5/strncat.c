#include <stdio.h>

void mystrncat(char*, int);

int main() {
    char *src = "hello world";
    mystrncat(src, 3);
    mystrncat(src, 7);
    mystrncat(src, 10);
    return 0;
}

void mystrncat(char* s, int n) {
    for ( ; n > 0 && *s != '\0' ; n--, s++) {
        printf("%c", *s);
    } 
    printf("\n");
}