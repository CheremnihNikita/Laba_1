#include <iostream>
#include <cmath>
#include <limits> // for numeric_limits
#include <clocale>
using namespace std;
// Функция, которую нужно решить (замените на свою)
double f(double x) {
    return acos(x) - sqrt(1 - 0.3 * x * x * x);
}
// Производная функции 
double df(double x) {
    return ((9 * x * x) / (20 * sqrt(1 - 0.3 * x * x * x))) - (1 / (sqrt(1 - x * x)));
}
int main() {
    setlocale(LC_ALL, "RU");
    double x0, x1;
    double eps = 1e-6; // Точность
    int maxIterations = 100; // Максимальное число итераций
    cout << "Введите начальное приближение x0: ";
    cin >> x0;
    for (int i = 0; i < maxIterations; ++i) {
        // Проверка на деление на ноль
        if (abs(df(x0)) < numeric_limits<double>::epsilon()) {
            cout << "Производная равна нулю. Метод Ньютона не сходится." << endl; // Возвращаем код ошибки
        }
        x1 = x0 - f(x0) / df(x0);
        cout << "Итерация " << i + 1 << ": x = " << x1 << ", f(x) = " << f(x1) << endl;
        if (abs(x1 - x0) < eps) {
            cout << "Решение найдено: x = " << x1 << endl;
            return 0; // Возвращаем код успешного завершения
        }
        x0 = x1;
    }
    cout << "Метод Ньютона не сошелся за " << maxIterations << " итераций." << endl;
    return 0; // Возвращаем код ошибки
}

