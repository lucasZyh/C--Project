#include <iostream>
#include <set>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void printSet(const multiset<int>& s) {
	for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main2() {
	multiset <int> s1;

	s1.insert(10);
	s1.insert(60);
	s1.insert(30);
	s1.insert(50);
	s1.insert(30);
	printSet(s1);

	multiset <int, MyCompare> s2;

	s2.insert(10);
	s2.insert(60);
	s2.insert(30);
	s2.insert(50);
	s2.insert(30);

	for (multiset<int, MyCompare>::const_iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
