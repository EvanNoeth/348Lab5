//Evan Noeth, Friday 3:00 PM Lab
#include <stdio.h>
#define MATRIX_SIZE 5

void addMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int sumMatrix[MATRIX_SIZE][MATRIX_SIZE]);
void multiplyMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int productMatrix[MATRIX_SIZE][MATRIX_SIZE]);
void transposeMatrix(int originalMatrix[MATRIX_SIZE][MATRIX_SIZE], int transposedMatrix[MATRIX_SIZE][MATRIX_SIZE]);
void displayMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main() {
    int matrixA[MATRIX_SIZE][MATRIX_SIZE];
    int matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int resultMatrix[MATRIX_SIZE][MATRIX_SIZE];
    int userChoice;

    // Matrix A Input:
    printf("Enter elements for Matrix A (size %dx%d):\n", MATRIX_SIZE, MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    // Matrix B Input:
    printf("\nEnter elements for Matrix B (size %dx%d):\n", MATRIX_SIZE, MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Display Matrix A\n");
        printf("6. Display Matrix B\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                addMatrices(matrixA, matrixB, resultMatrix);
                printf("\nSum of matrices:\n");
                displayMatrix(resultMatrix);
                break;
            case 2:
                multiplyMatrices(matrixA, matrixB, resultMatrix);
                printf("\nProduct of matrices:\n");
                displayMatrix(resultMatrix);
                break;
            case 3:
                transposeMatrix(matrixA, resultMatrix);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(resultMatrix);
                break;
            case 4:
                transposeMatrix(matrixB, resultMatrix);
                printf("\nTranspose of Matrix B:\n");
                displayMatrix(resultMatrix);
                break;
            case 5:
                printf("\nMatrix A:\n");
                displayMatrix(matrixA);
                break;
            case 6:
                printf("\nMatrix B:\n");
                displayMatrix(matrixB);
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (userChoice != 7);

    return 0;
}

void addMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int sumMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int productMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void transposeMatrix(int originalMatrix[MATRIX_SIZE][MATRIX_SIZE], int transposedMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
