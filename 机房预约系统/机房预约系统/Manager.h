#pragma once
#include <iostream>
#include "Identity.h"
#include "GlobalFile.h"
#include "ComputerRoom.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;


class Manager : public Identity {
public:

	//学生信息
	vector<Student> vStu;

	//老师信息
	vector<Teacher> vTea;

	//机房信息
	vector<ComputerRoom> vCom;

	//空参构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//显示菜单
	virtual void operMenu();

	//打开管理员界面
	virtual void openMenu();

	//添加账号
	void addAccount();

	//查看账号
	void showAccount();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化信息容器
	void initVector();

	//查重函数
	bool checkRepeat(int id, int type);
};

