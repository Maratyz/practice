#include <ctype.h>

double atfo(char s[]) {
    double val, power;
    int i, sign ;

    for ( i = 0 ; isspace(s[i]) ; i++)
        ;
    sign = ( s[i] == '-') ? -1 : 1 ;
    if (s[i] == '+')

    return sign * val / power ;
}