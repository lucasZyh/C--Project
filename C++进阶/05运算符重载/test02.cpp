#include <iostream>

using namespace std;

class person {
public:
	int *age;

	person(int age) {
		this->age = new int(age);
	}

	~person()
	{
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
	}

	//重载赋值运算符 
	person& operator=(person& p)
	{
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		this->age = new int(*p.age);

		//返回自身
		return *this;
	}

};

int main() {

	person p1 = person(18);
	person p2 = person(20);

	p2 = p1;
	cout << *p1.age << endl;
	cout << *p2.age << endl;

	return 0;
}
