/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations 
like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
Allow for letters of either case and digits, and be prepared to handle cases 
like a-b-c and a-z0−9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/
#include <stdio.h>

#define MAX_LENGTH 1000
#define STACK_SIZE 3

void expand(char s1[], char s2[]);
int isAlphaNum(char c); 

int main() {
    char s2[MAX_LENGTH];
    char s1[] = "-a-c-f0-3-9-";

    expand(s1,s2);
    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j, k;
    char stack[STACK_SIZE];

    for (i=0,j=0 ; s1[i] != '\0' && j < MAX_LENGTH ; i++) {
        if (isAlphaNum(s1[i]) && s1[i+1] == '-' &&  isAlphaNum(s1[i+2])) {
            stack[0] = s1[i], stack[1] = s1[i+1], stack[2] = s1[i+2] ;
            i += 1;
            for ( k=0 ; k < stack[2]-stack[0]; k++) {
                s2[j++] = stack[0] + k ;
            }
        } else if (isAlphaNum(s1[i])) {
            s2[j++] =s1[i];
        }
    }
}

int isAlphaNum(char c) {
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return 1;
    if ( (c >= '0' && c <= '9') )
        return 1;
    return 0;
}