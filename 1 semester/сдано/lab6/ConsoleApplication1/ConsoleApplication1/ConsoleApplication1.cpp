#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	srand(time(NULL));

	int k = 0, t = 0, i = 0, j = 0, f = 0;
	
	int rows;
	cout << "Numb of rows:" << endl;
	cin >> rows;
	
	int col;
	cout << "Numb of cols:" << endl;
	cin >> col;

	cout << endl;
	int** arr;
	arr = new int* [rows];

	for (i = 0; i < rows; i++)
	{
		arr[i] = new int[col];
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = -5 + rand() % 11;
		}
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\n";

	for (j = 0; j < col; j++)
	{
		for (i = 0; i < rows; i++)
		{
			f += arr[i][j];
		}
		for (i = 0; i < rows; i++)
		{
			if (f-arr[i][j]<arr[i][j])
			{
				k++;
			}
		}

		f = 0;
	
	}
	
	cout << "Numb of special elements= " << k << "\t";
	
	for (i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}
