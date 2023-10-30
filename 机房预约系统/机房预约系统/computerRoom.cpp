#include "computerRoom.h"
#include <fstream>

//预约信息
void InsertMap(map<string, string>& m, string s) {
	string key;
	string value;

	int pos = s.find(":");
	if (pos != -1)
	{
		key = s.substr(0, pos);
		value = s.substr(pos + 1, s.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
}

//初始化机房预约信息
void ComputerRoom::orderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

	this->orderSize = 0; //记录条数

	while (ifs >> date && ifs >> interval && ifs >> stuId &&
		ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;

		InsertMap(m, date);
		InsertMap(m, interval);
		InsertMap(m, stuId);
		InsertMap(m, stuName);
		InsertMap(m, roomId);
		InsertMap(m, status);

		this->orderData.insert(make_pair(this->orderSize, m));
		this->orderSize++;
	}
	ifs.close();
}

//更新预约记录
void ComputerRoom::updateOrder() {
	if (this->orderSize == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < orderSize; i++)
	{
		ofs << "日期:" << this->orderData[i]["日期"] << " ";
		ofs << "时间段:" << this->orderData[i]["时间段"] << " ";
		ofs << "学号:" << this->orderData[i]["学号"] << " ";
		ofs << "姓名:" << this->orderData[i]["姓名"] << " ";
		ofs << "机房:" << this->orderData[i]["机房"] << " ";
		ofs << "状态:" << this->orderData[i]["状态"] << endl;
	}
	ofs.close();
}


