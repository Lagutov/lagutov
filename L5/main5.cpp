#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	  ifstream in("data_v19.bin", std::ios::binary);
	double a = 0;
	int const N = 100;
	while (in.read((char*)& a, sizeof(double)))
		cout << a << ' ';
	cout << '\n';
	float m[N] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		m[i] = 1/a;
	}

	ofstream out("outFile.bin", std::ios::binary);
	if (out.is_open())
	{
		for (int i = 0; i < 100; i++)   // выводим массив в файл поэлементно
			out.write((char*)&m[i], sizeof(float));
		out.close();
	}
	return 0;
}

