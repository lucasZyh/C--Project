#include <iostream>

using namespace std;

//类模板
template <class nameT, class ageT>
class person {
public:
	nameT name;
	ageT age;

	person(nameT name, ageT age) {
		this->name = name;
		this->age = age;
	}
};


//类模板中的成员函数类外实现
template <class nameT, class ageT>
class person2 {
public:
	nameT name;
	ageT age;

	person2(nameT name, ageT age);
	void show();
};

template <class nameT, class ageT>
person2<nameT, ageT>::person2(nameT name, ageT age) {
	this->name = name;
	this->age = age;
}

template <class nameT, class ageT>
void person2<nameT, ageT>::show() {
	cout << this->name << " " << this->age << endl;
}


int main3() {

	person<string, int> p = person<string, int>("张三", 18);

	person2<string, int> p2 = person2<string, int>("李四", 20);
	p2.show();

	cout << p.name << " " << p.age << endl;
	return 0;
}
