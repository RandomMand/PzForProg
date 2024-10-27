#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void checkRows(int rows, int cols, int matrix[rows][cols], char matrixName);


void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 21) - 1;  // Заполнение случайными числами от -10 до 10
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void checkRows(int rows, int cols, int matrix[rows][cols], char matrixName) {
    for (int i = 0; i < rows; i++) {
        int positiveCount = 0, negativeCount = 0;

        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                positiveCount++;
            } else if (matrix[i][j] < 0) {
                negativeCount++;
            }
        }

        if (positiveCount == negativeCount) {
            printf("В матрице %c строка %d содержит равное число положительных и отрицательных элементов.\n", matrixName, i + 1);
        }
    }
}

int main() {
    
    int m, n;

    printf("Введите количество строк m и столбцов n для матрицы B: ");
    scanf("%d %d", &m, &n);

    int B[m][n];
    int C[n][m];

    srand(time(0));


    fillMatrix(m, n, B);
    printf("\nМатрица B:\n");
    printMatrix(m, n, B);

    fillMatrix(n, m, C);
    printf("\nМатрица C:\n");
    printMatrix(n, m, C);

    
    printf("\nПроверка строк матрицы B:\n");
    checkRows(m, n, B, 'B');

    printf("\nПроверка строк матрицы C:\n");
    checkRows(n, m, C, 'C');

    return 0;
}

