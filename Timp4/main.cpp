/*! @file main.cpp
* @author Максимов О.В.
* @version 1.0.0
* @date 13.06.2019
* @brief Заголовочный файл для модуля main.cpp
*/
#include <iostream>
#include <cctype>
#include <codecvt>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
bool isValid(const string& s)
{
	locale loc("ru_RU.UTF-8");
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
	wstring ws = codec.from_bytes(s);
	for(auto wc:ws)
		if (!isalpha(wc,loc) || !isupper(wc,loc))
			return false;
	return true;
}
/*! @brief Интерфейс программы
* @details Осуществелние выбора ключа и операции 0, 1 или 2. В зависимости
от выбора выполняются следующие действия: выход, зашифровка,
расшифровка.*/
int main(int argc, char **argv)
{
	string key;
	string text;
	unsigned op;
	cout<<"Cipher ready. Введите ключ: ";
	cin>>key; /// ввод ключа
	if (!isValid(key)) {
		cerr<<"Ключ не принят"<<endl;
		return 1;
	}
	cout<<"Ключ принят"<< endl;
	modAlphaCipher cipher(key);
	do {
		cout<<"Cipher ready. Введите операцию (0-выход,1-Зашифровка, 2-Расшифровка): ";
		cin>>op; /// ввод числа
		if (op > 2) {
			cout<<"Illegal operation"<<endl;
		} else if (op >0) {
			cout<<"Cipher ready. Введите текст: ";
			cin>>text;
			if (isValid(text)) {
				if (op==1) {
					cout<<"Зашифрованный текст:"<<cipher.encrypt(text)<<endl;
				} else {
					cout<<"Расшифрованный текст:"<<cipher.decrypt(text)<<endl;
				}
			} else {
				cout<<"Операция не удалась: неверный формат текста"
				    << endl;
			}
		}
	} while (op!=0);
	return 0;
}
