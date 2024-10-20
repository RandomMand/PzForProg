#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, M, L;  
    printf("Введите количество учеников (N): ");
    scanf("%d", &N);
    printf("Введите количество уроков (M): ");
    scanf("%d", &M);
    printf("Введите количество предметов (L): ");
    scanf("%d", &L);

    int ***journal = (int ***)malloc(L * sizeof(int **));
    for (int l = 0; l < L; l++) {
        journal[l] = (int **)malloc(N * sizeof(int *));
        for (int n = 0; n < N; n++) {
            journal[l][n] = (int *)malloc(M * sizeof(int));
        }
    }


    for (int l = 0; l < L; l++) {  // По предметам
        for (int n = 0; n < N; n++) {  // По ученикам
            for (int m = 0; m < M; m++) {  // По урокам
             printf("Введите оценку");
             scanf("%d", &journal[l][n][m]);
            }
        }
    }


    for (int n = 0; n < N; n++) {
        int horosho = 1;  
        for (int l = 0; l < L; l++) {  
            for (int m = 0; m < M; m++) {  
                if (journal[l][n][m] < 4) {
                    horosho = 0;  
                    break;  
                }
            }
            if (!horosho) break;  
        }
        if (horosho) {
            printf("Ученик %d учится только на \"хорошо\" и \"отлично\".\n", n + 1);
        }
    }


    for (int l = 0; l < L; l++) {
        for (int n = 0; n < N; n++) {
            free(journal[l][n]);
        }
        free(journal[l]);
    }
    free(journal);

    return 0;
}
