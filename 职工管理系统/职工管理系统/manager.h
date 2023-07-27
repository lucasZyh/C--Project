#pragma once
#include "worker.h"
class manager : public worker
{
public:
	manager(int id, string name, int deptId);
	void showInfo();
	string getDeptName();
};

