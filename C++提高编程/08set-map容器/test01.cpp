#include <iostream>
#include <set>

using namespace std;

int main1() {
	set <int> s1;

	s1.insert(10);
	s1.insert(60);
	s1.insert(30);
	s1.insert(80);
	s1.insert(50);

	set<int>::iterator it = s1.begin();

	for (s1.begin(); it != s1.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;


	// 删除
	s1.erase(s1.begin());
	s1.erase(30);
	//s1.erase(s1.begin(), s1.end());

	// 查找
	set<int>::iterator pos = s1.find(50);
	if (pos != s1.end()) {
		cout << "找到了" << endl;
	}
	else {
		cout << "没找到" << endl;
	}

	// 统计
	int num = s1.count(50);
	cout << "num = " << num << endl;
	return 0;
}
