#pragma once
#include <iostream>
using namespace std;
#include "GlobalFile.h"
#include <vector>
#include <map>


class ComputerRoom {
public:
	//机房ID号
	int computerRoomId;

	//机房最大容量
	int maxNum;

	//预约记录条数
	int orderSize;

	//初始化机房预约信息
	void orderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
	map<int, map<string, string>> orderData;

};
