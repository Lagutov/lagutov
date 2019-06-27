#include <iostream> 
#include <iomanip>

using namespace std;

void func(int n)
{
	int i, j;
	if (n == 8)
	{
		for (i = 1; i < 8; i++) {
			for (j = 1; j < 8; j++)
				cout << oct << i * j << "\t";
			cout << endl;
		}
	}
	if (n == 10)
	{
		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++)
				cout << i * j << "\t";
			cout << endl;
		}
	}
	if (n == 16)
	{
		for (i = 1; i < 16; i++) {
			for (j = 1; j < 16; j++)
				cout << hex << i * j << "\t";
			cout << endl;
		}
	}
	if (n != 8 && n != 10 && n != 16)
	{
		cout << "Ошибка!Введены неверные данные!";
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a;
	cout << "Введите систему счисления (8,10,16)>> ";
	cin >> a;
	func(a);
}

