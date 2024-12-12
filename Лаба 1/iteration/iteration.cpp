#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;
double f(double x){
	return cos(sqrt(1-0.3*x*x*x));
}
int main(){
	setlocale(LC_ALL, "RU");
	const double epsilon = 1e-6;
	double a, b, x0, x1;
	cout << "Введите границы интервала через пробел (a b): ";
	cin >> a >> b;
	x0 = (a + b) / 2;
	x1 = f(x0);
	cout << x0 << endl;
	cout << x1 << endl;
	while (abs(x1 - x0) > epsilon){
		x0 = x1;
		x1 = f(x0);
		cout << x1 << endl;
	}
	cout << "Корень: " << x1 << endl;
	return 0;
}