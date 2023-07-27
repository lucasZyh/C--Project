#include "manager.h"

manager::manager(int id, string name, int deptId) {
	this->setId(id);
	this->setName(name);
	this->setDeptId(deptId);
}

string manager::getDeptName() {
	return string("经理");
}

void manager::showInfo() {
	cout << "职工编号：" << this->getId()
		<< "\t职工姓名：" << this->getName()
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}
