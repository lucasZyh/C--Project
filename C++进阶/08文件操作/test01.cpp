#include<iostream>
#include<fstream>
using namespace std;

int main1() {
	ofstream of("test.txt", ios::out);

	of << "Hello World!" << endl;
	of << "张三 23" << endl;
	of << "李四 24" << endl;
	of.close();

	return 0;
}
