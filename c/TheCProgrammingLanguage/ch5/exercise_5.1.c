/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. 
Fix it to push such a character back on the input.”
*/

#include <stdio.h>
#include <ctype.h>
#define SIZE 1000

int getch(void);
void ungetch(int);

int main() {
    int n, array[SIZE], getint(int *), c;
    for ( n = 0 ; n < SIZE ; n++) {
        array[n] = 0;
    }
    for ( n = 0 ; n < SIZE && getint(&array[n]) != EOF ; n++)
        printf("%d\n", array[n]);
    return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = ( c == '-' ) ? -1 : 1 ;

    if ( c == '+' || c == '-' ) {
        c=getch();
        if ( !isdigit(c) ) {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c) ; c = getch())
        *pn = 10 * *pn + ( c - '0') ;

    *pn *= sign ;

    if ( c != EOF )
        ungetch(c);
    return c;
}