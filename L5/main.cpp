#include <iostream> 
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std;

int main()
{
	
	setlocale(LC_ALL, "ru");
	string path = "myFile.txt";
	ifstream in;
	in.open(path);
	int s;
	while (!in.eof()) {

		in >> s;
		
		cout << s << "\t";
		cout << oct << s << "\t";
		cout <<hex<< s;
		cout << endl;
}
	in.close();
	return 0;
}