#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int Random()
{
	static mt19937 rand((uint64_t)&rand);
	uniform_int_distribution<int> r(-1000000000, 1000000000);
	return r(rand);
}

int main()
{
	vector<int> v1;
	mt19937 rnd(-1000000000);
	for (int i=0; i < 10000000; i++)
		v1.push_back(rnd());
	vector<int> v2(10000000);
	generate(v2.begin(),v2.end(),Random);
	vector<int> v3(v2);
	for(auto e:v3)
		cout<<e<<'\t';
	cout<<endl;
}