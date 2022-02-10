/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. 
What type does getfloat return as its function value?”
*/

#include <stdio.h>
#include <ctype.h>
#define FALSE 0 
#define TRUE 1
#define SIZE 10

int getch(void);
void ungetch(int);


int main() {
    int n,  getint(int *);
    float array[SIZE], mygetfloat(float *);
    for ( n = 0 ; n < SIZE ; n++) {
        array[n] = 0.0;
    }
    for ( n = 0 ; n < SIZE && mygetfloat(&array[n]) != EOF ; n++)
        printf("%f\n", array[n]);
    return 0;
}

float mygetfloat(float *pf) {
    int f, sign, scaleDown ;
    scaleDown = 1;
    int afterDecimal = FALSE;

    while (isspace(f = getch()))
        ;

    while (!isdigit(f) && f != EOF && f != '+' && f != '-' && f != '.') {
        ungetch(f);
        return 0;
    }
    sign = ( f == '-' ) ? -1.0 : 1.0 ;
    if ( f == '+' || f == '-' )
        f = getch();
    for (*pf = 0 ; isdigit(f) || f == '.' ; f = getch()) {
        if ( f == '.' ) {
            afterDecimal = TRUE ;
            continue;
        }
        *pf = 10* *pf + ( f - '0' );
        if ( afterDecimal ) {
            scaleDown *= 10 ;
        }
    }
    *pf *= (float)sign ;
    *pf = *pf / (float)scaleDown ;
    if ( f != EOF )
        ungetch(f);
    return f ;
}