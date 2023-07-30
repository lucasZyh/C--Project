#include <iostream>
#include <map>

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

int main5() {

	map <person, string, comparePerson> m;

	person p1("刘备", 23);
	person p2("关羽", 27);
	person p3("张飞", 25);
	person p4("赵云", 21);

	m.insert(make_pair(p1, "射手"));
	m.insert(make_pair(p2, "战士"));
	m.insert(make_pair(p3, "坦克"));
	m.insert(make_pair(p4, "刺客"));

	for (map<person, string, comparePerson> ::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "姓名：" << (*it).first.name << " 年龄：" << (*it).first.age << " 职业：" << it->second << endl;
	}

	return 0;
}


