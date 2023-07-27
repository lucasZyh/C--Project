#include "employee.h"

employee::employee(int id, string name, int deptId) {
	this->setId(id);
	this->setName(name);
	this->setDeptId(deptId);
}

string employee::getDeptName() {
	return string("员工");
}

void employee::showInfo() {
	cout << "职工编号：" << this->getId()
		<< "\t职工姓名：" << this->getName()
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}