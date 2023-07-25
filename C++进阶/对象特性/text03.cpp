#include<iostream>

using namespace std;

class student {
private:
	int age;
public:
	student(){}

	student(int age) :age(age) {}

	int getAge() {
		return age;
	}
};

int main() {
	student s = student(10);

	cout << s.getAge() << endl;
	return 0;
}
