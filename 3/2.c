#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *p, c;
    int *a, b = 0;
    float *x, y = 3.5;
    double *m, n = 0;

    // Инициализация указателей
    a = &b;
    x = &y;
    m = &n;

    // Вывод адресов всех переменных
    printf("Addresses:\n");
    printf("&b=%p, &y=%p, &n=%p\n", &b, &y, &n);
    printf("&a=%p, &x=%p, &m=%p\n\n", &a, &x, &m);

    // Ввод значения переменной b
    printf("Enter b = ");
    scanf("%d", a);
    printf("a=%p\t*a=%d\tb=%d\n", a, *a, b);

    // Работы с указателем p, приведение типа
    p = (char *)a;
    c = *p;
    *p = *(p + 3);
    *(p + 3) = c;
    printf("p=%p\tc=%d\ta=%p\tb=%d\n", p, c, a, b);

    // Работа с указателями float
    printf("x=%p\t*x=%e\ty=%e\n", x, *x, y);

    // Присваивание указателя на float указателю на int (с приведением типа)
    a = (int *)x;
    *a = (int)*x;
    printf("a=%p\t*a=%d\tx=%p\t*x=%e\ty=%e\n", a, *a, x, *x, y);

    // Изменение значения y
    y = 12345.6789;
    printf("x=%p\t*x=%e\ty=%e\n", x, *x, y);

    // Работы с указателем p
    p = (char *)x;
    c = *p;
    *p = *(p + 3);
    *(p + 3) = c;
    printf("p=%p\tc=%d\tx=%p\ty=%e\n", p, c, x, y);

    // Работа с указателем m и переменной n
    printf("m=%p\t*m=%lf\tn=%lf\n", m, *m, n);
    n = 5.5;
    printf("m=%p\t*m=%lf\tn=%lf\n", m, *m, n);

    // Присвоение значений переменным
    b = n = y = 1.7;
    printf("b=%d\ty=%f\tn=%lf\n", b, y, n);
    printf("*a=%d\t*x=%f\t*m=%lf\n", *a, *x, *m);

    // Заменим m += 2; на m++;
    m++;
    printf("n=%lf\tn=%p\tm=%p\n", n, &n, m);

    // Вычисление значения, на которое указывает указатель m
    *m = (float)*a - n + (int)*x;
    printf("m=%p\t*m=%lf\n", m, *m);

    // Вывод значений всех переменных в конце программы
    printf("\nFinal values:\n");
    printf("b=%d, y=%f, n=%lf\n", b, y, n);
    printf("*a=%d, *x=%f, *m=%lf\n", *a, *x, *m);

    system("pause");
    return 0;
}