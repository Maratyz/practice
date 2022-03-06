/*
“Exercise 5-5. Write versions of the library functions 
strncpy, strncat, and strncmp, 
which operate on at most the first n characters of their argument strings. 
For example, strncpy(s,t,n) copies at most n characters of t to s. 
Full descriptions are in Appendix B.”

*/

#include <stdio.h>

char *mystrncpy(char*, char*, int);

int main() {
    char src[100];
    char *dst = "world";
    printf("%s\n", mystrncpy(src, dst, 3));
    return 0;
}

char *mystrncpy(char *src, char *dst, int n) {
    char *srcStart = src;
    // for ( ; n > 0 && ( *src++ = *dst++ ) != '\0' ; n-- )
    for ( ; n > 0 && ( *src++=*dst++ ) ; n-- )
        ;
    *src = '\0';
    return srcStart;
}
