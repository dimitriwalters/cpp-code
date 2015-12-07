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

bool isTargetInMatrix(int *matrix, int rows, int columns, int target) {
    int start = 0;
    int end = rows*columns - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        int midX = mid / columns;
        int midY = mid % columns;

        // // DEBUG
        // cout << "mid " << mid << " " << midX << " " << midY << endl;

        if (matrix[midX*columns + midY] == target) {
            return true;
        } else if (matrix[midX*columns + midY] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
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

    int bigMatrix[10][10] = {
        {1,2,3,4,5,6,7,8,9,10},
        {11,12,13,14,15,16,17,18,19,20},
        {21,22,23,24,25,26,27,28,29,30},
        {31,32,33,34,35,36,37,38,39,40},
        {41,42,43,44,45,46,47,48,49,50},
        {51,52,53,54,55,56,57,58,59,60},
        {61,62,63,64,65,66,67,68,69,70},
        {71,72,73,74,75,76,77,78,79,80},
        {81,82,83,84,85,86,87,88,89,90},
        {91,92,93,94,95,96,97,98,99,100}
    };

    cout << isTargetInMatrix((int *)bigMatrix, 10, 10, 100) << endl;
}
