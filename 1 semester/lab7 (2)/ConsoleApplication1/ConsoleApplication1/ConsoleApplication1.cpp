#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string str;
	int t, k;
	cout << "Enter the groups of '0' and '1' without spaces:\n";

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		k = i;

		while (str[i] == str[i + 1])
		{
			i++;
		}

		if ((i - k) % 2)
		{
			for (t = k; t <= i; t++)
			{
				cout << str[t];
			}
			cout << " ";
		}

	}
}
