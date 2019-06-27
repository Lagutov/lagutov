#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string path = "myFile.txt";
	ifstream in;
	in.open(path);
	double x,sum=0;
	int n = 0;
	while (in >> x) {
		sum += x;
		n++;
	}
	cout << "Среднее арифметическое = "<< sum / n;
	
	in.close();
	return 0;
}