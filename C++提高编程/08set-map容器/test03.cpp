#include <iostream>
#include <set>

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
class comparePerson
{
public:
	bool operator()(const person& p1, const person& p2) const
	{
		//按照年龄进行排序  降序
		return p1.age > p2.age;
	}
};

int main3() {
	set <person, comparePerson> s;

	person p1("刘备", 23);
	person p2("关羽", 27);
	person p3("张飞", 25);
	person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<person, comparePerson> ::iterator it = s.begin(); it != s.end(); it++) {

		cout << "姓名：" << (*it).name << " 年龄：" << (*it).age << endl;
	}
	cout << endl;


	return 0;
}
