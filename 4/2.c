#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr = NULL, *newArr = NULL;
    int novSize = 0;  

    // Ввод размера массива с проверкой
    printf("Введите размер массива: ");
    scanf("%d", &n);
    

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка: не удалось выделить память.\n");
        return 1;
    }

    printf("Введите %d элемента массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    newArr = (int *)malloc(0 * sizeof(int));

    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // Если элемент встречается более одного раза и ещё не добавлен в новый массив
        if (count > 1) {
            int estUje = 0;
            for (int k = 0; k < novSize; k++) {
                if (newArr[k] == arr[i]) {
                    estUje = 1;
                    break;
                }
            }

            // Если элемента еще нет в новом массиве, добавляем его
            if (!estUje) {
                novSize++;
                newArr = (int *)realloc(newArr, novSize * sizeof(int));
                if (newArr == NULL) {
                    printf("Ошибка: не удалось выделить память.\n");
                    free(arr);
                    return 1;
                }
                newArr[novSize - 1] = arr[i];
            }
        }
    }
    printf("Новый массив из уникальных повторяющихся элементов: ");
    for (int i = 0; i < novSize; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    free(arr);
    free(newArr);

    return 0;
}
