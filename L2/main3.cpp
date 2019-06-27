#include <iostream>

using namespace std;
int main()
{
	int a,sum=0;
	cout<<"Введите числа:\n";
	cin >> a;
	while (a != 0) {
		if (a>0) {
			sum += a;
		}
		cin >> a;
	}
	cout<<"\n Сумма положительных чисел  = "<<sum;

	return 0;
}