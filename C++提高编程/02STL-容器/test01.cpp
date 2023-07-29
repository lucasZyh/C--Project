#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main1() {

	vector<int> v;

	//插入数据
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个数据

	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置

	while (itBegin != itEnd) {
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });

	return 0;
}
