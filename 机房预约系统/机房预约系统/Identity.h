#pragma once
#include <iostream>
using namespace std;
#include "ComputerRoom.h"
#include <fstream>

//身份的父类
class Identity {
public:
	//纯虚函数
	virtual void operMenu() = 0;

	virtual void openMenu() = 0;

	//初始化机房容器
	void InitComputerRoom(vector<ComputerRoom>& vCom) {
		//读取机房信息
		ifstream ifs;
		ComputerRoom c;
		ifs.open(COMPUTER_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "文件读取失败" << endl;
			return;
		}
		while (ifs >> c.computerRoomId && ifs >> c.maxNum) {
			vCom.push_back(c);
		}
		cout << "机房数量为: " << vCom.size() << endl;
		ifs.close();
	}

	//用户名
	string username;
	//密码
	string password;
};

