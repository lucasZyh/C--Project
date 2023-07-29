#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class person {

public:
	string name;
	int age;

	person(string name, int age) {
		this->name = name;
		this->age = age;
	}
};


int main2() {
	vector <person> v;

	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for_each(v.begin(), v.end(),
		[](person p) {cout << "姓名：" << p.name << " " << "年龄：" << p.age << endl; });

	return 0;
}
