#include <stdio.h>

int main() {
    int c, ns, nt, nl;

    ns = nt = nl = 0 ;
    while ( ( c = getchar() ) != EOF) {
        if ( c == ' ' )
            ++ns;
        if ( c == '\t' ) 
            ++nt;
        if ( c == '\n' )
            ++nl;
    }
    
    printf("space: %d, tabs: %d, newline: %d", ns, nt, nl);
}