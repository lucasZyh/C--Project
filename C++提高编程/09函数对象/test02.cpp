#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//一元谓词
class GreaterFive {
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

//二元谓词
class mycompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};



int main2() {

	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int> ::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	if (it == v.end()) {
		cout << "Not found" << endl;
	}
	else {
		cout << "Found: " << *it << endl;
	}

	vector<int> v2;

	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(50);
	v2.push_back(20);

	sort(v2.begin(), v2.end());

	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	sort(v2.begin(), v2.end(), mycompare());
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}
