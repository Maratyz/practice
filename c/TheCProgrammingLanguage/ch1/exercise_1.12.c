#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state ;
    state = OUT ;

    while ( ( c = getchar() ) != EOF ) {
        if ( c == '\t' || c == ' ' || c == '\n' ) {
            if ( state == IN )
                putchar('\n') ;
            state = OUT ;
        }
        else {
            state = IN ;
            putchar(c) ;
        }
    }
}
