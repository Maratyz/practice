#include <stdio.h>

int myAtoi(char s[]);

int main() {
    int n ;
    n = myAtoi("123") ;
    printf("%d\n", n) ;
    
    return 0;
}

int myAtoi(char s[]) {
    int n, i ;
    n = 0 ;

    for (i = 0; s[i] > '0' && s[i] <= '9'; ++i) {
        n = ( s[i] - '0' ) + 10 * n ;
    }

    return n ; 
}