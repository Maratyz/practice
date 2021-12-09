/*
“Exercise 3-1. Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside). 
Write a version with only one test inside the loop and measure the difference in run-time.”
*/
#include <stdio.h>

#define LENGTH 10 

int binarySearch(int array[], int target);
int binarySearchOneTest(int array[], int target);

int main() {
    int array[LENGTH] = {1,2,2,3,3,5,6,7,9};

    printf("%d\n", binarySearchOneTest(array, 5));
    
    return 0;
}

int binarySearch(int array[], int target) {
    int lower, upper, mid ;
    lower = 0 ;
    upper = LENGTH - 1;
    while (upper > lower)
    {
        mid = lower + ( upper - lower ) / 2 ;
        if ( array[mid] > target ) {
            upper = mid - 1 ;
        } else if ( array[mid] < target ) {
            lower = mid + 1;
        } else {
            return mid ;
        }
    } 
    return -1 ;
}

int binarySearchOneTest(int array[], int target) {
    int lower, upper, mid ;
    lower = 0 ;
    upper = LENGTH - 1;
    while (upper > lower)
    {
        mid = lower + ( upper - lower ) / 2 ;
        if ( array[mid] > target ) {
            upper = mid - 1 ;
        } else {
            lower = mid + 1;
        }
    } 

    if ( array[mid] == target )
        return mid ;

    if ( array[mid] > target )
        mid -= 1;
    else
        mid += 1;
    
    if ( mid < 0 || mid > LENGTH - 1)  
        return -1 ;
    else
        return mid;
}