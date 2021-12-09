/*
Exercise 2-6. Write a function setbits(x,p,n,y) that 
returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
#include <stdio.h>
#include <limits.h>
void print_bin(unsigned int integer);
unsigned setbits(unsigned x, int p, int n, unsigned y);
int setbitsa(int,int,int,int);

int main() {
    unsigned x, y;
    x = 11;
    y = 5;
    int p,n;
    p = 3;
    n = 2;

    print_bin(x);
    print_bin(y);
    print_bin(setbits(x,p,n,y));
    print_bin(218);
    print_bin(9);
    print_bin(setbits(218, 2, 4, 9));
    print_bin(setbitsa(218, 2, 4, 9));

    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return ( (x & ~(~(~0 << n) << (p+1-n))) + ((y & ~(~0 << n) ) << (p+1-n)) );
}

int setbitsa(int x, int p, int n, int y)
{
	x = x & (~((~(~0 << n)) << p));
	y = (y & (~(~0 << n))) << p;

	return x | y;
}

void print_bin(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1)); 
    }
    putchar('\n');
}