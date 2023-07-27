#include "boss.h"

boss::boss(int id, string name, int deptId) {
	this->setId(id);
	this->setName(name);
	this->setDeptId(deptId);
}

string boss::getDeptName() {
	return string("老板");
}

void boss::showInfo() {
	cout << "职工编号：" << this->getId()
		<< "\t职工姓名：" << this->getName()
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：公司管理" << endl;
}