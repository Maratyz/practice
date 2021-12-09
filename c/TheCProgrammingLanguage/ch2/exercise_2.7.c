/*
    Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted 
    (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include <stdio.h>
#include <limits.h>
void print_bin(unsigned int integer);
int invert(int, int, int);

int main() {
    int x = 123;
    unsigned m;
    print_bin(x);
    m = (~(~0u << 2)) << (4-2);
    print_bin(m);
    print_bin(invert(x, 4, 2));
    return 0;
}


int invert(int x, int p, int n) {
    int m, inverted;
    m = ~(~0 << n) << (p-n);
    inverted = x & ~m ;
    return inverted  ;
}

void print_bin(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1)); 
    }
    putchar('\n');
}