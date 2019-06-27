#include <iostream>

using namespace std;
double* norm(double arr[],const int size)
{
	cout << "Введите числа: ";
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	double min=arr[0];
	double max=arr[0];
	for (int i = 0; i< size; i++) {
		if(arr[i]<min) {
			min=arr[i];
		}
		if(arr[i]>max) {
			max=arr[i];
		}
	}
	double* norm = new double [size];
	for(int i=0; i<size; i++) {
		arr[i]=(arr[i]-min)/(max-min);
		norm[i]=arr[i];
	}
	return norm;
	delete[] norm;

}
int main()
{

	int x;
	cout << "Размер: ";
	cin >> x;
	double *a = new double [x];
	for(int i=0; i<x; i++) {
		cin >> a[i];
	}

	a=norm(a,x);

	for(int i=0; i<x; i++) {
		cout << *(a+i) << endl;
	}

	delete[] a;
	return 0;
}