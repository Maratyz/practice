#include <stdio.h>

int mystrncmp(char*, char*, int);

int main() {
    char *src = "hello";
    char *dst = "hell";
    printf("%d\n", mystrncmp(src, dst, 4));
    return 0;
}

int mystrncmp(char *s, char *t, int n) {

    for ( ; *s == *t && n > 0 ; n--, s++, t++)
        if (*s == '\0')
            return 0;

    if ( n == 0 ) {
        return 0;
    }
    return *s - *t;
}