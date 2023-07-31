#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main4() {

	srand((unsigned int)time(NULL));
	vector <int> v0;
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++) {
		v0.push_back(i);
		v1.push_back(i);
	}

	v2.resize(v0.size() + v1.size());

	merge(v0.begin(), v0.end(), v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	random_shuffle(v0.begin(), v0.end());

	for_each(v0.begin(), v0.end(), [](int val) {cout << val << " "; });
	cout << endl;

	reverse(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	return 0;
}
