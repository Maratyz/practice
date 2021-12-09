/*
Exercise 3-2. Write a function escape(s,t) that converts characters 
like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. 
Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.”
*/

#include <stdio.h>

void escape(char s[], char t[]);
#define MAX_LEN 1000

int main() {
    char s[MAX_LEN];
    char t[] = "1\t2\n3" ;
    printf("%s\n", t) ;
    escape(s,t) ;
    printf("%s\n", s) ;
    return 0;
}

void escape(char s[], char t[]) {
    int i ;
    int j ;
    for ( i = 0, j = 0 ; t[i] != '\0' && s[j] != '\0' ; i++, j++) {
        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j] = 't'; 
                break;
            case '\n':
                s[j++] = '\\';
                s[j] = 'n'; 
                break;
            default:
                s[j] = t[i] ;
        }
    }
}