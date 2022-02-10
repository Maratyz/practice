/*
Exercise 5-4. Write the function strend(s,t), 
which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
*/

#include <stdio.h>

int strend(char*, char*);

int main() {
    printf("%d\n", strend("hello", "world"));
    printf("%d\n", strend("electricity","city"));
    return 0;
}

int strend(char* s, char* t) {
    char* start = t;
    for ( ; *s != '\0' ; s++)
        ;
    for ( ; *t != '\0' ; t++)
        ;
    for ( ; *s == *t ; t--, s--)
        if ( t == start ) {
            return 1;
        }
    return 0;
}