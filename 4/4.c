#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matrix[10][10];
    printf("Сгенерированная матрица 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = (rand() % (50 - -1 + 1)) + -1;
            printf("%4d ", matrix[i][j]);  
        }
        printf("\n");
    }

    printf("\nПервые отрицательные элементы каждого столбца:\n");
    for (int j = 0; j < 10; j++) {
        int nashel = 0;
        for (int i = 0; i < 10; i++) {
            if (matrix[i][j] < 0) {
                printf("Столбец %d: первый отрицательный элемент на строке %d (значение = %d)\n", 
                        j + 1, i + 1, matrix[i][j]);
                nashel = 1;
                break;  
            }
        }
        if (!nashel) {
            printf("Столбец %d: нет отрицательных элементов.\n", j + 1);
        }
    }

    return 0;
}
