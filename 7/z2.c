#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define INPUT_FILE_PATH "C:\\input.txt"
#define OUTPUT_FILE_PATH "C:\\output.txt"

int main() {

    FILE* input_file = NULL, * output_file = NULL;

    // Открываем входной файл для чтения
    if (fopen_s(&input_file, INPUT_FILE_PATH, "r") != 0) {
        printf("Ошибка: не удалось открыть файл %s\n", OUTPUT_FILE_PATH);
        return 1;
    }

    // Открываем выходной файл для записи
    if (fopen_s(&output_file, OUTPUT_FILE_PATH, "w") != 0) {
        printf("Ошибка: не удалось создать файл %s\n", INPUT_FILE_PATH);
        fclose(input_file);
        return 1;
    }

    double value;
    // Чтение данных из входного файла, округление и запись в выходной файл
    while (fscanf_s(input_file, "%lf", &value) == 1) {
        value = round(value * 10.0) / 10.0; // Округление до первого знака после запятой
        fprintf(output_file, "%.1f ", value); // Запись округленного значения в файл
        if (fgetc(input_file) == '\n') { // Проверка на переход строки
            fprintf(output_file, "\n");
        }
    }

    // Закрываем файлы
    fclose(input_file);
    fclose(output_file);

    printf("Матрица успешно обработана. Результат записан в файл %s\n", OUTPUT_FILE_PATH);
    
    return 0;
}