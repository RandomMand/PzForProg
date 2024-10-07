#include <stdio.h>

int main(void) {
    // Объявление переменных
    double a = 5.0, b, c = 5, d;

    // Ввод значений переменных b и d
    printf("Введите значение b: ");
    scanf("%lf", &b);
    printf("Введите значение d: ");
    scanf("%lf", &d);

    // Вычисление и вывод значений переменных
    a = a + b - 2;
    printf("После a=a+b-2: a=%.2lf, b=%.2lf, c=%.0lf, d=%.2lf\n", a, b, c, d);

    c = c + 1;
    d = c - a + d;
    printf("После c=c+1, d=c-a+d: a=%.2lf, b=%.2lf, c=%.0lf, d=%.2lf\n", a, b, c, d);

    a = a * c;
    c = c - 1;
    printf("После a=a*c, c=c-1: a=%.2lf, b=%.2lf, c=%.0lf, d=%.2lf\n", a, b, c, d);

    a = a / 10;
    c = c / 2;
    b = b - 1;
    d = d * (c + b + a);
    printf("После a=a/10, c=c/2, b=b-1, d=d*(c+b+a): a=%.2lf, b=%.2lf, c=%.0lf, d=%.2lf\n", a, b, c, d);

    return 0;
}