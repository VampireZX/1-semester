#include <cmath>
#include <iostream>
using namespace std;

double factorial(int k);
double fun1(double x);
double fun2(double x, double sum, double n);
double fun3(double y, double sum);
void Out_Rez(int l, double y, double sum, double m);
void switchfun(int l);

int main()
{
	int n, l, m = 0;
	double a, b, h, sum, x, y = 0;

	cout << "Enter a,b,h,n:\n";
	cout << "a= ";	cin >> a;
	cout << "b= ";	cin >> b;
	cout << "h= ";	cin >> h;
	cout << "n= ";	cin >> n;
	
	cout << "1)Y(x)\n2)S(x)\n3)|Y(x) - S(x)|\n";
	cin >> l;
	switchfun(l);

	for (x = a; x < b; x+=h)
	{
		y = fun1(x); sum = 1;
		sum = fun2(x, sum, n);
		m = fun3(y, sum);
		Out_Rez(l, y, sum, m);
	}	
}

double factorial(int k)
{
	if (k < 0) return 0;
	if (k == 0) return 1;
	else return k * factorial(k - 1);
}


double fun1(double x) {
	return  cos(x);
}


double fun2(double x, double sum, double n)
{
	for (double k = 1; k <= n; k++)
		sum += pow(-1, k) * pow(x, 2 * k) / factorial(2 * k);
	return sum;
}


double fun3(double y, double sum)
{
	return fabs(y - sum);
}


void Out_Rez(int l, double y, double sum, double m)
{
	switch (l)
	{
	case 1:
		cout << y << endl;
		break;

	case 2:
		cout << sum << endl;
		break;

	case 3:
		cout << fabs(y - sum) << endl;
		break;

	default:
		cout << "Error";
		break;
	}
}


void switchfun(int l)
{
	switch (l)
	{
	case 1:
		cout << "Y(x)" << endl;
		break;

	case 2:
		cout << "S(x)" << endl;
		break;

	case 3:
		cout << "|Y(x) - S(x)|" << endl;
		break;

	default:
		cout << "Error";
		break;
	}
}


