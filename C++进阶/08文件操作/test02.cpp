#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main2() {

	ifstream ifs("test.txt", ios::in); // 打开文件

	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return 0;
	}
	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close(); // 关闭文件
	return 0;
}
