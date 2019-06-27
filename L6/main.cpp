#include <iostream>

using namespace std;

template< class T >
void insertSort(T* a, int size)
{
	T tmp;
	for (int i = 1, j; i < size; ++i) // цикл проходов, i - номер прохода
	{
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; --j) // поиск места элемента в готовой последовательности 
			a[j + 1] = a[j];    // сдвигаем элемент направо, пока не дошли
		a[j + 1] = tmp; // место найдено, вставить элемент    
	}
}
template <typename T>
void print(T arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a[] = { 5,2,6,7,1 };
	insertSort(a, 5);
	print(a, 5);
	cout << endl;
	double b[]{ 3.2, 1.2, 6.7,4.4,5.5 };
	insertSort(b, 5);
	print(b, 5);
	return 0;
}