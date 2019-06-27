#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char *value;
	int len;
public:
	String():value(new char[1] {}),len(0) {}; // конструктор по умолчанию
	String(const char * s) {
		len = strlen(s);
		value = new char[len + 1];
		strcpy(value, s);
	}
	String(const String& s) {
		len = s.len;
		value = new char[len + 1];
		strcpy(value, s.value);
		cout<<"Копирование работает!"<<"\n";
	}
	~String() {
		delete[] value;
	}
	friend istream& operator >> (istream& is, String& s);
	friend ostream& operator<<(ostream& os, const String &s);
};
istream& operator >> (istream& is, String& s)
{
	is >> s.value;
	return is;
}
ostream& operator<<(ostream &os, const String &s)
{
	os << s.value;
	return os;
}
int main()
{
	String string1;
	cout <<"Введите строку: ";
	cin >> string1;
	String string2(string1);
	cout <<"Вывод: "<< string2<<"\n";
}