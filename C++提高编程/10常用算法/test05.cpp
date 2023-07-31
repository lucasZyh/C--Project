#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main5() {
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 0);

	cout << "sum = " << sum << endl;

	v1.resize(20);
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });

	return 0;
}
