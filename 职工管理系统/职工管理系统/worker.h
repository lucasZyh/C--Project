#pragma once
#include <iostream>
using namespace std;

class worker
{
private:
	int id; //职工编号
	string name; //职工姓名
	int deptId; //职工所在部门名称编号

public:

	//构造函数
	void setId(int id);
	int getId();
	void setName(string name);
	string getName();
	void setDeptId(int deptId);
	int getDeptId();

	virtual void showInfo() = 0; //显示个人信息
	virtual string getDeptName() = 0; //获取岗位名称
};

