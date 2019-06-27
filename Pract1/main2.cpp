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
		double *b = new double [x]; //
		delete[] a;
    
		a = new double[x];
		for(int i=0; i<x; i++) {
			a[i] = b[i];
		}

		normirovka(b,x);

		for(int i=0; i<x; i++) {
			cout << b[i] << endl;
		}
		delete[] b; //
		delete[] a;
		return 0;
}