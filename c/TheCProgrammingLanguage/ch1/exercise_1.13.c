/*
    “Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. 
    It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.”
*/

#include <stdio.h>

#define UPPER_LIMIT 20
#define IN 1
#define OUT 0

int main() {
    int c, i, wl, state, otherCount ;
    int hist[UPPER_LIMIT] ;

    wl = otherCount  = 0 ;
    state = OUT ;

    for ( i = 0 ; i < UPPER_LIMIT ; i++)
        hist[i] = 0;

    while ( ( c = getchar() ) != EOF ) {
        if ( c == '\t' || c == ' ' || c == '\n') {
            if ( state == IN ) {
                if ( wl < UPPER_LIMIT)
                    ++hist[wl] ;
                else
                    ++otherCount ;
                wl = 0 ;
            }
            state = OUT ;
        } else {
            state = IN ;
            ++wl ;
        }
    }

    printf("histgram\n");
    for ( i = 0 ; i < UPPER_LIMIT ; i++) {
        printf("%d: %d\n", i, hist[i]) ;
    }
    printf("above %d: %d\n", UPPER_LIMIT, otherCount) ;

}