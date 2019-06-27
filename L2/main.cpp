#include <iostream>

using namespace std;
int main()
{

	int n;
	cout<<"Введите кол-во элментов:";
	cin>>n;
	double a[n];
	cout<<"Введите числа:\n";
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	double sum=0;
	for(int i=0; i<n; i++) {
		sum=sum+a[i];
	}
	cout<<"\nСреднее арифметическое чисел  = "<<sum/n;

	return 0;
}