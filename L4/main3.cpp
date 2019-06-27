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
	String& operator = (const String &other) {
		if (this != &other) {
			delete[] value;
		}
		len=strlen(other.value);
		value= new char[len+1];
		for(int i=0; i<len; i++) {
			value[i]=other.value[i];
		}
		value[len]='\0';
		return *this;
	}
	String operator-() const {
		String ret; //временный объект
		ret.len = len; //длина строки
		delete[] ret.value; //освободить старый буфер
		ret.value = new char[len+1]; //буфер под строку
		for (int i=0; i<len; i++) { //копируем в обратном порядке
			ret.value[i] = value[len-i-1];
		}
		ret.value[len] = 0; //нулевое окончание строки
		return ret; //возвращаем временный объект
	}
	String operator + (const String& other) {
		char *s = new char[len + other.len + 1];
		String result(strcat(strcpy(s, value), other.value));
		delete[] s;
		return result;
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
	String d;
	d = string1; // вызывается  перегруженный оператор присваивания
	cout<<"Вывод (присваивание): "<<d<<"\n";
	String string2(string1);
	cout <<"Вывод(копирование): "<< string2<<"\n";
	String string3 = "hello";
	string3= -string3;
	cout << "Перегруженный оператор минуса: "<<string3<<"\n";
	String str("Hello");
	String str2("World");
	String result;
	result = str + str2;
	cout << "Перегруженный оператор плюса: "<<result<<"\n";
	return 0;
}