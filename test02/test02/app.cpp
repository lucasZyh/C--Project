#include <iostream>

using namespace std;
#define MAX 1000

//联系人结构体
struct Person
{
	string name; //姓名
	string sex; //性别：1男 2女
	int age; //年龄
	string phoneNum; //电话
	string addr; //住址
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int num = 0; //通讯录中人员个数
};


void show();
void check(int* select, struct Addressbooks* books);
void addPerson(struct Addressbooks* books);
void showPerson(struct Addressbooks* books);
void deletePerson(struct Addressbooks* books);
int checkPerson(struct Addressbooks* books, string name);
void foundPerson(struct Addressbooks* books);
void modifyPerson(struct Addressbooks* books);
void cleanPerson(struct Addressbooks* books);

int main()
{
	int select = -1;
	struct Addressbooks books;
	check(&select, &books);

	return 0;
}

/*
* 显示菜单
*/
void show()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
/*
* 选择功能
*/
void check(int* select, struct Addressbooks* books) {
	while (*select)
	{
		show();
		cout << "请输入您的选择：" << endl;
		cin >> *select;

		switch (*select) {
		case 1:
			cout << "-------添加联系人-------" << endl;
			addPerson(books);
			break;
		case 2:
			cout << "-------显示联系人-------" << endl;
			showPerson(books);
			break;
		case 3:
			cout << "-------删除联系人-------" << endl;
			deletePerson(books);
			break;
		case 4:
			cout << "-------查找联系人-------" << endl;
			foundPerson(books);
			break;
		case 5:
			cout << "-------修改联系人-------" << endl;
			modifyPerson(books);
			break;
		case 6:
			cout << "-------清空联系人-------" << endl;
			cleanPerson(books);
			break;
		case 0:
			cout << "退出通讯录，欢迎下次使用" << endl;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
}

/*
* 添加联系人
*/
void addPerson(struct Addressbooks* books){
	//判断通讯录是否满
	if (books->num == MAX) {
		cout << "当前通讯录已经填满,无法添加" << endl;
		return;
	}
	else {
		//添加姓名
		cout << "请输入联系人姓名： ";
		cin >> books->personArray[books->num].name;
		//添加性别
		int n = 0;
		cout << "请选择联系人性别： " << endl;
		while (1)
		{
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> n;
			if (n == 1) {
				books->personArray[books->num].sex = "男";
				break;
			}
			else if (n == 2) {
				books->personArray[books->num].sex = "女";
				break;
			}
			else {
				cout << "请输入正确的选项" << endl;
			}
		}
		//添加年龄
		cout << "请选择联系人年龄： ";
		cin >> books->personArray[books->num].age;
		//添加电话
		cout << "请选择联系人电话： ";
		cin >> books->personArray[books->num].phoneNum;
		//添加住址
		cout << "请选择联系人住址： ";
		cin >> books->personArray[books->num].addr;
		//更新通讯录人数
		books->num++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

/*
* 显示联系人
*/
void showPerson(struct Addressbooks* books) {
	if (books->num == 0) {
		cout << "当前通讯录为空，请添加联系人" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < books->num; i++) {
			cout << "编号：" << i + 1 << endl;
			cout << "姓名：" << books->personArray[i].name << endl;
			cout << "性别：" << books->personArray[i].sex << endl;
			cout << "年龄：" << books->personArray[i].age << endl;
			cout << "电话：" << books->personArray[i].phoneNum << endl;
			cout << "住址：" << books->personArray[i].addr << endl;
			cout << "******************" << endl;
		}
		system("pause");
		system("cls");
	}
}
/*
* 删除联系人
*/
void deletePerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "请输入需要删除的联系人姓名： ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = index; i < books->num; i++) {
			books->personArray[i] = books->personArray[i + 1];
		}
		books->num--;
		cout << "删除成功" << endl;
	}

	system("pause");
	system("cls");
}

//判断联系人是否存在
int checkPerson(struct Addressbooks* books, string name) {
	for (int i = 0; i < books->num; i++) {
		if (books->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

/*
* 查找联系人
*/
void foundPerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "请输入需要查询的联系人姓名： ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "编号：" << index + 1 << endl;
		cout << "姓名：" << books->personArray[index].name << endl;
		cout << "性别：" << books->personArray[index].sex << endl;
		cout << "年龄：" << books->personArray[index].age << endl;
		cout << "电话：" << books->personArray[index].phoneNum << endl;
		cout << "住址：" << books->personArray[index].addr << endl;
		cout << "查询成功" << endl;
	}

	system("pause");
	system("cls");
}

/*
*修改联系人
*/
void modifyPerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "请输入需要修改的联系人姓名： ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		//添加姓名
		cout << "请输入修改后联系人姓名： ";
		cin >> books->personArray[index].name;
		//添加性别
		int n = 0;
		cout << "请选择修改后联系人性别： " << endl;
		while (1)
		{
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> n;
			if (n == 1) {
				books->personArray[index].sex = "男";
				break;
			}
			else if (n == 2) {
				books->personArray[index].sex = "女";
				break;
			}
			else {
				cout << "请输入正确的选项" << endl;
			}
		}
		//添加年龄
		cout << "请选择修改后联系人年龄： ";
		cin >> books->personArray[index].age;
		//添加电话
		cout << "请选择修改后联系人电话： ";
		cin >> books->personArray[index].phoneNum;
		//添加住址
		cout << "请选择修改后联系人住址： ";
		cin >> books->personArray[index].addr;

		cout << "修改成功" << endl;
	}

	system("pause");
	system("cls");
}

/*
*清空联系人
*/
void cleanPerson(struct Addressbooks* books){
	books->num = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

