#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int rows, int cols) {
    int** matrix = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void matrixAddition(int rows, int cols, int** mat1, int** mat2, int** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void displayMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int** matrix1 = allocateMatrix(rows, cols);
    int** matrix2 = allocateMatrix(rows, cols);
    int** resultMatrix = allocateMatrix(rows, cols);

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    matrixAddition(rows, cols, matrix1, matrix2, resultMatrix);

    printf("Matrix 1:\n");
    displayMatrix(rows, cols, matrix1);

    printf("Matrix 2:\n");
    displayMatrix(rows, cols, matrix2);

    printf("Resultant matrix after addition:\n");
    displayMatrix(rows, cols, resultMatrix);

    freeMatrix(matrix1, rows);
    freeMatrix(matrix2, rows);
    freeMatrix(resultMatrix, rows);

    return 0;
}