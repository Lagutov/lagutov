#include <iostream>
#include <string>

using namespace std;
int main()
{
	string text = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
	string str1 = "yandex",
	       str2 = "mephi";

	size_t res = text.find(str2, 0);
	if (res != string::npos) {
		while (res != string::npos) {
			text.replace(res, str2.size(), str1);
			res = text.find(str2, res + str1.size());
		}
		cout << text << endl;
	}
	return 0;
}