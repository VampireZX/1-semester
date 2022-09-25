#include <iostream>
#include <windows.h>
#include "Header.h"
using namespace std;

void Menu(Queue* begin, Queue* end)
{
	while (true)
	{
		cout << "1 - ������� �������\n2 - ����������\n3 - ��������\n4 - ������� ������� ��� ������ �������\n5 - �������� �������\n6 - �������������� �������\n7 - �������� �������� �� �������(�� �����)\n0 - �����\n��� �����: ";
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			system("cls");
			int info, size, choice;
			QueueLibrary::Create_First_Element(&begin, &end, 0);
			cout << "������� ���-�� ��������� �������: ";
			cin >> size;
			system("cls");
			cout << "�������� ������ ���������� �������:\n1 - ��������� ���������� ������� � ��������� �� -25 �� 25\n2 - ��������� � ����������\n";
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
					cout << "������� " << i + 1 << "-� ������� �������: ";
					cin >> info;
					QueueLibrary::Push_to_end(&begin, &end, info);
				}
				break;
			}
			QueueLibrary::Pop_from_begin(&begin);
			cout << "������� �������.\n";
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			int choice, info = 0;
			cout << "����� �������� ������ �������� �������?\n1 - �������� ��������� ����� � ��������� �� -25 �� 25\n2 - �������� � ����������\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				info = rand() % 51 - 25;
				break;
			case 2:
				system("cls");
				cout << "������� �����: ";
				cin >> info;
				break;
			}
			system("cls");
			cout << "���� �� ������ �������� �������?\n1 - � ������\n2 - � �����\n";
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
			cout << "������� ��������.";
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			int choice;
			cout << "�������� ������ ��������� �������:\n1 - � ������\n2 - � �����\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				cout << "--�������--\n";
				QueueLibrary::View_from_begin(begin);
				break;
			case 2:
				cout << "--�������--\n";
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
			cout << "�������� ����� ������� ������ �������:\n1 - ������ �������\n2 - ������ �������\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				QueueLibrary::Pop_from_begin(&begin);
				cout << "������� ������� �����.\n";
				break;
			case 2:
				QueueLibrary::Pop_from_end(&end);
				cout << "������ ������� �����.\n";
				break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			QueueLibrary::�lear_queue(&begin);
			cout << "������� �������.\n";
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "�������������� �������: � ��������� ������� ��������� ������� �������������� � �������� �� ��� ������ �������� ���������.\n";
			if (begin != nullptr)
			{
				cout << "������� ��:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
				QueueLibrary::Individual_Task(begin);
				cout << "\n������� �����:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
			}
			else
				cout << "������� �����.\n";
			system("pause");
			system("cls");

			break;
		}
		case 7:
		{
			system("cls");
			int key;
			cout << "������� ���� ��� �������� ���������: ";
			cin >> key;
			system("cls");
			if (begin != nullptr)
			{
				cout << "������� ��:\n";
				QueueLibrary::View_from_begin(begin);
				cout << endl;
				int check = QueueLibrary::Remove_element(key, &begin, &end);
				if (check == 0)
				{
					cout << "�������� � �������� ������ ���� � �������.";
				}
				else
				{
					cout << "\n������� �����:\n";
					QueueLibrary::View_from_begin(begin);
				}
				cout << endl;
			}
			else
				cout << "������� �����.\n";
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
			cout << "������ �������� ���.\n";
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