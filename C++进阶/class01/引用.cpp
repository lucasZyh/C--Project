#include <iostream>
using namespace std;

//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	cout << "a = " << a << endl;
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

int main1() {

	int a = 10;
	int& b = a;

	int arr[2] = { 1, 2 };
	int *p = arr;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "arr = " << *arr << endl;
	cout << "arr = " << *(arr + 1) << endl;
	cout << "arr = " << *p << endl;
	p++;
	cout << "arr = " << *p << endl;

	cout << "********************" << endl;

	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	return 0;
}
