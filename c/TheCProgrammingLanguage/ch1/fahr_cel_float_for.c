#include <stdio.h>

#define LOWER 0.0 // lower limit
#define UPPER 200.0 // upper limit
#define STEP 30.0

void fToC(float f);
void fToCR(float f);
float conversion(float f);

int main() {
    float fahr ;
    fToC(fahr) ;
    fToCR(fahr) ;
}

void fToC(float fahr) {
    for (fahr = LOWER ; fahr <= UPPER ; fahr += STEP ) {
        printf("%3.0f\t%6.1f\n", fahr, conversion(fahr));
    }
}

void fToCR(float fahr) {
    printf("reverse order\n");
    for (fahr = UPPER ; fahr >= LOWER ; fahr -= STEP ) {
        printf("%3.0f\t%6.1f\n", fahr, conversion(fahr));
    }
}

float conversion(float fahr) {
    return (5.0/9.0)*(fahr-32.0) ;
}