#include <iostream>
#include <cmath>
using namespace std;
double fun(double k)
{
    return pow(k, 3);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b;
    cout << "Введите два числа" << endl;
    cin >> a >> b;

    cout << fun(a) + fun(b) - fun(a + b);
    
}

