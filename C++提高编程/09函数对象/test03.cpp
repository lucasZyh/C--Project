#include <iostream>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class mycopare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void t1() {
	negate <int> n;
	cout << n(50) << endl;

	plus<int> p;
	cout << p(10, 20) << endl;

	multiplies<int> m;
	cout << m(10, 20) << endl;
}

int main3() {

	vector<int> v;
	vector<int> v1;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	v1 = v;
	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), mycopare());

	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	sort(v1.begin(), v1.end(), greater<int>());
	for (vector<int> ::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
