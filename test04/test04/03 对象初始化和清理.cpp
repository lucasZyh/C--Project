#include <iostream>

using namespace std;

class person {
private:
	string name;
	int age;
public:
	person() {
		cout << "���캯������" << endl;
	}
	person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	~person() {
		cout << "������������" << endl;
	}
	
	void show() {
		cout << "name = " << name << ", age = " << age << endl;
	}
};


int main3()
{
	person p1;
	system("pause");
	return 0;
}
