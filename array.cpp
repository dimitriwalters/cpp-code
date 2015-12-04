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

void splitArray(int orig[], int l[], int lLen, int r[], int rLen) {
    for (int i=0; i<lLen; i++) {
        l[i] = orig[i];
    }

    for (int i=lLen; i<(lLen + rLen); i++) {
        r[i - lLen] = orig[i];
    }
}

int main() {
    int arr[10];
    fillArray(arr, 1, 10);
    printArray(arr, 10);

    return 0;
}
