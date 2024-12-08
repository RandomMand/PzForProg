#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define INPUT_FILE_PATH "C:\\trains.txt"
#define MAX_LINE_LENGTH 256

typedef struct {
    int trainNumber;
    char destination[50];
    char departureTime[10];
    char travelTime[10];
    char ticketsAvailable[10];
} Train;

void findTrainsByCityAndTime(const char* city, const char* startTime, const char* endTime) {
    FILE* file;
    Train train;
    char line[MAX_LINE_LENGTH];

    if (fopen_s(&file, INPUT_FILE_PATH, "r") != 0) {
        printf("Не удалось открыть файл: %s\n", INPUT_FILE_PATH);
        return;
    }

    printf("Поезда в город %s в интервале времени %s - %s:\n", city, startTime, endTime);
    printf("Номер поезда | Время отправления\n");

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf_s(line, "%d %49s %9s %9s %9s",
            &train.trainNumber,
            train.destination, (unsigned)_countof(train.destination),
            train.departureTime, (unsigned)_countof(train.departureTime),
            train.travelTime, (unsigned)_countof(train.travelTime),
            train.ticketsAvailable, (unsigned)_countof(train.ticketsAvailable));

        if (strcmp(train.destination, city) == 0 &&
            strcmp(train.departureTime, startTime) >= 0 &&
            strcmp(train.departureTime, endTime) <= 0) {
            printf("%12d | %s\n", train.trainNumber, train.departureTime);
        }
    }

    fclose(file);
}

void checkTicketsAvailability(int trainNumber) {
    FILE* file;
    Train train;
    char line[MAX_LINE_LENGTH];

    if (fopen_s(&file, INPUT_FILE_PATH, "r") != 0) {
        printf("Не удалось открыть файл: %s\n", INPUT_FILE_PATH);
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf_s(line, "%d %49s %9s %9s %9s",
            &train.trainNumber,
            train.destination, (unsigned)_countof(train.destination),
            train.departureTime, (unsigned)_countof(train.departureTime),
            train.travelTime, (unsigned)_countof(train.travelTime),
            train.ticketsAvailable, (unsigned)_countof(train.ticketsAvailable));

        if (train.trainNumber == trainNumber) {
            printf("Поезд %d: Наличие билетов: %s\n", trainNumber, train.ticketsAvailable);
            fclose(file);
            return;
        }
    }

    printf("Поезд с номером %d не найден.\n", trainNumber);
    fclose(file);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char city[50];
    char startTime[10], endTime[10];
    int trainNumber;
    int choice;

    printf("Выберите действие:\n");
    printf("1. Найти поезда по городу и времени отправления.\n");
    printf("2. Проверить наличие билетов на поезд.\n");
    printf("Ваш выбор: ");
    if (scanf_s("%d", &choice) != 1) {
        printf("Ошибка ввода. Попробуйте снова.\n");
        return 1;
    }

    if (choice == 1) {
        printf("Введите город назначения: ");
        scanf_s("%49s", city, (unsigned)_countof(city));

        printf("Введите начальное время отправления (HH:MM): ");
        scanf_s("%9s", startTime, (unsigned)_countof(startTime));

        printf("Введите конечное время отправления (HH:MM): ");
        scanf_s("%9s", endTime, (unsigned)_countof(endTime));

        findTrainsByCityAndTime(city, startTime, endTime);

    }
    else if (choice == 2) {
        printf("Введите номер поезда: ");
        if (scanf_s("%d", &trainNumber) != 1) {
            printf("Ошибка ввода. Попробуйте снова.\n");
            return 1;
        }

        checkTicketsAvailability(trainNumber);

    }
    else {
        printf("Неверный выбор. Попробуйте снова.\n");
    }

    int lol = 0;
    scanf_s("%d", &lol);
    return 0;
}
