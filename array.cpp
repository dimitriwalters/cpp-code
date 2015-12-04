#include <stdio.h>

void printArray(int arr[], int length) {
    for (int i=0; i<length; i++) {
        printf("%d\n", arr[i]);
    }
}

void fillArray(int arr[], int start, int end) {
    int length = end - start;
    for (int i=0; i<=length; i++) {
        arr[i] = start + i;
    }
}

void fillArrayParity(int arr[], int start, int end) {
    int length = (end - start)/2;
    for (int i=0; i<=length; i++) {
        arr[i] = start + (i*2);
    }
}

void split(int orig[], int l[], int lLen, int r[], int rLen) {
    for (int i=0; i<lLen; i++) {
        l[i] = orig[i];
    }

    for (int i=lLen; i<(lLen + rLen); i++) {
        r[i - lLen] = orig[i];
    }
}

void merge(int a[], int aLen, int b[], int bLen, int source[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < aLen || j < bLen) {
        if (i == aLen) {
            source[k] = b[j];
            j++;
        } else if (j == bLen) {
            source[k] = a[i];
            i++;
        } else if (a[i] < b[j]) {
            source[k] = a[i];
            i++;
        } else {
            source [k] = b[j];
            j++;
        }

        k++;
    }
}

int main() {
    int a[] = {2, 3, 1, 4, 5};
    int b[2];
    int c[3];
    int d[5];

    split(a, b, 2, c, 3);
    printf("b:\n");
    printArray(b, 2);
    printf("c:\n");
    printArray(c, 3);

    merge(b, 2, c, 3, d);
    printf("d:\n");
    printArray(d, 5);

    return 0;
}
