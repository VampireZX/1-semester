#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	double f;
	f = pow(M_E, x) / x / x / x - pow(sin(x), 3) - 2;
	return f;
}

double method(double f(double), double x0, double x1, double eps) {
	double x2, y0, y1, de;
	y0 = f(x0); y1 = f(x1);
	do {
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
		de = fabs(x1 - x2);
		x0 = x1; 	x1 = x2; 	y0 = y1; 	y1 = f(x2);
	} while (de > eps);
	return x2;
}


int main() 
{
	setlocale(LC_ALL, "rus");

	double a, b, x, h, m, eps, test;
	a = 4.0; b = 7.0; eps = 0.0001, m = 2;
	
	cout << "Введите шаг: ";
	cin >> h;

	int k = 0;

	for (x = a; x <= b; x = x + h)
	{
		cout << "При x = " << x << " f(x) = " << f(x);
		if (x < b && f(x) * f(x + h) < 0) {
			cout << "\tПромежуток изоляции (" << x << "; " << x + h << ")";
			k++;
		}
		cout << endl;
		cout << "x" << x << " = " << method(f, x, b, eps) << endl;
		
	}
	cout << endl;

	cout << "Кол-во корней: " << k << endl;
	return 0;
}