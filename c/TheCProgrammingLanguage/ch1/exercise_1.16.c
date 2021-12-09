/*
    “Exercise 1-16. Revise the main routine of the longest-line program so it will correctly 
    print the length of arbitrarily long input lines, and as much as possible of the text.”
*/

#include <stdio.h>

#define MAXLINE 10


int getLineWithTrim(char line[], int maxline);
void copyWithTrim(char to[], char from[]);

int main() {
    int len, loadedLen;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0 ;

    while ( (loadedLen=getLineWithTrim(line, MAXLINE)) > 0) {
        if (line[MAXLINE-1] == '\n') {
            len = 0;
        } else {
            len = len + loadedLen;
        }
        if (len>max) {
            max = len;
            copyWithTrim(longest, line);
            printf("%s", longest);
        }
    }
    if (max>0)
        printf("length: %d, content: %s", max, longest);
    return 0;
}

int getLineWithTrim(char s[], int lim) {
    int c, i;

    for ( i = 0 ; i < lim && ( c=getchar() ) != EOF && c != '\n' ; ++i )
        s[i] = c;
    if ( c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copyWithTrim(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}