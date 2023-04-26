#include <iostream>

using namespace std;
void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}
int main2() {
	int a = 10;
	int b = 200;

	cout << a << endl;
	cout << b << endl;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;

	return 0;
}
