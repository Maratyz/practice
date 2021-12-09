# include <stdio.h>

// Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

# define SPACE 1
# define NONSPACE 0

int main() {
    int c, prev;

    prev = NONSPACE ;

    while ( ( c = getchar() ) != EOF ) {
        if ( c != ' ' ) {
            putchar(c) ;
            prev = NONSPACE ;
        }
        else {
            if ( prev != SPACE ) {
                putchar(' ');
                prev = SPACE ;
            }
        }
    }
}