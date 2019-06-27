#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
int main()
{
	locale loc("ru_RU.UTF-8");
	wstring_convert < codecvt_utf8 < wchar_t >, wchar_t > codec;
	string x("x");
	int n;
	cout << "Введите число от 1 до 100 \n";
	cin >> n;
	if (n%10==1 && n!=11){
		string s = "В караване был x верблюд";
		s.replace(s.find(x),x.length(),to_string(n));
		wstring ws = codec.from_bytes(s);
		s = codec.to_bytes(ws);
		cout<< s <<endl;
	}
 else if ((n%10==2 || n%10==3 || n%10==4 ) && (n!=12 && n!=13 && n!=14)){
		string s = "В караване был x верблюд";
		string s1("был");
		string s2("верблюд");
		s.replace(s.find(s1),s1.length(),"было");
		s.replace(s.find(s2),s2.length(),"верблюда");
		s.replace(s.find(x),x.length(),to_string(n));
		wstring ws = codec.from_bytes(s);
		s = codec.to_bytes(ws);
		cout<< s <<endl;
	}
	else ( n%10==5 || n%10==6 || n%10==7  || n%10==8 || n%10==9 || n%10==0 );{
		string s = "В караване был x верблюд";
		string s1("был");
		string s2("верблюд");
		s.replace(s.find(s1),s1.length(),"было");
		s.replace(s.find(s2),s2.length(),"верблюдов");
		s.replace(s.find(x),x.length(),to_string(n));
		wstring ws = codec.from_bytes(s);
		s = codec.to_bytes(ws);
		cout<< s <<endl;
		
	}
	return 0;
}