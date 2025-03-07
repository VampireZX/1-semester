#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Table
{
	string destination;
	time_t timeDeparture;
	time_t timeArrival;
	int number;
};

template<typename T = int>
void InputNumber(T&, string = "", T = numeric_limits<T>::min(), T = numeric_limits<T>::max());
int Select(const string*, int, string = "");
void ChangeTableInfo(Table&);
void ShowTableInfo(Table);
void ShowTablesInfo(Table[], int);
void InputTime(time_t&, string = "");
void ShowTime(time_t, string = "");
template<typename T = time_t>
void SelectionSort(Table[], int, T Table::* = &Table::timeArrival);
template<typename T = time_t>
void QuickSort(Table[], int, int, T Table::* = &Table::timeArrival);
template<typename T = time_t>
int LinearSearch(Table[], int, T, T Table::* = &Table::timeArrival);
template<typename T = time_t>
int BinarySearch(Table[], int, int, T, T Table::* = &Table::timeArrival);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input, result;
	Table* tables;
	time_t key;
	string variants[][100] = { { "��", "���" }, { "�������� ����", "�������� �����" },
	{ "�������", "���������� ������ �������", "������� ����������", "�������� �����", "�������� �����" } };
	ifstream fin("Structures.txt", ios::binary);
	fin.seekg(0, ios::end);
	if ((int)fin.tellg() > 0 && Select(variants[1], 2) == 1)
	{
		n = (int)fin.tellg() / sizeof(Table);
		fin.seekg(0, ios::beg);
		tables = new Table[n]{};
		fin.read((char*)tables, sizeof(*tables) * n);
		ShowTablesInfo(tables, n);
		while (1)
		{
			if (Select(variants[0], 2, "�������� ����?") == 1)
			{
				InputNumber(input, "����� ����� (�� 1)?\n", 1, n);
				cout << "\n";
				ChangeTableInfo(tables[input - 1]);
				ShowTablesInfo(tables, n);
			}
			else break;
		}
	}
	else
	{
		InputNumber(n, "���������� �������: ", 1);
		cout << "\n";
		tables = new Table[n]{};
		for (int i = 0; i < n; i++) ChangeTableInfo(tables[i]);
	}
	ofstream fout("Structures.txt", ios::binary);
	fout.write((char*)tables, sizeof(*tables) * n);
	fout.close();
	switch (Select(variants[2], 5, "�������� ��������:"))
	{
	case 1:
		InputTime(key, "������� ������ ����� ��������:\n");
		cout << "\n";
		for (int i = 0; i < n; i++) if (tables[i].timeArrival < key) ShowTableInfo(tables[i]);
		break;
	case 2:
		SelectionSort(tables, n);
		ShowTablesInfo(tables, n);
		break;
	case 3:
		QuickSort(tables, 0, n - 1);
		ShowTablesInfo(tables, n);
		break;
	case 4:
		InputTime(key, "������� ������ ����� ��������:\n");
		cout << "\n";
		result = LinearSearch(tables, n, key);
		if (result >= 0) ShowTableInfo(tables[result]);
		else cout << "������� �� ������\n\n";
		break;
	case 5:
		if (Select(variants[0], 2, "������ ����� ������������, ����������?") != 1) break;
		QuickSort(tables, 0, n - 1);
		ShowTablesInfo(tables, n);
		InputTime(key, "������� ������ ����� ��������:\n");
		cout << "\n";
		result = BinarySearch(tables, 0, n, key);
		if (result >= 0) ShowTableInfo(tables[result]);
		else cout << "������� �� ������\n\n";
		break;
	}
	goto Start;
}

template<typename T>
void InputNumber(T& n, string text, T minVlaue, T maxValue)
{
	cout << text;
	while (!(cin >> n) || n < minVlaue || n > maxValue)
	{
		cout << "������� ���������� ��������\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Select(const string* variants, int count, string question)
{
	int choice;
	if (question != "") cout << question << "\n";
	for (int i = 0; i < count; i++) cout << i + 1 << " - " << variants[i] << "\n";
	InputNumber(choice, "", 1, count);
	cout << "\n";
	return choice;
}

void InputTime(time_t& time, string text)
{
	cout << text;
	tm tmTime{ 0, 0, 0, 2, 0, 70 };
	InputNumber(tmTime.tm_hour, "���: ", 0, 23);
	InputNumber(tmTime.tm_min, "������: ", 0, 59);
	time = mktime(&tmTime);
}

void ShowTime(time_t time, string text)
{
	cout << text;
	tm date;
	localtime_s(&date, &time);
	cout << (date.tm_hour < 10 ? "0" : "") << date.tm_hour <<
		":" << (date.tm_min < 10 ? "0" : "") << date.tm_min;
}

void ChangeTableInfo(Table& table)
{
	InputNumber(table.number, "�����: ", 1);
	cout << "����� ����������: ";
	getline(cin, table.destination);
	InputTime(table.timeDeparture, "����� �����������:\n");
	InputTime(table.timeArrival, "����� ��������:\n");
	cout << "\n";
}

void ShowTableInfo(Table table)
{
	cout << "�����: " << table.number << "\n";
	cout << "����� ����������: " << table.destination << "\n";
	ShowTime(table.timeDeparture, "����� �����������: ");
	cout << "\n";
	ShowTime(table.timeArrival, "����� ��������: ");
	cout << "\n\n";
}

void ShowTablesInfo(Table tables[], int n)
{
	for (int i = 0; i < n; i++) ShowTableInfo(tables[i]);
}

template<typename T>
void SelectionSort(Table array[], int n, T Table::* keyPtr)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++) if (array[i].*keyPtr < array[j].*keyPtr) m = j;
		if (m == i) continue;
		Table temp = array[i];
		array[i] = array[m];
		array[m] = temp;
	}
}

template<typename T>
void QuickSort(Table array[], int begin, int end, T Table::* keyPtr)
{
	int left = begin, right = end, middle = (left + right) / 2;
	do
	{
		while (array[left].*keyPtr > array[middle].*keyPtr) left++;
		while (array[right].*keyPtr < array[middle].*keyPtr) right--;
		if (left <= right)
		{
			Table temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) QuickSort(array, begin, right, keyPtr);
	if (left < end) QuickSort(array, left, end, keyPtr);
}

template<typename T>
int LinearSearch(Table array[], int n, T key, T Table::* keyPtr)
{
	int result = -1;
	for (int i = 0; i < n; i++) if (array[i].*keyPtr == key) result = i;
	return result;
}

template<typename T>
int BinarySearch(Table array[], int left, int right, T key, T Table::* keyPtr)
{
	if (left > right) return -1;
	int middle = (left + right) / 2;
	if (array[middle].*keyPtr < key) return BinarySearch(array, left, middle - 1, key, keyPtr);
	if (array[middle].*keyPtr > key) return BinarySearch(array, middle + 1, right, key, keyPtr);
	return middle;
}