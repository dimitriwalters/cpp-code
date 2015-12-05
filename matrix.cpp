#include <iostream>

using namespace std;

void printMatrix(int *matrix, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout << matrix[i*columns + j] << endl;
        }
    }
}

int main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printMatrix((int *)matrix, 3, 3);
}
