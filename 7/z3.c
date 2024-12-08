#include <stdio.h>
#include <windows.h>

#define INPUT_FILE_PATH "C:\\input.bin"
#define TEMP_FILE_PATH "C:\\temp.bin"

int main() {
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем кодировку UTF-8 для корректного отображения

    FILE* inputFile = NULL;
    FILE* tempFile = NULL;
    int userNumber, currentNumber;
    int found = 0;


    if (fopen_s(&inputFile, INPUT_FILE_PATH, "rb") != 0) {
        printf("Не удалось открыть файл для чтения: %s\n", INPUT_FILE_PATH);
        return 1;
    }

    printf("Содержимое файла:\n");
    while (fread(&currentNumber, sizeof(int), 1, inputFile) == 1) {
        printf("%d ", currentNumber);
    }
    fclose(inputFile);

    printf("\nВведите число, которое нужно удалить или добавить: ");
    if (scanf_s("%d", &userNumber) != 1) {
        printf("Ошибка ввода. Попробуйте снова.\n");
        return 1;
    } 
 
   
    // Открытие исходного файла для чтения в бинарном режиме
    if (fopen_s(&inputFile, INPUT_FILE_PATH, "rb") != 0) {
        printf("Не удалось открыть файл: %s. Возможно, файл пустой или не существует.\n", INPUT_FILE_PATH);
        // Создаем пустой файл
        if (fopen_s(&inputFile, INPUT_FILE_PATH, "wb") != 0) {
            printf("Не удалось создать файл.\n");
            return 1;
        }
        fclose(inputFile);
        inputFile = NULL;
    }
    else {
        // Создание временного файла для записи
        if (fopen_s(&tempFile, TEMP_FILE_PATH, "wb") != 0) {
            printf("Не удалось создать временный файл.\n");
            fclose(inputFile);
            return 1;
        }

        // Чтение из исходного файла и запись в временный файл
        while (fread(&currentNumber, sizeof(int), 1, inputFile) == 1) {
            if (currentNumber == userNumber) {
                found = 1; // Число найдено, пропускаем его
            }
            else {
                fwrite(&currentNumber, sizeof(int), 1, tempFile);
            }
        }

        fclose(inputFile);
        fclose(tempFile);
    }

    if (!found) {
        // Если число не найдено, дописываем его в конец файла
        if (fopen_s(&tempFile, TEMP_FILE_PATH, "ab") != 0) {
            printf("Не удалось открыть временный файл для добавления.\n");
            return 1;
        }
        fwrite(&userNumber, sizeof(int), 1, tempFile);
        fclose(tempFile);
    }


    if (remove(INPUT_FILE_PATH) != 0) {
        printf("Не удалось удалить исходный файл.\n");
        return 1;
    }
    if (rename(TEMP_FILE_PATH, INPUT_FILE_PATH) != 0) {
        printf("Не удалось переименовать временный файл.\n");
        return 1;
    }

    printf("Операция выполнена успешно.\n");

    if (fopen_s(&inputFile, INPUT_FILE_PATH, "rb") != 0) {
        printf("Не удалось открыть файл для чтения: %s\n", INPUT_FILE_PATH);
        return 1;
    }

    printf("Содержимое файла:\n");
    while (fread(&currentNumber, sizeof(int), 1, inputFile) == 1) {
        printf("%d ", currentNumber);
    }

    fclose(inputFile);
    scanf_s("%d", &userNumber);

    return 0;
}
