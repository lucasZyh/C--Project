#include<iostream>

using namespace std;

class Students {
private:
	string name;
	int age;
	string StudentID;
public:

	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setStudentID(string StudentID) {
		this->StudentID = StudentID;
	}

	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	string getStudentID() {
		return StudentID;
	}
};


int main2() {
	Students s1;
	s1.setName("张三");
	s1.setAge(18);
	s1.setStudentID("20181111");
	cout << "姓名：" << s1.getName() << "\t年龄：" << s1.getAge() <<
		"\t学号：" << s1.getStudentID() << endl;

	return 0;
}
