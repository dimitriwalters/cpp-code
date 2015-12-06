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

void copyArray(int src[], int dest[], int length) {
    for (int i=0; i<length; i++) {
        dest[i] = src[i];
    }
}

bool isVisited(int i, int j, int *visited, int length) {
    for (int k=0; k<length; k+=2) {
        if (visited[k] == i && visited[k+1] == j) {
            return true;
        }
    }
    return false;
}

bool dfs(char *matrix, int rows, int columns, string word, int i, int j, int k, int *visited) {
    // // DEBUG
    // if (i < 0 || i >= rows || j < 0 || j >= columns) {
    //     cout << "dfs" << " " << i << " " << j << endl;
    // } else {
    //     cout << "dfs" << " " << matrix[i*columns + j] << endl;
    // }

    if (i < 0 || i >= rows || j < 0 || j >= columns) {
        return false;
    } else if (isVisited(i, j, visited, word.size()*2)) {
        return false;
    } else if (matrix[i*columns + j] == word[k]) {
        if (k == word.length()-1) {
            return true;
        } else {
            int newVisited[word.size() * 2];
            copyArray(visited, newVisited, word.size()*2);
            newVisited[k*2] = i;
            newVisited[k*2 + 1] = j;

            return dfs(matrix, rows, columns, word, i-1, j, k+1, newVisited)
                || dfs(matrix, rows, columns, word, i, j+1, k+1, newVisited)
                || dfs(matrix, rows, columns, word, i+1, j, k+1, newVisited)
                || dfs(matrix, rows, columns, word, i, j-1, k+1, newVisited);
        }
    } else {
        return false;
    }
}

bool isWordInMatrix(char *matrix, int rows, int columns, string word) {
    int visited[word.size() * 2];
    for (int i=0; i<word.size()*2; i++) {
        visited[i] = -1;
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            if (dfs(matrix, rows, columns, word, i, j, 0, visited)) {
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

    cout << isWordInMatrix((char *)a, 3, 3, "aba") << endl;
}
