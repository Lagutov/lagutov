#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>
using namespace std;
void findPass(string pass, const string& hash, string
              name)
{
	static mutex mtx;
	crypt_data *pCryptData = new crypt_data;
	size_t pos = hash.find_last_of('$');
	string hashHead = hash.substr(0,pos);
	do {
		string
		newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
		if (newHash == hash) {
			lock_guard<mutex> lock(mtx);
			cout<<"Hash: "<<hash<<endl<<"Pass:"<<pass<<endl;
			break;
		}
	} while ( next_permutation( pass.begin(),
	                            pass.end() ) );
	delete pCryptData;
}
int main ()
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
	thread th_1, th_2,th_3,th_4,th_5,th_6,th_7,th_8;
	if (quantity ==1) {
		for(int i = 0; i < quantity-1; i++) {
			th_1 = thread(findPass, s, hash3[i],
			              "First");
		th_1.join();}
	}else if (quantity ==2) {
		for(int i = 0; i < quantity-1; i++) {
			th_1 = thread(findPass, s, hash3[i],
			              "First");
			th_2 = thread(findPass, s, hash3[i+1],
			              "Second");
			th_1.join();
			th_2.join();
		}
	} else if(quantity == 4) {
		for(int i = 0; i < quantity-3; i++) {
			th_1 = thread(findPass, s, hash3[i],
			              "First ");
			th_2 = thread(findPass, s, hash3[i+1],
			              "Second ");
			th_3 = thread(findPass, s, hash3[i+2],
			              "Third ");
			th_4 = thread(findPass, s, hash3[i+3],
			              "Fourth ");
			th_1.join();
			th_2.join();
			th_3.join();
			th_4.join();
		}
	} else if(quantity == 8) {
		for(int i = 0; i < quantity-7; i++) {
			th_1 = thread(findPass, s, hash3[i],
			              "First ");
			th_2 = thread(findPass, s, hash3[i+1],
			              "Second ");
			th_3 = thread(findPass, s, hash3[i+2],
			              "Third ");
			th_4 = thread(findPass, s, hash3[i+3],
			              "Fourth ");
			th_5 = thread(findPass, s, hash3[i+4],
			              "Fifth ");
			th_6 = thread(findPass, s, hash3[i+5],
			              "Sixth ");
			th_7 = thread(findPass, s, hash3[i+6],
			              "Seventh ");
			th_8 = thread(findPass, s, hash3[i+7],
			              "Eighth ");
			th_1.join();
			th_2.join();
			th_3.join();
			th_4.join();
			th_5.join();
			th_6.join();
			th_7.join();
			th_8.join();
		}
	}
	return 0;
}