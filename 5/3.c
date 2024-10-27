#include <stdio.h>
#include <math.h>


double Integral(double (*f)(double), double a, double b, int n);


double func1(double x) {
    return 1.0 / (3 * x * x - 2 * x + 4);
}

double func2(double x) {
    return cos(x) / (1 + sin(x) * sin(x));
}
double Integral(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    return sum * h;
}

int main() {
    double a1 = -1, b1 = 3; 
    double a2 = 1, b2 = 5;  
    int n = 35;

  
    double result1 = Integral(func1, a1, b1, n);
    double result2 = Integral(func2, a2, b2, n);

    printf("Результат интегрирования первого выражения: %.6f\n", result1);
    printf("Результат интегрирования второго выражения: %.6f\n", result2);

    return 0;
}

