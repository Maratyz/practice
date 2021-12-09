#include <stdio.h>
#include <limits.h>

unsigned getbits(unsigned x, int p, int n);
void print_bin(unsigned int integer);

int main() {
    int x;
    x = 20;
    print_bin(x);
    print_bin(getbits(x,4,3));
    return 0;
}


unsigned getbits(unsigned x, int p, int n) {
    return ( x >> (p+1-n) & ~(~0 << n));
}

void print_bin(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1)); 
    }
    putchar('\n');
}