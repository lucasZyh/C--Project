#include <iostream>

using namespace std;
class people {
private:
	string name;
	int age;

public:
	people() {
		cout << "构造函数调用" << endl;
	}
	people(string name, int age) {
		this->name = name;
		this->age = age;
	}
	~people() {
		cout << "析构函数调用" << endl;
	}
	void show() {
		cout << "name = " << name << ", age = " << age << endl;
	}
};
int main4() {
	people p1("zjah",23);
	p1.show();
	people p2(p1);
	p2.show();
	system("pause");
	return 0;
}
