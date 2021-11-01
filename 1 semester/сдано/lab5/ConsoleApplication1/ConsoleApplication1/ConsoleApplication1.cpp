#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
int main()
{
	srand(time(NULL));

	int i, size, arr[10], k=0, f=0, l=0;
	
	cout << "Input size of the array(<=10):" << endl;
	cin >> size;

	cout << "1)Random elements generation \n2)Input from ur keybord" << endl;
	cin >> k;

	switch (k)
	{
	case 1:
		for (i = 0; i < size; i++)
		{
			arr[i] = -5 + rand() % 11;
		}
	break;
	
	case 2:
		cout << "Enter the elements of array" << endl;
		for (i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

	break;
	
	default:
		cout << "error!" << endl;
		break;
	}

	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	for (f = 0; f < size; f++)
	{
		if (arr[f] > 0) 
			break;
	}
	
	for (l = size-1; l >= 0; l--)
	{
		
		if (arr[l] > 0)
			break;
	}

	int s = 0;

	for (i = f + 1; i < l; i++)
	{
		s += arr[i];
	}

	cout << "\nsum = " << s;
}
