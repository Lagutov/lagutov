#include <iostream>
#include <locale>
#include <string>
using namespace std;

wstring decrypt(const wstring text, const int key);

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring wdeshifr;
	wstring wdeshifr2 = L"", wdeshifr3 = L"";
	wcout << L"Введите слова(о): ";
	getline(wcin,wdeshifr);
	int key;
	wcout << L"Введите ключ:";
	wcin >> key;
	for (wchar_t & wc: wdeshifr) {
		if ((wc >= L'а' && wc <= L'я') || (wc >= L'А' && wc <= L'Я')) {
			wc = toupper(wc,loc);
			wdeshifr2 += wc;
		}
	}
	wdeshifr3 = decrypt(wdeshifr, key);
	wcout << wdeshifr3 << endl;
	return 0;
}
wstring decrypt(const wstring text, const int key)
{
	int key1, i;
	wstring text1 = text;
	wstring str;
	wstring error = L"ОШИБКА";
	for (i = 0; i < text1.length(); i++)
		if (text1[i] >= L'А' && text1[i] <= L'Я')
			continue;
		else
			return error;
	if (key > 32) key1 = key % 32;
	else key1 = key;
	for (wchar_t & wc: text1) {
		if ((wc - key1) < L'А')
			str += wc - key1 + 32;
		else
			str += wc - key1;
	}
	return str;
}