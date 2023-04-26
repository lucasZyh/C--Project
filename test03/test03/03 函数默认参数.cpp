#include <iostream>

using namespace std;
void add(int a, int b = 2, int c = 1) {
	cout << a + b + c << endl;
}
int main3() {

	int a = 10;
	int b = 200;

	add(a);

	return 0;
}
