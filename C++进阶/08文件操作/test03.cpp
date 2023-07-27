#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

int main() {
	ofstream ofs("person.txt", ios::out | ios::binary);

	Person p = Person{ "张三", 18 };

	ofs.write((const char*)&p, sizeof(p));

	ofs.close();

	ifstream ifs("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	ifs.read((char*)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;

	ifs.close();
	return 0;
}
