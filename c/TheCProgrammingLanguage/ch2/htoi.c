/*

“Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F.”

*/

#include <stdio.h>

int htoi(char hex[]);

int main() {
    printf("%d\n", htoi("0xabc")) ;
    printf("%d\n", htoi("0Xabc")) ;
    printf("%d\n", htoi("abc")) ;
}

int htoi(char hex[]) {
    int i ;
    int n ;
    n = 0 ;

    for ( i = 0 ; hex[i] != '\0' ; i++) {
        if ( i == 0 && hex[i+1] == 'x' || hex[i+1] == 'X' ) {
            i = 2 ;
        }        
        if ( hex[i] > '0'-1 && hex[i] < '9'+1 ) {
            n = hex[i] - '0' + n*16 ;
        }
        if ( hex[i] > 'a'-1 && hex[i] < 'f'+1 ) {
            n = hex[i] - 'a' + 10 + n*16 ;
        }
        if ( hex[i] > 'A'-1 && hex[i] < 'F'+1 ) {
            n = hex[i] - 'A' + 10 + n*16 ;
        }
    }
    return n ;
}

