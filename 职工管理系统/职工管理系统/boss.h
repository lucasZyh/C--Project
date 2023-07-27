#pragma once
#include "worker.h"

class boss : public worker
{
public:
	boss(int id, string name, int deptId);
	void showInfo();
	string getDeptName();
};

