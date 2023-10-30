#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
class Teacher : public Identity {
public:
	int TeacherId;

	//空参构造
	Teacher();

	//有参构造
	Teacher(string name, string pwd, int id);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//打开老师界面
	virtual void openMenu();
};

