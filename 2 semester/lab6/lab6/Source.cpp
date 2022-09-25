#include <iostream>
#include <windows.h>
#include "Header.h"
using namespace std;

void Menu(Queue* begin, Queue* end)
{
	while (true)
	{
		cout << "1 - Создать очередь\n2 - Добавление\n3 - Просмотр\n4 - Удалить верхний или нижний элемент\n5 - Очистить очередь\n6 - Индивидуальное задание\n7 - Удаление элемента из очереди(по ключу)\n0 - Выход\nВаш выбор: ";
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			system("cls");
			int info, size, choice;
			QueueLibrary::Create_First_Element(&begin, &end, 0);
			cout << "Введите кол-во элементов очереди: ";
			cin >> size;
			system("cls");
			cout << "Выберите способ заполнения очереди:\n1 - Заполнить рандомными числами в диапазоне от -25 до 25\n2 - Заполнить с клавиатуры\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				for (int i = 0; i < size; i++)
				{
					info = rand() % 51 - 25;
					QueueLibrary::Push_to_end(&begin, &end, info);
				}
				break;
			case 2:
				for (int i = 0; i < size; i++)
				{
					cout << "Введите " << i + 1 << "-й элемент очереди: ";
					cin >> info;
					QueueLibrary::Push_to_end(&begin, &end, info);
				}
				break;
			}
			QueueLibrary::Pop_from_begin(&begin);
			cout << "Очередь создана.\n";
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			int choice, info = 0;
			cout << "Каким способом хотите добавить элемент?\n1 - Добавить рандомное число в диапазоне от -25 до 25\n2 - Добавить с клавиатуры\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				info = rand() % 51 - 25;
				break;
			case 2:
				system("cls");
				cout << "Введите число: ";
				cin >> info;
				break;
			}
			system("cls");
			cout << "Куда вы хотите добавить элемент?\n1 - В начало\n2 - В конец\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				QueueLibrary::Push_to_begin(&begin, &end, info);
				break;
			case 2:
				QueueLibrary::Push_to_end(&begin, &end, info);
				break;
			}
			system("cls");
			cout << "Элемент добавлен.";
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			int choice;
			cout << "Выберите способ просмотра очереди:\n1 - С начала\n2 - С конца\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				cout << "--Очередь--\n";
				QueueLibrary::View_from_begin(begin);
				break;
			case 2:
				cout << "--Очередь--\n";
				QueueLibrary::View_from_end(end, begin);
				break;
			}
			cout << "-----------\n";
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			int choice;
			cout << "Выберите какой элемент хотите удалить:\n1 - Вехний элемент\n2 - Нижний элемент\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				QueueLibrary::Pop_from_begin(&begin);
				cout << "Верхний элемент удалён.\n";
				break;
			case 2:
				QueueLibrary::Pop_from_end(&end);
				cout << "Нижний элемент удалён.\n";
				break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			QueueLibrary::Сlear_queue(&begin);
			cout << "Очередь удалена.\n";
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "Индивидуальное задание: В созданной очереди вычислить среднее арифметическое и заменить им все четные значения элементов.\n";
			if (begin != nullptr)
			{
				cout << "Очередь до:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
				QueueLibrary::Individual_Task(begin);
				cout << "\nОчередь после:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
			}
			else
				cout << "Очередь пуста.\n";
			system("pause");
			system("cls");

			break;
		}
		case 7:
		{
			system("cls");
			int key;
			cout << "Введите ключ для удаления элементов: ";
			cin >> key;
			system("cls");
			if (begin != nullptr)
			{
				cout << "Очередь до:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
				int check = QueueLibrary::Remove_element(key, &begin, &end);
				if (check == 0)
				{
					cout << "Элемента с заданным ключом нету в очереди.";
				}
				else
				{
					cout << "\nОчередь после:\n";
					QueueLibrary::View_from_begin(begin);
				}
				cout << endl;
			}
			else
				cout << "Очередь пуста.\n";
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			return;
			break;
		}
		default:
		{
			cout << "Такого варианта нет.\n";
			system("pause");
			system("cls");
			break;
		}
		}
	}
}


int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	Queue* begin = nullptr, * end = nullptr;
	Menu(begin, end);
}