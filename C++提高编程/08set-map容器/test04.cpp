#include <iostream>
#include <map>

using namespace std;

class MyCompare {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;//从大到小排
	}
};

int main4() {

	map <int, int, MyCompare> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(make_pair(5, 66));

	for (map<int, int, MyCompare> ::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key=" << (*it).first << " Value=" << it->second << endl;
	}
	cout << m.size() << endl;

	//删除
	m.erase(3);
	for (map<int, int, MyCompare> ::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key=" << (*it).first << " Value=" << it->second << endl;
	}
	cout << m.size() << endl;

	//查找
	map<int, int, MyCompare>::iterator pos = m.find(2);

	if (pos != m.end()) {
		cout << "找到了元素 key = " << (*pos).first << " value = " << pos->second << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}

	//统计
	int num = m.count(2);
	cout << "num = " << num << endl;

	return 0;
}
