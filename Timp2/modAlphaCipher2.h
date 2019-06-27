#pragma once
#include <string>
using namespace std;
class shifr
{
	char** value;
	int m, n;
public:
	shifr() = delete;
	shifr(int key, const string& s);
	string encrypt(const string& open_text);
	string decrypt(const string& cipher_text);
	~shifr();
};
