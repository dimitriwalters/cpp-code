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

void splitArray(int original[], int left[], int right[], int length) {
    int midpt = length / 2;

    for (int i=0; i<midpt; i++) {
        left[i] = original[i];
    }

    for (int i=midpt; i<length; i++) {
        right[i - midpt] = original[i];
    }
}

int main() {
    int arr[10];
    fillArray(arr, 1, 10);
    printArray(arr, 10);

    return 0;
}
