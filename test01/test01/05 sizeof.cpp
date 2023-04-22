#include <iostream>

using namespace std;

int main5()
{
	short a0 = 10;
	int a1 = 10;
	long a2 = 10;
	long long a3 = 10;
	float a4 = 3.14f;
	double a5 = 3.14;
	char a6 = 'a';
	bool a7 = true;


	cout << "short " << sizeof(a0) << endl;
	cout << "int " << sizeof(a1) << endl;
	cout << "long " << sizeof(a2) << endl;
	cout << "long long " << sizeof(a3) << endl;
	cout << "float " << sizeof(a4) << endl;
	cout << "double " << sizeof(a5) << endl;
	cout << "char " << sizeof(a6) << endl;
	cout << "bool " << sizeof(a7) << endl;
	return 0;
}
