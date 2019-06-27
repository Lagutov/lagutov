#include <iostream>

using namespace std;

template <typename T1, typename T2> class DoubleBox
{
private:
	T1 value1;
	T2 value2;
public:
	DoubleBox() {
		value1 = nullptr;
		value2 = nullptr;
	}
	DoubleBox(const T1 s1, const T2 s2) : value1(s1), value2(s2) {};
	void set(const T1 s1, const T2 s2) {
		value1 = s1;
		value2 = s2;
	}
	void get(T1 &s1, T2 &s2 ) {
		s1 = value1;
		s2 = value2;
		
	}


};

int main()
{
	int x ;
	double y;
	DoubleBox<int, double> c(5,5.6);
	c.set(65, 5.6);
	c.get(x, y);
	cout << x << "\t" << y << endl;
	return 0;
}