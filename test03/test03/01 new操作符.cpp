#include <iostream>

using namespace std;

void test01() {
	int* p = new int[10];
	for (int i = 0; i < 10; i++) {
		p[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}
	delete[] p;
}

int main01() {
	//����
	//int *p = new int(10);
	//cout << *p << endl;
	//cout << *p << endl;
	//delete p;
	//cout << *p << endl;

	//����
	test01();
	system("pause");
	
	return 0;
}
