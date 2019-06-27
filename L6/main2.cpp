#include <iostream>
using namespace std;
template< class T >
void sort(T* a, int size)
{
	T tmp;
	for (int i = 1, j; i < size; ++i)
	{
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; --j)  
			a[j + 1] = a[j];   
		a[j + 1] = tmp;    
	}
}
template <typename T> class Rectangle
{
	T height, width;

public:
	Rectangle() {};
	Rectangle(T _height, T _width) {
		height = _height;
		width = _width;
	}
	
	bool operator >(const Rectangle x) {
		return (height * width > x.height * x.width);
	}
	friend ostream& operator <<(ostream& S, Rectangle x) {
		 S << x.height * x.width;
		 return S;
	}
	 friend bool operator== (const Rectangle& c1, const Rectangle& c2) {
		return (c1.s1 == c2.s2);
	}
	friend bool operator!= (const Rectangle& c1, const Rectangle& c2) {
		return !(c1 == c2);
	}
	friend Rectangle operator*(const Rectangle& d1, const Rectangle& d2) {
		return d1.height* d2.width;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	
	int x = 4, y = 3;
	double a = 6.65, b = 1.0877;
	int s1;
	s1 = x * y;
	double s2;
	s2 = a * b;
	if (s1 == s2)
	{
		cout << "Площади равны!\n";
	}
	else if (s1 != s2)
	{ cout << "Площади не равны!\n"; }
	Rectangle <int> arr[3];
	Rectangle <double> buf[3];
	for (int i = 0; i < 3; i++) {
		Rectangle <int> r(x - i, y);
		arr[i] = r;
		Rectangle <double> f(a - i, b);
		buf[i] = f;
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < 3; i++)
		cout << arr[i] << " ";
	sort(arr, 3);
	cout << "\nСортировка: ";
	for (int i = 0; i < 3; i++)
		cout << arr[i] << " ";
	return 0;
}