#include <stdio.h>

int main() {
    int fahr, celsiuis;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsiuis = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsiuis);
        fahr = fahr + step;
    }
}