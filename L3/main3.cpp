#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9')
			++x;
		else if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
			++y;
		else
			++z;
	}
	cout <<"Кол-во цифр: " << x << endl;
	cout <<"Кол-во букв: " << y << endl;
	cout <<"Кол-во прочих символов: " << z << endl;
	return 0;
}