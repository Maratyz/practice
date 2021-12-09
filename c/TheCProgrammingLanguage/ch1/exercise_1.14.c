/*
    “Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.”
*/

#include <stdio.h>

#define UPPER_LIMIT 128 // upper bound of ASCII table

int main() {
    int c, i ; 
    int charCount[UPPER_LIMIT] ;

    for ( i = 0 ; i < UPPER_LIMIT ; i++) {
        charCount[i] = 0 ;
    }

    while ( ( c = getchar() ) != EOF )
        ++charCount[c];

    printf("char frequency\n") ;

    for ( i = 0 ; i < UPPER_LIMIT ; i++ ) {
        printf("%c: %d\n", i, charCount[i]);
    }
}