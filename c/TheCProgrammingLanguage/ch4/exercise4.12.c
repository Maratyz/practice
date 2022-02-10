/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive routine
*/

#include <stdio.h>
#define MAXLEN 1000

void recursiveItoa(int, char[]);


int main() {
    char s[MAXLEN];
    recursiveItoa(1111, s);
}


void recursiveItoa(int n, char s[]) {
    static int digit ;
    if ( n < 0 ) {
        s[0] = '-';
        n = -n ;
    }
    if ( n / 10 ) {
        recursiveItoa(n, s);
    } 
    s[digit++] = n % 10 + '0';

}