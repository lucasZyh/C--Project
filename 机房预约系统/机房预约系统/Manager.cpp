#include "Manager.h"
#include "GlobalFile.h"
#include <fstream>
#include <algorithm>

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
	this->username = name;
	this->password = pwd;

	//初始化容器
	this->initVector();

}

//打开管理员界面
void Manager::openMenu() {
	while (true) {
		//显示菜单
		this->operMenu();

		char select;
		cin >> select;

		switch (select - '0') {
		case 1:
			//添加账号
			cout << "---------------添加账号---------------" << endl;
			this->addAccount();
			break;
		case 2:
			//查看账号
			cout << "---------------查看账号---------------" << endl;
			this->showAccount();
			break;
		case 3:
			//查看机房信息
			cout << "---------------查看机房---------------" << endl;
			this->showComputer();
			break;
		case 4:
			//清空预约记录
			cout << "---------------清空预约---------------" << endl;
			this->cleanFile();
			break;
		case 0:
			//注销登录
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}

//显示菜单
void Manager::operMenu() {
	cout << "欢迎管理员: " << this->username << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.添加账号           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.查看账号           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.查看机房           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.清空预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.注销登录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作: " << endl;

}

//添加账号
void Manager::addAccount() {
	cout << "请选择添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	char select;
	while (1) {
		cin >> select;
		if (select - '0' == 1) {
			fileName = STUDENT_FILE;
			tip = "请输入学号: ";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select - '0' == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入职工编号: ";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			continue;
		}
	}

	int id;
	string name;
	string pwd;
	int flag = 0;

	cout << tip << endl;

	//判断学号或者职工号是否重复
	while (1) {
		cin >> id;
		//判断输入数据是否正确
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> id;
			flag++;
		}

		if (checkRepeat(id, select - '0')) {
			cout << errorTip << endl;
			continue;
		}
		break;
	}

	cout << "请输入姓名: " << endl;
	cin >> name;
	cout << "请输入密码: " << endl;
	cin >> pwd;

	//将新的账号信息写入文件中
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	ofs.close();
	this->initVector(); //重新加载信息
	system("cls");
}


void printStudent(Student& s) {
	cout << "学号: " << s.StudentId << " 姓名: " << s.username << " 密码: " << s.password << endl;
}

void printTeacher(Teacher& t) {
	cout << "职工号: " << t.TeacherId << " 姓名: " << t.username << " 密码: " << t.password << endl;
}

//查看账号
void Manager::showAccount() {

	cout << "请选择查看内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	char select;
	cin >> select;

	if (select - '0' == 1) {
		//查看所有学生
		cout << "所有学生信息如下: " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select - '0' == 2) {
		//查看所有老师
		cout << "所有老师信息如下: " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下: " << endl;

	for_each(vCom.begin(), vCom.end(), [](ComputerRoom c) {
		cout << "机房编号: " << c.computerRoomId << " 最大容量: " << c.maxNum << endl;
		});
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	//清空之前进行判断
	cout << "是否确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	char select;
	cin >> select;

	if (select - '0' == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector() {
	ifstream ifs;
	vStu.clear();
	vTea.clear();
	vCom.clear();

	//读取学生文件中的数据
	Student s;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	while (ifs >> s.StudentId && ifs >> s.username && ifs >> s.password) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为: " << vStu.size() << endl;
	ifs.close();

	//读取老师文件中的数据
	Teacher t;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	while (ifs >> t.TeacherId && ifs >> t.username && ifs >> t.password) {
		vTea.push_back(t);
	}
	cout << "当前老师数量为: " << vTea.size() << endl;
	ifs.close();

	//读取机房信息
	this->InitComputerRoom(vCom);
}

// 查重函数
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//检测学生重复
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->StudentId) {
				return true; //存在重复
			}
		}
	}
	else {
		//检测老师重复
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->TeacherId) {
				return true;
			}
		}
	}
	return false;
}


