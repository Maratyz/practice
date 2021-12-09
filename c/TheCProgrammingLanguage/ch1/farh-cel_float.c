#include <stdio.h>

int main() {
    float fahr, celsiuis;
    float lower, upper, step;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    fahr = lower;
    printf("%s\t%s\n", "Fahr", "Cels");
    while (fahr <= upper) {
        celsiuis = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.3f\n", fahr, celsiuis);
        fahr = fahr + step;
    }
}