#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "workerFile.txt"

using namespace std;

class app
{
public:
	int workerNum;//职工人数
	worker** workerArray;//职工数组
	bool isEmpty;//标志文件是否为空

	app();

	~app();

	void showMenu();//显示菜单

	void exitSystem();//退出系统

	void addWorker();//添加职工

	void saveFile();//保存文件

	int getFilewWorkerNum();//获取文件中的人数

	void initWorker();//初始化职工

	void showWorker();//显示职工

	void delWorker();//删除职工

	int checkWorkerExist(int id);//检测职工是否存在

	void changeWorker();//修改职工

	void findWorker();//查找职工

	void sortWorker();//排序职工

	void clearFile();//清空文件

};

