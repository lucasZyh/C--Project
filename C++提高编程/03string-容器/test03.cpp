#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test03() {
	string s1 = "hello world";
	string s2 = "helloworld";

	if (s1.compare(s2) == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else {
		cout << "s1 不等于 s2" << endl;
	}
}

void test04() {
	string s1 = "abcdef";
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " ";
	}
}

void test05() {
	string s1 = "abcdef";
	s1.insert(1, "111");
	s1.erase(1, 3);
	cout << s1 << endl;
}

int main3() {

	//test03();
	//test04();
	test05();

	return 0;
}
