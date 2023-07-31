#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	//查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());

	if (it == v.end()) {
		cout << "找不到!" << endl;
	}
	else {
		cout << "找到相邻重复元素为:" << *it << endl;
	}
}

int main2() {
	//test01();

	vector<int>v;

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}
	//二分查找
	bool ret = binary_search(v.begin(), v.end(), 55);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	return 0;
}
