#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10

void fillArray(int *array, int size);
void printArray(int *array, int size);
int findMinInBlock(int *array, int blockSize);
void printBlockWithHighestMin(int *array, int n);


void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 100) - 50;  
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");  
    }
}

int findMinInBlock(int *array, int blockSize) {
    int min = array[0];
    for (int i = 1; i < blockSize; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void printBlockWithHighestMin(int *array, int n) {
    int maxMin = -51; 
    int bestBlockIndex = 0;

    for (int i = 0; i < n; i++) {
        int *blockStart = &array[i * 10];
        int minInBlock = findMinInBlock(blockStart, 10);
        
        printf("Минимум в блоке %d: %d\n", i + 1, minInBlock);

        if (minInBlock > maxMin) {
            maxMin = minInBlock;
            bestBlockIndex = i;
        }
    }

    printf("\nБлок с наибольшим минимумом (блок %d):\n", bestBlockIndex + 1);
    printArray(&array[bestBlockIndex * 10], 10);
}

int main() {
    int n;
    printf("Введите значение n (от 1 до 10): ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_N) {
        printf("Ошибка: n должно быть в диапазоне от 1 до 10.\n");
        return 1;
    }

    int size = 10 * n;
    int A[size];

    srand(time(0));

    fillArray(A, size);

    printf("Массив A:\n");
    printArray(A, size);

    printBlockWithHighestMin(A, n);

    return 0;
}
