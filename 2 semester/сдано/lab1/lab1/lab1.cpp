#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct Rating
{
    
public:
    
    string imya;
    int godrozhd, ngruppib;
    double phis, mat, inf, xim;
    
    Rating()
    {
        phis = mat = inf = xim = godrozhd = ngruppib = 0;
    }

    double srball()
    {
        return (phis + mat + inf + xim) / 4;
    }

    void show() 
    {
        cout << "|" << imya << "|\t|" << godrozhd << "|\t|" << ngruppib << "| |" << 
            phis << "|" << mat << "|" << inf << "|" << xim << "| |" << srball() << "|" << endl;
    }

    void add() 
    {
        
        cout << "Введите имя студента(Ф.И.О)" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        getline(cin, imya);
        cout << "Введите год рождения студента:" << endl;
        cin >> godrozhd;
        cout << "Введите номер его группы:" << endl;
        cin >> ngruppib;
        cout << "Отметки студента по физике, математике, информатике, химии:" << endl;
        cin >> phis;
        cin >> mat;
        cin >> inf;
        cin>> xim;
    }

    
};


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    const int n = 10;

   cout << "Выберите операцию:\n1)Создать список;\n2)Показать информацию о студентах(имя, год рождения, номер группы, отметки по предметам, средний балл);"
        "\n3)Добавить студента;\n4)Решение индивидуального задания." << endl;

    int l;
    cin >> l;

    while (l != 1) 
    {
        cout<<"Ошибка! Список не создан! Выберите первый пункт\n";
        cin >> l;
    } 
    Rating* a = new Rating [n];
   

        a[0].imya = "Гуцев В.В";
        a[0].godrozhd = 2004;
        a[0].ngruppib = 190020;
        a[0].phis = 4; a[0].mat = 7; a[0].inf = 9; a[0].xim = 5;

        a[1].imya = "Алексеев А.Б";
        a[1].godrozhd = 2003;
        a[1].ngruppib = 421234;
        a[1].phis = 9; a[1].mat = 8; a[1].inf = 9; a[1].xim = 6;

        a[2].imya = "Борисов А.В";
        a[2].godrozhd = 2004;
        a[2].ngruppib = 531223;
        a[2].phis = 4; a[2].mat = 6; a[2].inf = 4; a[2].xim = 5;

        cout << "Список создан!" << endl;



    int m = 1, k = 0;
    while (true)
    {
        cout << "\n1)Показать информацию о студентах(имя, год рождения, номер группы, отметки по предметам, средний балл);"
            "\n2)Добавить студента;\n3)Решение индивидуального задания;\n0)Выход." << endl;
        cin >> m;

        while (m < 0 || m > 3)
        {
            cout << "Повторите ввод" << endl;
            cin >> m;
        }

        switch (m)
        {
        case 1:

            for (int i = 0; i < 3 + k; i++)
                a[i].show(); 

            break;

        case 2:

            cout << "Сколько студентов требуется добавить?" << endl;

            int f;
            cin >> f;

            if (f >= 0)
            {
                for (int i = 3; i < f + 3; i++)
                {

                    a[i].add();
                    a[i].srball();
                    ++k;

                }

                cout << "Студент успешно добавлен!" << endl;

                for (int i = 0; i < f + 3; i++)
                    a[i].show();

            }

            break;

        case 3:

            for (int i = 0; i < n; i++)
            {

                if ((a[i].mat == 8 || a[i].mat == 9) && a[i].imya < "Баааааааа")
                    a[i].show();
            
            }
            break;
 
        case 0:
            return 0;

        default:
            cout << "Error" << endl;
        }


        
    }
    delete[] a;
}
