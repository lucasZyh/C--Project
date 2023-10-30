#include <iostream>
#include "Identity.h" 
#include "GlobalFile.h"
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;
/**
@brief 学生身份验证
* @param fileName 文件路径
* @param type 登录的身份 （1代表学生、2代表老师、3代表管理员）
*/

void LoginIn(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	int flag = 0;

	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//接收用户信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1) cout << "请输入您的学号: " << endl;
	if (type == 2) cout << "请输入您的职工号: " << endl;

	if (type == 1 || type == 2) {
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
	}

	cout << "请输入用户名: " << endl;
	cin >> name;

	cout << "请输入密码: " << endl;
	cin >> pwd;

	int fid;
	string fname;
	string fpwd;

	if (type == 1) {
		//学生登录验证
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "验证登录成功!" << endl;
				system("pause");
				system("cls");
				ifs.close();
				person = new Student(name, pwd, id);
				person->openMenu();
				system("cls");
				return;
			}
		}
	}
	else if (type == 2) {
		//教师登录验证
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "验证登录成功!" << endl;
				system("pause");
				system("cls");
				ifs.close();
				person = new Teacher(name, pwd, id);
				person->openMenu();
				system("cls");
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录验证
		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "验证登录成功!" << endl;
				system("pause");
				system("cls");
				ifs.close();
				person = new Manager(name, pwd);
				person->openMenu();
				system("cls");
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}


int main() {

	char select = 0;

	while (1) {
		cout << "======================  欢迎来到轻大机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";

		cout << "输入您的选择: ";
		cin >> select;

		switch (select - '0')
		{
		case 1:
			cout << "学生代表" << endl;
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			cout << "老师" << endl;
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			cout << "管理员" << endl;
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			exit(0);
			break;
		default:
			cout << "输入有误,请重新输入" << endl;
			break;
		}
	}
	return 0;
}
