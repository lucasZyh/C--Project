#include <iostream>
using namespace std;

struct students
{
	string name;  //����
	int age;      //����
	int score;    //����
};

void PrintStudents(struct students s)
{
	cout << "������" << s.name << " ���䣺" << s.age << " ������" << s.score << endl;
}

int main9()
{
	struct students arr[] = {
		{"����",18,80 },
		{"����",19,60 },
		{"����",20,70 }
	};

	struct students *p = &arr[1];

	cout << p->name << endl;
	cout << p->age << endl;
	PrintStudents(arr[2]);

	return 0;
}
