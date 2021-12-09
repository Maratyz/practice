#include <stdio.h>

int bitcount(unsigned);
int fastbitcount(unsigned);

int main() {
    int x;
    x = 0777;
    printf("%d\n", bitcount(x));
    printf("%d\n", fastbitcount(x));
}

int bitcount(unsigned x) {
    int b;

    for (b=0; x!=0; x >>= 1)
        if (x & 01)
        b++;
    return b;
}

int fastbitcount(unsigned x) {
    int b;
    for (b=0; x>0;x&=(x-1))
        b++;
    return b;
}