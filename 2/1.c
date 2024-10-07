#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double f(double x, double y) {
    return (x > 0 && y < 0) ? (x + y) :
           (x > 0 && y > 1) ? (x / (y - 1)) :
           (x - y);
}
int are_collinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
}

double distance_to_origin(double x, double y) {
    return sqrt(x * x + y * y);
}


int is_prime(int p) {
    if (p < 2) return 0; 
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) return 0;
    }
    return 1;
}

int main() {
    double x, y;
    printf("Введите значения x и y: ");
    scanf("%lf %lf", &x, &y);
    
    double result = f(x, y);
    printf("f(%.2lf, %.2lf) = %.2lf\n", x, y, result);

   
    //Второе задание
     double x,y, A;

   
    printf("Введите значение x: ");
    scanf("%lf", &x);
    printf("Введите значение y: ");
    scanf("%lf", &y);

    
    if (y == 0) {
        printf("Ошибка: y не может быть равен нулю.\n");
        return 1;  
    }

   //ООФ
    if (4 * pow(y, 3) <= 0) {
        printf("Ошибка: выражение |4y^3| должно быть больше 0.\n");
        return 1;  
    }

   
    A = (sin(x) * cos(y) - tan(x / y)) / (log(fabs(4 * pow(y, 3)))/ log(exp(1)));

   
    printf("Результат: A = %.6f\n", A);
    
    //Третье задание
    
    double x1, y1, x2, y2, x3, y3;

    
    printf("Введите координаты точки 1 (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Введите координаты точки 2 (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Введите координаты точки 3 (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);

   
    if (are_collinear(x1, y1, x2, y2, x3, y3)) {
     
        double A = y2 - y1;
        double B = x1 - x2;
        double C = -(A * x1 + B * y1);

        
        if (A < 0) {
            A = -A;
            B = -B;
            C = -C;
        }

        printf("Точки лежат на одной прямой.\n");
        printf("Уравнение прямой: %.2lfx + %.2lfy + %.2lf = 0\n", A, B, C);
    } else {
       
        double d1 = distance_to_origin(x1, y1);
        double d2 = distance_to_origin(x2, y2);
        double d3 = distance_to_origin(x3, y3);

        printf("Точки не лежат на одной прямой.\n");
        printf("Расстояние до точки 1: %.6lf\n", d1);
        printf("Расстояние до точки 2: %.6lf\n", d2);
        printf("Расстояние до точки 3: %.6lf\n", d3);
    }
    
    //Четвертое задание
    
    double tC, tF;

    printf("Температура по Цельсию\tТемпература по Фаренгейту\n");
    printf("--------------------------------------------\n");

   
    for (tC = 0; tC <= 100; tC++) {
       
        tF = (9.0 / 5.0) * tC + 32;
        printf("%.0lf\t\t\t%.2lf\n", tC, tF);
    }
    
    //Пятое задание
    int xx;
    sum = 0;
    printf("Введите значение X (натуральное число): ");
    scanf("%d", &xx);
    printf("Введите значение Y (натуральное число): ");
    scanf("%lf", &y);

    if (xx > y) {
        printf("Ошибка: X должно быть меньше или равно Y.\n");
        return 1;
    }

    if (xx % 2 != 0) {
        xx++;  
    }

    int i = xx;
    if (xx <= y) {
        do {
            sum += i * i * i;  
            i += 2;  
        } while (i <= y);
    }

    
    printf("Сумма кубов всех четных чисел в диапазоне [%d, %lf] = %lf\n", xx, y, sum);

    
    //Шестое задание
    
    int temp;
    bool is_binary = true;  

    
    printf("Введите число N: ");
    scanf("%d", &N);

    temp = N; 

    
    while (temp > 0) {
        int digit = temp % 10;  

        if (digit != 0 && digit != 1) {  
            is_binary = false;  
            break;
        }

        temp /= 10; 
    }

   
    if (is_binary == true) {
        printf("Число %d является двоичным.\n", N);
    } else {
        printf("Число %d не является двоичным.\n", N);
    }
    
    //Седьмое задание
    double term,n;
    sum = 0.5;  // Инициализация суммы с 1/2
        
    n = 0;            
    double epsilon = 1e-6; 

    
    printf("Введите значение x: ");
    scanf("%lf", &x);


	term = pow(2, -1) * pow(x, 0) / 1; 

    while (fabs(term) >= epsilon) {
        sum += term;  

        // Рассчитываем следующий член ряда
        n++;
        term *= -x * x / ((2 * n) * (2 * n - 1)) * 4;  // Рекуррентная формула для вычисления нового члена ряда
    }

  
    printf("Вычисленное значение суммы ряда: %lf\n", sum);

   
    double check = pow(cos(x), 2);
    printf("Проверочное значение (cos^2(x)): %lf\n", check);
    
    //Восьмое задание
    
    sum = 0.0;
    n = 1;
    const double eepsilon = 1e-6;
    const double cos_pi_over_3 = cos(M_PI / 3);  // Предвычисляем cos(π/3), который равен 0.5

   
    p // Ввод значения x
    printf("Введите значение x (в диапазоне 0.1 <= x <= 0.8): ");
    scanf("%lf", &x);

    // Проверка корректности введённого значения x
    if (x < 0.1 || x > 0.8) {
        printf("Ошибка: значение x должно быть в диапазоне 0.1 <= x <= 0.8.\n");
        return 1;
    }

    // Цикл для вычисления суммы ряда до достижения точности epsilon
    do {
        // Рассчитываем текущий член ряда
        term = (pow(x, n) * cos(n * M_PI / 3)) / n;  // f(x) = x^n * cos(n * π / 3) / n
        sum += term;  // Добавляем текущий член к сумме
        n++;          // Увеличиваем n
    } while (fabs(term) >= eepsilon);  // Продолжаем до достижения точности

    // Вывод результата
    printf("Вычисленное значение суммы ряда f(x): %lf\n", sum);

    // Проверка с помощью функции y
    double y = -0.5 * (log(1 - 2 * x * 0.5 + x * x)/log(M_E));  // cos(π/3) = 0.5
    printf("Значение функции y для проверки: %lf\n", y);

    
    //Девятое задание
    
    int a, numerator, denominator;

  
    printf("Введите значение a: ");
    scanf("%d", &a);

    // Вычисление числителя и знаменателя
    numerator = pow(a, 4) + 12 * pow(a, 2) - 5;
    denominator = pow(a, 3) + 11 * a;

    
    printf("Простые числа, на которые сокращается дробь:\n");
	
	//is_prime true - число простое
	
    for (int p = 2; p <= abs(numerator) && p <= abs(denominator); p++) {
        if (is_prime(p)) { 
            if (numerator % p == 0 && denominator % p == 0) {
                printf("%d\n", p); 
            }
        }
    }
    
    return 5;
}
