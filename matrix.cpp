#include <iostream>

using namespace std;

void printMatrix(int *matrix, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout << matrix[i*columns + j] << " ";
        }
        cout << endl;
    }
}

void rotate90(int *matrix, int rows, int columns, int *dest) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            dest[j*rows + i] = matrix[((rows - 1) - i) * columns + j];
        }
    }
}

int main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int newMatrix[3][3];

    printMatrix((int *)matrix, 3, 3);
    rotate90((int *)matrix, 3, 3, (int *)newMatrix);
    printMatrix((int *)newMatrix, 3, 3);
}
