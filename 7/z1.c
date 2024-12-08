#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_FILE_PATH "C:\\input.txt"
#define OUTPUT_FILE_PATH "C:\\output.txt"

// Функция для проверки конца предложения
int is_end_of_sentence(char ch) {
    return ch == '.' || ch == '!' || ch == '?';
}

int main() {
        const char* output_filename = "C:\\output.txt";
        const char* input_filename = "C:\\input.txt";  // Путь к входному файлу
        

        FILE* input_file = NULL, * output_file = NULL;
        int ch; // Тип int для корректной работы с fgetc
        int line_count = 0, word_count = 0, sentence_count = 0;
        int char_count_with_spaces = 0, char_count_without_spaces = 0;
        int in_word = 0;

        // Открываем входной файл для чтения
        if (fopen_s(&input_file, input_filename, "r") != 0) {
            printf("Ошибка: не удалось открыть файл %s\n", input_filename);
            return 1;
        }

        // Открываем выходной файл для записи
        if (fopen_s(&output_file, output_filename, "w") != 0) {
            printf("Ошибка: не удалось создать файл %s\n", output_filename);
            fclose(input_file);
            return 1;
        }

        // Анализ текста
        while ((ch = fgetc(input_file)) != EOF) {
            char_count_with_spaces++;

            // Приведение ch к unsigned char для работы с isspace
            if (!isspace((unsigned char)ch)) {
                char_count_without_spaces++;
            }

            if (ch == '\n') {
                line_count++;
            }

            if (is_end_of_sentence((char)ch)) {
                sentence_count++;
            }

            if (isspace((unsigned char)ch)) {
                in_word = 0;
            }
            else if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }

        // Если последний символ файла не был новой строкой, учитываем последнюю строку
        if (char_count_with_spaces > 0 && ch != '\n') {
            line_count++;
        }

        // Записываем результаты в выходной файл
        fprintf(output_file, "Статистика текста:\n");
        fprintf(output_file, "Количество строк: %d\n", line_count);
        fprintf(output_file, "Количество фраз: %d\n", sentence_count);
        fprintf(output_file, "Количество слов: %d\n", word_count);
        fprintf(output_file, "Количество знаков (без пробелов): %d\n", char_count_without_spaces);
        fprintf(output_file, "Количество знаков (с пробелами): %d\n", char_count_with_spaces);

        // Сообщаем об успешной обработке
        printf("Анализ текста завершён. Результаты записаны в файл %s\n", output_filename);

        // Закрываем файлы
        fclose(input_file);
        fclose(output_file);

    return 0;
}
