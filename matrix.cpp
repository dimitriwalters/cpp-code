#include <iostream>
#include <string>

using namespace std;

void printMatrix(int *matrix, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout << matrix[i*columns + j] << " ";
        }
        cout << endl;
    }
}

void printCharMatrix(char *matrix, int rows, int columns) {
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

bool dfs(char *matrix, int rows, int columns, string word, int i, int j, int k) {
    if (k == word.length()) {
        return true;
    } else if (i < 0 || i >= rows || j < 0 || j >= columns) {
        return false;
    } else {
        if (matrix[i*columns + j] == word[k]) {
            return dfs(matrix, rows, columns, word, i-1, j, k+1)
                || dfs(matrix, rows, columns, word, i, j+1, k+1)
                || dfs(matrix, rows, columns, word, i+1, j, k+1)
                || dfs(matrix, rows, columns, word, i, j-1, k+1);
        } else {
            return false;
        }
    }
}

bool isWordInMatrix(char *matrix, int rows, int columns, string word) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            if (dfs(matrix, rows, columns, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
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

    char a[3][3] = {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'}
    };
    printCharMatrix((char *)a, 3, 3);

    cout << isWordInMatrix((char *)a, 3, 3, "ihgdabcfe") << endl;
}
