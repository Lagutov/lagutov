#include <iostream>

using namespace std;
void normirovka (double arr[],int size)
{
	cout << "Введите числа: ";
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	double min=arr[0];
	double max=arr[0];
	for (int i = 0; i< size; i++) 
		{
			if(arr[i]<min) {
				min=arr[i];
			}
			if(arr[i]>max) {
				max=arr[i];
			}
		}
		for(int i=0; i<size; i++) {
			arr[i]=(arr[i]-min)/(max-min);
		}
	}
	int main() {
		int x;
		cout << "Размер: ";
		cin >> x;
		double *a = new double [x];
		normirovka(a,x);
		for(int i=0; i<x; i++) {
			cout << a[i] << endl;
		}
		delete[] a;
		return 0;
}