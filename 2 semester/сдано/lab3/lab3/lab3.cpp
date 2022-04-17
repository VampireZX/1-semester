#include <iostream>
using namespace std;

double funer(double n, double k);

// Рекурсивная реализация факториала

double fact1(double n) {
    if (n < 2) return 1;
    else return n * fact1(n - 1);
}

// Нерекурсивная реализация факториала

double fact2(double k) {
    double s = 1;
    for (int i = 1; i <= k; i++)
    {
        s *= i;
    }
    return s;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double n, k, C2 = 0, C1 = 0;
    cout << "Введите целые положительные n и k" << endl;
    cin >> k >> n;

    funer(n, k);

    C1 = fact1(n) / fact1(k) / fact1(n - k);
    C2 = fact2(n) / fact2(k) / fact2(n - k);

    cout << endl << endl;

    cout << C1 << " - результат рекурсивного метода" << endl;
    cout << endl;
    cout << C2 << " - результат нерекурсивного метода" << endl;
     
}

double funer(double n, double k) {
    if (n < 0 || k < 0) {
        cout << "Некорректные значения(n и k должны быть больше 0)" << endl;
        return 0;
    }
    else if (n < k) {
        cout << "n должно быть больше k" << endl;
        return 0;
    }
}
