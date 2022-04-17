#include <iostream>
#include <ctime>
using namespace std;

class MyClass
{
private:
	
	bool checkvoltage() {
		int voltage = -5 + rand() % 11;
		if (voltage > 0)
			return true;
		else return false;
	}

public:
	void start()
	{
		if (checkvoltage())
			cout << "coffe grinder is working right now" << endl;
		else
			cout << "coffe grinder was broken by god" << endl;
	}
};

MyClass a;
int choose1(int choose);

int main()
{
	srand(time(NULL));
	cout << "do u wanna use coffe grinder\n\t1)yep\n\t2)nah" << endl;
	int choose;
	cin >> choose;
	choose1(choose);

}




int choose1(int choose) {
	switch (choose)
	{
	case 1:
		a.start();
		break;
	case 2:
		cout << "ok, bye" << endl;
		return 0;
		break;
	default:
		cout << "hasn't work" << endl;
		return 0;
		break;
	}
}
