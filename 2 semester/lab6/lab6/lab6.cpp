#include <iostream>
#include <queue>
using namespace std;
void individual(queue<int> q, int first, int last, int n);
void showcasefromfirst(queue<int> q, int n);
void showcasefromlast(queue<int> q, int n, int a[]);
void addintheend(queue<int> q, int n);
int switchfun(queue<int> q, int n);
int main()
{

    setlocale(LC_ALL, "rus");
    queue<int> q;
    int n;
    cout << "Введите кол-во элементов в очереди" << endl;
    cin >> n;
    cout << "Введите элементы очереди" << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    switchfun(q, n);
    return 0;
}

void individual(queue<int> q, int first, int last, int n) {
    cout << q.front() << "    " << q.back() << endl;
    swap(first, last);
    q.front() = first; q.back() = last;
    cout << q.front() << "    " << q.back() << endl;
    showcasefromfirst(q, n);
}

void showcasefromfirst(queue<int> q, int n) {
    cout << "Ваш список:\n";
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void showcasefromlast(queue<int> q, int n, int a[]) {
    cout << "Ваш список:\n";
    for (int i = 0; i < n; i++) {
        a[i] = q.front();
        q.pop();
    }
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << endl;
}
void addintheend(queue<int> q, int n) {
    int kol;
    cout << "Введите кол-во элементов необоходимое добавить: ";
    cin >> kol;
    for (int i = n; i < n + kol; i++)
    {
        int el;
        cout << "Введите элементы:\n";
        cin >> el;
        q.push(el);
    }

    cout << "Ваш список:\n";
    for (int i = 0; i < n + kol; i++)
    {
        cout << q.front() << endl;
        q.pop();
    }
}

int switchfun(queue<int> q, int n) {
    int a[100];
    int first = q.front(), last = q.back();
    cout << "Выберите операцию\n1)Просмотр списка(с первого эл-а)\n2)Просмотр списка(с последнего эл-та)" <<
        "\n3)Добавление элемента\n4)Индивидуальное задание\n0)Выход из программы" << endl;
    int l;
    cin >> l;

    switch (l)
    {
    case 1:
        showcasefromfirst(q, n);
        break;
    case 2:
        showcasefromlast(q, n, a);
        break;
    case 3:
        addintheend(q, n);
        break;
    case 4:
        individual(q, first, last, n);
        break;
    case 0:
        return 0;
    default:
        cout << "ERROR!";
        return 0;
        break;
    }
}
