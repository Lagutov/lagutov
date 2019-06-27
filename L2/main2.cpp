#include <iostream>
using namespace std;
int main()
{
	int n,x;
	cout<<"Искомое число:";
	cin>>x;
	do {
		cout<<"Введите число:";
		cin>>n;
		if (x == n)break;
	} while(n != 0);
	bool f = 0;
	{
		if (x==n)
			f = 1;
	}
	if (f) cout<<"найдено \n";
	else cout<<"не найдено \n";
	return 0;
}