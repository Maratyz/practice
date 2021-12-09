/*
    “Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.”
*/

#include <stdio.h>

#define MAXLINE 10


int mygetline(char line[], int maxline);
void copyWithTrim(char to[], char from[]);

int main() {
    int loadedLen;
    char line[MAXLINE];
    char trimmedLine[MAXLINE];

    while ( (loadedLen=mygetline(line, MAXLINE)) > 0) {
        copyWithTrim(trimmedLine, line);
        if ( trimmedLine[0] == '\0' ) {
            printf("%s", trimmedLine);
        }
    }
    return 0;
}

int mygetline(char s[], int lim) {
    int c, i, len;

    for ( i = 0 ; i < lim && ( c=getchar() ) != EOF && c != '\n' ; ++i )
        s[i] = c;
    if ( c == '\n') {
        s[i] = c;
        ++i;
    }
    len = i ;
    for ( i = len - 2 ; i > 0 && ( s[i] == ' ' || s[i] == '\t' ) ; --i )
        ;
    s[i+1] = '\n' ;
    s[i+2] = '\0' ;


    return len;
}

void copyWithTrim(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}