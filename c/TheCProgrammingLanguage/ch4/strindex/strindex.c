#include <stdio.h>
int strindex(char s[], char t[]) {
    int i,j,k;

    for ( i = 0 ; s[i] != '\0' ; i++ ) {
        for ( j = i, k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++);
        if ( k > 0 && t[k] == '\0') {
            return i;
        }
    }

    return -1 ;
}

/*

“Exercise 4-1. Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or −1 if there is none.”
*/
int strrindex(char s[], char t[]) {
    int i,j,k,r;
    r = -1;

    for ( i = 0 ; s[i] != '\0' ; i++ ) {
        for ( j = i, k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++) {
            if ( k > 0 && t[k+1] == '\0') {
                r = i;
                k = 0;
                i = ++j;
            }
        }
    }

    return r ;
}
