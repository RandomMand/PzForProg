#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap_rows(double **matrix, int row1, int row2, int n) {
    for (int i = 0; i < n + 1; ++i) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void gaussian_elimination(double **matrix, double *solution, int n) {
    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(matrix[k][i]) > fabs(matrix[max_row][i])) {
                max_row = k;
            }
        }
        
        if (max_row != i) {
            swap_rows(matrix, i, max_row, n);
        }
                for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; --j) {
            matrix[j][n] -= matrix[j][i] * solution[i];
        }
    }
}

void generate_random_system(double **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            matrix[i][j] = (double)(rand() % 100) / 10.0;
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    int n;
    printf("Введите количество элементов матрицы (n): ");
    scanf("%d", &n);


    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (double *)malloc((n + 1) * sizeof(double));
    }
    double *solution = (double *)malloc(n * sizeof(double));


    generate_random_system(matrix, n);
    printf("Созданная матрица:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            printf("%10.3f ", matrix[i][j]);
        }
        printf("\n");
    }

    clock_t start = clock();
    gaussian_elimination(matrix, solution, n);
    clock_t end = clock();


    printf("\nРешение:\n");
    for (int i = 0; i < n; ++i) {
        printf("x[%d] = %.6f\n", i, solution[i]);
    }

    printf("\nВремя выполнения: %.6f секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(solution);

    return 0;
}