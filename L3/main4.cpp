#include <iostream>
#include <locale>
#include <string>
using namespace std;

wstring encrypt(const wstring text, const int key);

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring wshifr;
	wstring wshifr2 = L"", wshifr3 = L"";
	wcout << L"Введите слова(о): ";
	getline(wcin,wshifr);
	int key;
	wcout << L"Введите ключ:";
	wcin >> key;
	for (wchar_t & wc: wshifr) {
		if ((wc >= L'а' && wc <= L'я') || (wc >= L'А' && wc <= L'Я')) {
			wc = toupper(wc,loc);
			wshifr2 += wc;
		}
	}

	wcout << wshifr2 << endl;
	wshifr3 = encrypt(wshifr2, key);
	wcout << wshifr3 << endl;
	return 0;
}
wstring encrypt(const wstring text, const int key)

{
	int key1;
	wstring text1 = text;
	wstring str;
	if (key > 32) key1 = key % 32;
	else key1 = key;
	for (wchar_t & wc: text1) {
		if ((wc + key1) > L'Я')
			str += wc + key1 - 32;
		else
			str += wc + key1;
	}
	return str;
}