#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "ComputerRoom.h"


class Student : public Identity {
public:
	int StudentId;

	//机房容器
	vector<ComputerRoom> vCom;

	//空参构造
	Student();

	//有参构造
	Student(string name, string pwd, int id);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//打开学生界面
	virtual void openMenu();
};

