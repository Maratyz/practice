#include <stdio.h>

char *month_name(int);
int main() {
    int day_of_months[2][13] = {
        {
            0,31,28,31,30,31,30,31,31,30,31,30,31
        },
        {
            0,31,29,31,30,31,30,31,31,30,31,30,31
        }
    };

    printf("%d\n", day_of_months[0][2]);
    printf("%s\n", month_name(3));
    return 0;
}

char *month_name(int n) {
    static char *name[] = {
        "Illegal Month",
        "January", "Feburary", "March", "Apr", "May", "June",
        "July", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    return ( n < 1 || n > 12 ) ? name[0] : name[n];
}