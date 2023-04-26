#include <iostream>

using namespace std;

void demo() {
	cout << "demo" << endl;
}
void demo(int a) {
	cout << "demo(int a)" << endl;
}

int main() {
	demo();
	demo(10);
	system("pause");
	return 0;
}
