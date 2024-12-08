#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y) { int temp = x; x = y; y = temp; }

// Генерация случайного массива
void generate_random_array(int *arr, int n, int range) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
}

// Сортировка массива для бинарного и интерполяционного поиска
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                SWAP(arr[i], arr[j]);
            }
        }
        SWAP(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Последовательный поиск
int sequential_search(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Бинарный поиск
int binary_search(int *arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Интерполяционный поиск
int interpolation_search(int *arr, int low, int high, int key) {
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos;
        }
        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n = 100000; // Длина массива
    int m = 1000;   // Количество ключей поиска

    int *arr = malloc(n * sizeof(int));
    int *keys = malloc(m * sizeof(int));

    if (!arr || !keys) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    srand(time(NULL));

    // Генерация массива и ключей поиска
    generate_random_array(arr, n, n);
    generate_random_array(keys, m, n + m);

    // Последовательный поиск
    clock_t start = clock();
    for (int i = 0; i < m; i++) {
        sequential_search(arr, n, keys[i]);
    }
    clock_t end = clock();
    printf("Последовательный поиск: %.2f мс\n", 1000.0 * (end - start) / CLOCKS_PER_SEC);

    // Сортировка массива для бинарного и интерполяционного поиска
    quicksort(arr, 0, n - 1);

    // Бинарный поиск
    start = clock();
    for (int i = 0; i < m; i++) {
        binary_search(arr, 0, n - 1, keys[i]);
    }
    end = clock();
    printf("Бинарный поиск: %.2f мс\n", 1000.0 * (end - start) / CLOCKS_PER_SEC);

    // Интерполяционный поиск
    start = clock();
    for (int i = 0; i < m; i++) {
        interpolation_search(arr, 0, n - 1, keys[i]);
    }
    end = clock();
    printf("Интерполяционный поиск: %.2f мс\n", 1000.0 * (end - start) / CLOCKS_PER_SEC);

    free(arr);
    free(keys);

    return 0;
}
