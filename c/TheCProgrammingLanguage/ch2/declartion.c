#include <stdio.h>

void testGarbage() ;

int main() {
    static int testvar ;
    printf("%d\n", testvar) ;
    testGarbage();
}

void testGarbage() {
    int g ;
    int y ;
    printf("%d\n%d\nend", g, y) ;
}