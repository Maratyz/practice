#include <stdio.h>

void qSort(int v[], int left, int right );

int main() {
    int i;
    int v[] = {1,3,9,7,2,5,4};
    qSort(v,0,6);
    for (i = 0 ; i < 7 ; i++) {
        printf("%d\t", v[i]);
    }
    return 0;
}


void qSort(int v[], int left, int right ) {
    int i, last;
    void swap(int v[], int i, int j );

    if (left >= right)
        return ;

    swap(v, left, left+(right-left)/2);
    last = left ;

    for (i = left+1 ; i <= right ; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, last, left);
    qSort(v, left, last-1);
    qSort(v, last+1, right);
}

void swap(int v[], int i, int j ) {
    int temp ;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}