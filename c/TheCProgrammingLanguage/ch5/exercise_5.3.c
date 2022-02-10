/*
ch2 version
void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
    ;
}

“Exercise 5-3. Write a pointer version of the function strcat 
that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.”

*/

#include <stdio.h>

#define MAXLEN 1000

void mystract(char*, char*);

int main() {
    char h[] = "hello";
    char w[] = " world";
    char l[] = " hasta la vista";
    mystract(h,w);
    mystract(h,l);
    printf("%s\n", h);
    return 0;

}

void mystract(char *s, char *t) {
    while ( *(s++) != '\0' )
        ;
    s--;
    for  ( ;*t != '\0' ; ) {
        *s = *t;
        s++, t++;
    }
    *s = '\0';
}