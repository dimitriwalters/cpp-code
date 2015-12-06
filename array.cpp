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

void mergesort(int arr[], int length) {
    if (length < 2) {
        return;
    } else {
        int midpt = length / 2;
        int left[midpt];
        int right[length - midpt];

        split(arr, left, midpt, right, length - midpt);
        mergesort(left, midpt);
        mergesort(right, length - midpt);
        merge(left, midpt, right, length - midpt, arr);
    }
}

void copyArray(int src[], int dest[], int length) {
    for (int i=0; i<length; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int a[] = {3, 2, 4, 5, 1};
    int b[5];

    copyArray(a, b, 5);
    printArray(b, 5);

    mergesort(a, 5);
    printArray(a, 5);

    return 0;
}
