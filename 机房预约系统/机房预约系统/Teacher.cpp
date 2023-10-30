#include "Teacher.h"

Teacher::Teacher() {
}

Teacher::Teacher(string name, string pwd, int id) {
	this->username = name;
	this->password = pwd;
	this->TeacherId = id;
}

//打开老师界面
void Teacher::openMenu() {
	while (true) {
		this->operMenu();

		char select;
		cin >> select;

		switch (select - '0') {
		case 1:
			//查看所有预约
			cout << "---------------查看所有预约---------------" << endl;
			this->showAllOrder();
			break;
		case 2:
			//审核预约
			cout << "---------------审核预约---------------" << endl;
			this->validOrder();
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

//菜单界面
void Teacher::operMenu() {
	cout << "欢迎老师: " << this->username << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.查看所有预约       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.审核预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.注销登录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作: " << endl;
}

//查看所有预约
void Teacher::showAllOrder() {
	ComputerRoom c;
	c.orderFile();

	if (c.orderSize == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < c.orderSize; i++) {
		cout << i + 1 << "、";
		cout << "预约日期：周 " << c.orderData[i]["日期"];
		cout << " 时间段：" << (c.orderData[i]["时间段"] == "1" ? "上午" : "下午");
		cout << " 学号：" << c.orderData[i]["学号"];
		cout << " 姓名：" << c.orderData[i]["姓名"];
		cout << " 机房：" << c.orderData[i]["机房"];
		string status = " 状态：";
		if (c.orderData[i]["状态"] == "1") {
			status += "审核中";
		}
		else if (c.orderData[i]["状态"] == "2") {
			status += "预约成功";
		}
		else if (c.orderData[i]["状态"] == "-1") {
			status += "审核未通过，预约失败";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
		cout << "--------------------------------------------------------" << endl;
	}

	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder() {
	ComputerRoom c;
	c.orderFile();
	vector<int> v;
	int index = 1;

	if (c.orderSize == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;

	for (int i = 0; i < c.orderSize; i++) {
		if (c.orderData[i]["状态"] == "1") {
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约日期：周 " << c.orderData[i]["日期"];
			cout << " 时间段：" << (c.orderData[i]["时间段"] == "1" ? "上午" : "下午");
			cout << " 学号：" << c.orderData[i]["学号"];
			cout << " 姓名：" << c.orderData[i]["姓名"];
			cout << " 机房：" << c.orderData[i]["机房"];
			cout << " 状态：审核中" << endl;
			cout << "--------------------------------------------------------" << endl;
		}
	}

	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0; //选择审核的预约记录
	char ret = 0; // 记录审核结果

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}

			cout << "请输入审核结果：" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;

			cin >> ret;
			if (ret - '0' == 1) {
				c.orderData[v[select - 1]]["状态"] = "2";
			}
			else {
				c.orderData[v[select - 1]]["状态"] = "-1";
			}

			c.updateOrder();
			cout << "审核完毕！" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}


