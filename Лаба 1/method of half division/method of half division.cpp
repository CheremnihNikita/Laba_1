#include <iostream>
#include <clocale>
#include <cmath> 
using namespace std;
double f(double x)
{
    return acos(x) - sqrt(1 - 0.3 * x * x * x);
}
int main()
{
    setlocale(LC_ALL, "RU");
    const double eps = 1e-6; // точность
    double a, b, x;
    cout << "Введите границы интервала через пробел (a b): ";
    cin >> a >> b;
    while (abs(b - a) > eps){
        x = (a + b) / 2;
        cout << x << endl; // вывод корня
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }
    cout << "Корень: " << (a + b) / 2 << endl;
    return 0;
}