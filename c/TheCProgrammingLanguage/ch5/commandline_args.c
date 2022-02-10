#include <stdio.h>

int main(int argc, char* argv[]) {
    while (--argc > 0) {
        printf("%s ", *++argv);
    }
    // int i;

    // for ( i = 1 ; i < argc ; i++ ) {
    //     printf("%s ", argv[i]);
    // }
    // printf("\n");
    return 0;
}