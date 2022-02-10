#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    int found = 0;
    int r,c;

    while (mygetline(line, MAXLINE) > 0) {
        // if ((r=strrindex(line, pattern)) >= 0)  {
        //     printf("%d",r);
        // }
        r=strrindex(line, pattern);
        c=strindex(line, pattern);
        printf("%d, %d\n",r, c);
    }
    return 0;
}
