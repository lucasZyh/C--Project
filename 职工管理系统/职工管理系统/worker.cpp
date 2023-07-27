#include "worker.h"

void worker::setId(int id) {
	this->id = id;
}

int worker::getId() {
	return this->id;
}

void worker::setName(string name) {
	this->name = name;
}

string worker::getName() {
	return this->name;
}

void worker::setDeptId(int deptId) {
	this->deptId = deptId;
}

int worker::getDeptId() {
	return this->deptId;
}
