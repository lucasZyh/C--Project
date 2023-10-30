#include "Student.h"

Student::Student() {
}

Student::Student(string name, string pwd, int id) {
	this->username = name;
	this->password = pwd;
	this->StudentId = id;
	this->InitComputerRoom(vCom);
}

//打开学生界面
void Student::openMenu() {
	while (true) {
		this->operMenu();

		char select;
		cin >> select;

		switch (select - '0') {
		case 1:
			//申请预约
			cout << "---------------申请预约---------------" << endl;
			this->applyOrder();
			break;
		case 2:
			//查看我的预约
			cout << "---------------查看我的预约---------------" << endl;
			this->showMyOrder();
			break;
		case 3:
			//查看所有预约
			cout << "---------------查看所有预约---------------" << endl;
			this->showAllOrder();
			break;
		case 4:
			//取消预约
			cout << "---------------取消预约---------------" << endl;
			this->cancelOrder();
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
void Student::operMenu() {
	cout << "欢迎学生代表: " << this->username << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.申请预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.查看我的预约       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.查看所有预约       |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.取消预约           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.注销登录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作: " << endl;
}

//申请预约
void Student::applyOrder() {
	char date = 0; //日期
	char interval = 0; //时间段
	char room = 0; //机房编号

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "***************************************" << endl;
	while (true) {
		cin >> date;
		if (date - '0' >= 1 && date - '0' <= 5) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	cout << "***************************************" << endl;
	while (true) {
		cin >> interval;
		if (interval - '0' == 1 || interval - '0' == 2) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << i + 1 << "、" << vCom[i].computerRoomId << "号机房容量：" << vCom[i].maxNum << endl;
	}
	cout << "***************************************" << endl;
	while (true) {
		cin >> room;
		if (room - '0' >= 1 && room - '0' <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;
	ofstream ofs(ORDER_FILE, ios::app);

	ofs << "日期:" << date << " ";
	ofs << "时间段:" << interval << " ";
	ofs << "学号:" << this->StudentId << " ";
	ofs << "姓名:" << this->username << " ";
	ofs << "机房:" << room << " ";
	ofs << "状态:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

//查看自身预约
void Student::showMyOrder() {
	ComputerRoom c;
	c.orderFile();

	if (c.orderSize == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < c.orderSize; i++) {
		if (atoi(c.orderData[i]["学号"].c_str()) == this->StudentId) {
			cout << "预约日期：周 " << c.orderData[i]["日期"];
			cout << " 时间段：" << (c.orderData[i]["时间段"] == "1" ? "上午" : "下午");
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
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder() {
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

//取消预约
void Student::cancelOrder() {
	ComputerRoom c;
	c.orderFile();

	if (c.orderSize == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	cout << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < c.orderSize; i++) {
		if (atoi(c.orderData[i]["学号"].c_str()) == this->StudentId) {
			if (c.orderData[i]["状态"] == "1" || c.orderData[i]["状态"] == "2") {
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周 " << c.orderData[i]["日期"];
				cout << " 时间段：" << (c.orderData[i]["时间段"] == "1" ? "上午" : "下午");
				cout << " 机房：" << c.orderData[i]["机房"];
				string status = " 状态：";
				if (c.orderData[i]["状态"] == "1") {
					status += "审核中";
				}
				else if (c.orderData[i]["状态"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}

			c.orderData[v[select - 1]]["状态"] = "0";
			c.updateOrder();
			cout << "已取消预约" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}