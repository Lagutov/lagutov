#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string path1 = "input.txt";
	ifstream in;
	in.open(path1);
	cout << "Файл input открыт!"<<endl;
	string s;
	string path2="output.txt";
	ofstream out;
	out.open(path2,ofstream::app);
	cout << "Файл output открыт!";
	while (getline(in, s))
		out << s << endl;
	out << "\n";
	in.close();
	out.close();
	return 0;
}