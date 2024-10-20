#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

int main() {
    const int SIZE = 50;
    int arr[SIZE];  
    int sum = 0;
    double sred;
    int count = 0;
    
    printf("Введите %d элементов массива:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];  
    }
    
    sred = (double)sum / SIZE;
    
    for (int i = 0; i < SIZE; i++) {
        if (fabs(arr[i] - sred) <= 1.0) {
            count++;
        }
    }

    printf("Количество элементов, отличающихся от среднего не более чем на 1: %d\n", count);

    return 0;
}
