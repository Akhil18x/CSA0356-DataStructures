#include <stdio.h>

#define ROWS 3
#define COLS 3

void transposeMatrix(int mat[ROWS][COLS], int transposed[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

    int transposedMatrix[COLS][ROWS];

    transposeMatrix(matrix, transposedMatrix);

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}