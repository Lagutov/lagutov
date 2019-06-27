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
		len=s.len;
		value = new char[len+1]; // выделить память под новый буфер
		for (int i=0; i<=len; i++) // скопировать строку в новый буфер
			value[i]=s.value[i];
		cout<<"Копирование работает!"<<"\n";
	}
	~String() {
		delete[] value;
	}
	friend ostream& operator<<(ostream& os, const String &s);
};
ostream& operator<<(ostream &os, const String &s)
{
	os << s.value;
	return os;
}
int main()
{
	String string1("hello");
	String string2(string1);
	cout <<"Вывод: "<< string2<<"\n";
}