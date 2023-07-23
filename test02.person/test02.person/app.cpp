#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//联系人结构体
struct person
{
	string name;
	string sex;
	int age;
	string phone;
	string address;
};

//通讯录结构体
struct AdderssBook
{
	struct person Array[MAX];
	int size;
};

void show();//显示菜单界面
int select();//选择功能
void addPerson(AdderssBook* ab);//添加联系人
void showPerson(AdderssBook* ab);//显示联系人
void deletePerson(AdderssBook* ab);//删除联系人
void findPerson(AdderssBook* ab);//查找联系人
void modifyPerson(AdderssBook* ab);//修改联系人
void clearPerson(AdderssBook* ab);//清空联系人

int main() {
	AdderssBook ab = {};
	ab.size = 0;
	while (true) {
		show();//显示菜单界面
		int num = select();//选择功能
		switch (num) {
			case 1:
				cout << "添加联系人" << endl;
				addPerson(&ab);
				break;
			case 2:
				cout << "显示联系人" << endl;
				showPerson(&ab);
				break;
			case 3:
				cout << "删除联系人" << endl;
				deletePerson(&ab);
				break;
			case 4:
				cout << "查找联系人" << endl;
				findPerson(&ab);
				break;
			case 5:
				cout << "修改联系人" << endl;
				modifyPerson(&ab);
				break;
			case 6:
				cout << "清空联系人" << endl;
				clearPerson(&ab);
				break;
			case 0:
				cout << "退出通讯录" << endl;
				return 0;
				break;	
			default:
				cout << "输入错误" << endl;
				break;
		}
	}

	return 0;
}

/*
* 显示菜单界面
*/
void show() {
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
int select() {
	int select = 0;
	cout << "请选择功能：" << endl;
	cin >> select;
	return select;
}

/*
* 添加联系人
*/
void addPerson(AdderssBook *ab) {
	if (ab->size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		ab->Array[ab->size].name = name;

		int sex;
		cout << "请输入性别：" << endl;
		cout << "1....男" << endl;
		cout << "2....女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1) {
				ab->Array[ab->size].sex = "男";
				break;
			}
			else if (sex == 2) {
				ab->Array[ab->size].sex = "女";
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		ab->Array[ab->size].age = age;

		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		ab->Array[ab->size].phone = phone;

		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		ab->Array[ab->size].address = address;

		ab->size++;

		cout << "添加成功" << endl;
		system("cls");
	}
}

/*
* 显示联系人
*/
void showPerson(AdderssBook* ab) {
	if (ab->size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < ab->size; i++) {
			cout << "姓名：" << ab->Array[i].name << "\t";
			cout << "性别：" << ab->Array[i].sex << "\t";
			cout << "年龄：" << ab->Array[i].age << "\t";
			cout << "电话：" << ab->Array[i].phone << "\t";
			cout << "住址：" << ab->Array[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* 判断联系人是否存在
* 存在返回位置，不存在返回-1
*/
int checkPerson(AdderssBook* ab, string name) {
	for (int i = 0; i < ab->size; i++) {
		if (ab->Array[i].name == name) {
			return i;
		}
	}
	return -1;
}

/*
* 删除联系人
*/
void deletePerson(AdderssBook* ab) {
	string name;
	cout << "请输入要删除的联系人姓名：" << endl;
	cin >> name;
	int index = checkPerson(ab, name);

	if (index == -1) {
		cout << "联系人不存在" << endl;
	}
	else {
		for (int i = index; i < ab->size; i++) {
			ab->Array[i] = ab->Array[i + 1];
		}
		ab->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

/*
* 查找联系人
*/
void findPerson(AdderssBook* ab) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int index = checkPerson(ab, name);
	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名：" << ab->Array[index].name << "\t";
		cout << "性别：" << ab->Array[index].sex << "\t";
		cout << "年龄：" << ab->Array[index].age << "\t";
		cout << "电话：" << ab->Array[index].phone << "\t";
		cout << "住址：" << ab->Array[index].address << endl;
	}
	system("pause");
	system("cls");
}

/*
* 修改联系人
*/
void modifyPerson(AdderssBook* ab) {
	string name;
	cout << "请输入您要修改的联系人" << endl;
	cin >> name;

	int index = checkPerson(ab, name);

	if (index == -1) {
		cout << "联系人不存在" << endl;
	}
	else {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		ab->Array[index].name = name;

		int sex;
		cout << "请输入性别：" << endl;
		cout << "1....男" << endl;
		cout << "2....女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1) {
				ab->Array[index].sex = "男";
				break;
			}
			else if (sex == 2) {
				ab->Array[index].sex = "女";
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		ab->Array[index].age = age;

		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		ab->Array[index].phone = phone;

		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		ab->Array[index].address = address;

		cout << "修改成功" << endl;
		system("cls");
	}
}

/*
* 清空联系人
*/
void clearPerson(AdderssBook* ab) {
	ab->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}