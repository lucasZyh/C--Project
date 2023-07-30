#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque2(const deque<int>& d) {
	for (deque<int> ::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main2() {

	deque <int> d1;
	d1.push_back(85);
	d1.push_back(25);
	d1.push_back(2);
	d1.push_front(888);
	d1.push_back(42354);
	d1.push_back(423);
	d1.push_back(8695);
	d1.push_front(45);

	printDeque2(d1);

	sort(d1.begin(), d1.end());
	printDeque2(d1);
	return 0;
}