#include <iostream>
using namespace std;

int main7()
{
	int a = 5;
	int b;

	cout << "ÇëÊäÈëbµÄÖµ" << endl;
	cin >> b;

	cout << "a + b = " << a << " + " << b  << " = " << a + b << endl;
	cout << "a - b = " << a << " - " << b  << " = " << a - b << endl;
	cout << "a * b = " << a << " * " << b  << " = " << a * b << endl;
	cout << "a / b = " << a << " / " << b << " = " << a / (b * 1.0) << endl;
	cout << "a % b = " << a << " % " << b  << " = " << a % b << endl;


	cout << "a ++ = " <<  a ++ << endl;
	cout << "++ a = " <<  ++ a << endl;

	return 0;
}