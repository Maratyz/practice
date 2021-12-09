/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.”
x=001, n=3 -> x=100

*/
#include <limits.h>
void print_bin(unsigned int integer);

void print_bin(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1)); 
    }
    putchar('\n');
}