#include <iostream>

using namespace std;

class man {
private:
	string name;
	int* age;
public:
	man() {
		cout << "构造函数调用" << endl;
	}
	man(string name, int age) {
		this->name = name;
		this->age = new int(age);
	}

	~man() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}

		cout << "析构函数调用" << endl;
	}

	man(const man& m) {
		this->name = m.name;
		this->age = new int(*m.age);
	}

	void show() {
		cout << "name = " << name << ", age = " << *age << endl;
	}
};

class test {
public:
	int a;
	int b;
	int c;

	test(int A,int B,int C):a(A), b(B),c(C){}

	void show() {
		cout << "a = " << a << ", b = " << b << endl;
	}
};

int main() {

	man m("lis", 23);
	m.show();
	man n(m);
	n.show();
	test t(10, 20, 30);
	t.show();
	system("pause");
	return 0;
}
