#include <stdio.h>
#include <string.h>
#include <math.h>

int convert_to_decimal(const char *num_str, int base) {
    int decimal = 0;
    int len = strlen(num_str);

    for (int i = 0; i < len; i++) {
        decimal += (num_str[i] - '0') * pow(base, len - i - 1);
    }
    return decimal;
}

int main() {
    char input[256];
    int base;

    printf("Введите основание системы счисления (n): ");
    scanf("%d", &base);
    if (base <= 0 || base >= 10) {
        printf("Основание должно быть в диапазоне от 1 до 9.\n");
        return 1;
    }

    printf("Введите число в %d-ричной системе: ", base);
    scanf("%s", input);

    // Удаляем символы после точки
    char *dot = strchr(input, '.');
    if (dot) *dot = '\0';

    int decimal = convert_to_decimal(input, base);
    printf("Десятичное представление: %d\n", decimal);

    return 0;
}
