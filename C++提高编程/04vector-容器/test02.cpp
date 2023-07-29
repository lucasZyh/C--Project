#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector2(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector <int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * 10);
	}
	printVector2(v1);

	v1.pop_back();
	printVector2(v1);

	v1.insert(v1.begin(), 100);
	printVector2(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector2(v1);

	v1.erase(v1.begin());
	printVector2(v1);

	v1.clear();
	printVector2(v1);
}

void test02() {
	vector <int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * 10);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
}

void test03() {
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector2(v1);

	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector2(v2);

	v1.swap(v2);
	printVector2(v1);
	printVector2(v2);


}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}