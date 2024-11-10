#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap_first_last(char *word) {
    int len = strlen(word);
    if (len > 1) {
        char temp = word[0];
        word[0] = word[len - 1];
        word[len - 1] = temp;
    }
}

int main() {
    char input[256];
    printf("Введите строку: ");
    fgets(input, 256, stdin);

    // Обрезаем строку до точки
    char *dot = strchr(input, '.');
    if (dot) *dot = '\0';

    char *word = strtok(input, " ");
    int count = 1;

    while (word) {
        if (count % 2 == 0) {
            swap_first_last(word);
        }
        printf("%s ", word);
        word = strtok(NULL, " ");
        count++;
    }

    return 0;
}
