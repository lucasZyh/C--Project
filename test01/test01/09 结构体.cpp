#include <iostream>
using namespace std;

struct students
{
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

void PrintStudents(struct students s)
{
	cout << "姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}

int main9()
{
	struct students arr[] = {
		{"张三",18,80 },
		{"李四",19,60 },
		{"王五",20,70 }
	};

	struct students *p = &arr[1];

	cout << p->name << endl;
	cout << p->age << endl;
	PrintStudents(arr[2]);

	return 0;
}
