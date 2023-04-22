#include <iostream>
using namespace std;


/*
* 输入信息版本
struct student {
	string name;
	int score;
};

struct teacher {
	string name;
	struct student arr[5];
};

void Init(struct teacher tarr[]) {
	for (int i = 0; i < 3; i++) {
		cout << "请输入老师姓名：" << endl;
		cin >> tarr[i].name;
		for (int j = 0; j < 5; j++) {
			cout << "请输入第"<< j + 1 <<"位学生的姓名：" << endl;
			cin >> tarr[i].arr[j].name;
			cout << "请输入第"<< j + 1 << "位学生的成绩：" << endl;
			cin >> tarr[i].arr[j].score;
		}
	}
}

void Print(struct teacher tarr[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << tarr[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tarr[i].arr[j].name << " 分数：" << tarr[i].arr[j].score << endl;
		}
	}
}

int main10()
{
	int m;
	struct teacher tarr[3];

	cout << "请录入信息：" << endl;
	Init(tarr);
	Print(tarr);
	return 0;
}
*/

//随机生成版本
struct Student
{
	string name;
	int score;
};
struct Teacher
{
	string name;
	Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].name = tName + nameSeed[i];

		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = sName + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;
		}
	}
}

void printTeachers(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main10() {

	srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

	Teacher tArray[3]; //老师数组

	int len = sizeof(tArray) / sizeof(Teacher);

	allocateSpace(tArray, len); //创建数据

	printTeachers(tArray, len); //打印数据

	system("pause");

	return 0;
}