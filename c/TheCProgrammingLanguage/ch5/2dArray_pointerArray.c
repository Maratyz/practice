#include <stdio.h>

int main() {
    int n ;
    char *name[] = { "Illegal month", "January", "Feburary", "March" };
    char aname[][20] = { "Illegal month", "January", "Feburary", "March" };

    for ( n = 0 ; n < 4 ; n++ ) {
        printf("%s\t%s\n", name[n], aname[n]);
        printf("%lu\t%lu\n", sizeof(name[n]), sizeof(aname[n]));
    }

    return 0;
}