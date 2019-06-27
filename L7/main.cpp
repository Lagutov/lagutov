#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>

using namespace std;

void findPass(string pass, const string& hash)
{
	crypt_data* pCryptData = new crypt_data;
	size_t pos = hash.find_last_of('$');
	string hashHead = hash.substr(0, pos);
	do {
		string newHash(crypt_r(pass.data(), hashHead.data(), pCryptData));
		if (newHash == hash) {
			cout << "Hash: " << hash << endl << "Pass: " << pass << endl;
			break;
		}
	} while (next_permutation(pass.begin(), pass.end()));
	delete pCryptData;
}

int main()
{ 
int quantity; 
cout << "Введите число хэшей (1 - 8): "; 
cin >> quantity; 
ifstream 
hash2("/home/user/Documents/Lab7/pr1/Release/hash.txt"); 
string *hash3 = new string [quantity]; 
for (int i = 0; i < quantity; i++) { 
hash2 >> hash3[i]; 
} 
string s = "123456789"; 
for (int i = 0; i < quantity; i++) 
findPass(s, hash3[i]); 
return 0; 
}