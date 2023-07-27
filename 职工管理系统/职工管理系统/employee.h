#pragma once
#include "worker.h"
class employee : public worker
{
public:
	//构造函数，初始化信息
	employee(int id, string name, int deptId);
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};

