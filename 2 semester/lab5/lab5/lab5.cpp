#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack *next;
};

Stack *push(Stack *p, int chislo);
void view(Stack *p);
void checker(int m);
void individual(Stack *p, int num);
void sort_p(Stack** p);
void sort_info(Stack* p);
void del(Stack** p);

int main()
{

    setlocale(LC_ALL, "rus");

    int num, chislo, l;
    Stack *begin = NULL;

    cout << "\t\t\t\tВыберите операцию\n1)Создать стек\n2)Просмотреть стек\n3)Добавить элемент\n4)Решение индивидуального задания(Поменять местами крайние элементы)\n0)Выход" << endl;
    cin >> l;

    while (l != 1 && l != 0) {

        cout << "Вы не создали стек - повторите ввод:" << endl;
        cin >> l;
    }

    if (!l)
        return 0;

    cout << "Введите кол-во элементов в стеке" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Введите " << i + 1 << "е число: ";
        cin >> chislo;

        begin = push(begin, chislo);

    }

    while (1)
    {
        cout << "\n1)Просмотреть стек\n2)Добавить элемент\n3)Сортировка с помощью перестановки адресов\n4)Сортировка методом обмена иформацией\n5)Решение индивидуального задания(Поменять местами крайние элементы)\n0)Выход" << endl;
        cin >> l;

        switch (l)
        {
        case 1:


            cout << "Ваш стек:\n";

            if (begin)
                view(begin);
            else
            {
                cout << "Стек пуст!";
                return 0;
            }

            break;
        case 2:

            int m;
            cout << "Сколько элементов необоходимо добавить?" << endl;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                cout << "Введите число: ";
                cin >> chislo;
                cout << endl;
                begin = push(begin, chislo);
            }

            checker(m);

            break;

        case 3:
            begin = push(begin, 0);
            sort_p(&begin);
            del(&begin);
            
            cout << "\n";
            view(begin);

            break;
        case 4:
            
            sort_info(begin);
            
            cout << "\n";
            view(begin);

            break;
        case 5:
            
            cout << "Измененный стек:" << endl;
            individual(begin, num);
            view(begin);
            break;
        case 0:
            return 0;
            break;

        default:
            cout << "Некорректный ввод!";

            break;
        }
    }
    return 0;
}

Stack *push(Stack *p, int chislo) 
{

    Stack *temp = new Stack;
    temp->info = chislo;
    temp->next = p;
    return temp;

}

void del(Stack** p) {
    Stack* t;
    t = *p;
    *p = (*p)->next;
    delete t;
}

void view(Stack *p) 
{

    Stack *temp = p;
    while (temp != 0) {
        cout << temp->info << endl;
        temp = temp->next;
    }

}

void checker(int m)
{
    if (m == 1)
        cout << "Элемент добавлен";

    else if (m <= 0)
        cout << "Некорректный ввод";

    else cout << "Элементы добавлены!";
}

void individual(Stack* p, int num)
{

    if (p == 0) {
        cout << "Стек пуст!" << endl;
        return;
    }

    Stack* temp = p, * first = p, * last = p;
    int s;
    
    for (int i = 0; i < num; i++)
    {
       /*if (i == 0) {

            first->info = temp->info;
            first = temp;
        }*/

        if (i == num - 1)
        {
            last = temp;
            //last->info = temp->info;
        }

        temp = temp->next;
    }

    s = first->info;
    first->info = last->info;
    last->info = s;
}

void sort_p(Stack** p) {
    Stack* t = NULL, * t1 = nullptr, * r;

    if ((*p)->next->next == NULL) return;

    do {

        for (t1 = *p; t1->next->next != t; t1 = t1->next) {

            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        }
        t = t1->next;
    } while ((*p)->next->next != t);
}

void sort_info(Stack* p) {

    Stack *t = NULL, *t1 = nullptr;
    int r;
    do {

        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->info > t1->next->info) {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}








