#include <stdio.h>
#include <time.h>

int main() {
    int **A = (int **)malloc(N*sizeof(int *));
    for(int i = 0; i < N; i++) {
    A[i] = (int *)malloc(M*sizeof(int));
    }
    
    int matrix[10][10];  
    
    printf("Сгенерированная матрица 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = rand() % (100 + 1);  
            printf("%4d ", matrix[i][j]); 
        }
        printf("\n");
    }

    for (int i = 0; i < 10 - 1; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (matrix[i][0] < matrix[j][0]) {
                // Меняем строки местами
                for (int k = 0; k < 10; k++) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }
    }

    printf("Матрица после сортировки по убыванию первого столбца:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%4d ", matrix[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
