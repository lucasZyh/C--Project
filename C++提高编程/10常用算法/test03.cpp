#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//自定义数据类型
class Person
{
public:

	Person() {};

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator()(const Person& p) const
	{
		return p.m_Age < 35;
	}

	string m_Name;
	int m_Age;
};

int main3() {
	vector<Person> v;
	Person p;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), p);
	cout << "小于35岁的个数：" << num << endl;

	return 0;
}
