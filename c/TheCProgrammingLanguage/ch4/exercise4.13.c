/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.”
*/

#include <stdio.h>
#define MAXLEN 1000

void reverse(char s[], int left, int right);
void swap(char s[], int i, int j);

int main() {
    char s[] = "abcd";
    reverse(s, 0, 3);
    printf("%s\n",s);
}

void reverse(char s[], int left, int right) {
    if ( left >= right ) {
        return;
    }
    swap(s, left, right);
    reverse(s, ++left, --right);
}

void swap(char s[], int i, int j) {
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
