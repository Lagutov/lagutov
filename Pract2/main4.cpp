#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int Random()
{
	static mt19937 rand((uint64_t)&rand);
	uniform_int_distribution<int> r(-1000000000, 1000000000);
	return r(rand);
}

int main()
{
	random_device rd;
	vector<int> v1;
	mt19937 rnd(-1000000000);
	steady_clock::time_point vec1 = steady_clock::now();
	for (int i=0; i < 10000000; i++)
		v1.push_back(rnd());
	steady_clock::time_point vec2 = steady_clock::now();
	duration<double> d = vec2 - vec1;
	cout << "I ветор: " << d.count() << endl;
	vector<int> v2(10000000);
	vec1 = steady_clock::now();
	generate(v2.begin(),v2.end(),Random);
	vec2 = steady_clock::now();
	d = vec2 - vec1;
	cout << "II ветор: " << d.count() << endl;
	vec1 = steady_clock::now();
	vector<int> v3(v2);
	vec2 = steady_clock::now();
	cout << "III ветор: " << d.count() << endl;
	vec1 = steady_clock::now();
	sort(v2.begin(),v2.end());
	vec2 = steady_clock::now();
	d = vec2 - vec1;
	cout << "II сортировка: " << d.count() << endl;
	vec1 = steady_clock::now();
	stable_sort(v3.begin(), v3.end());
	vec2 = steady_clock::now();
	d = vec2 - vec1;
	cout << "III сортировка: " << d.count() <<  endl;
}