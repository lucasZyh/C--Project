#include <iostream>

using namespace std;

template <typename T>
void change(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main1() {

	int a = 1, b = 2;
	change(a, b);
	cout << a << " " << b << endl;

	double c = 1.1, d = 2.2;
	change(c, d);
	cout << c << " " << d << endl;

	change<int>(a, b);
	cout << a << " " << b << endl;

	change<double>(c, d);
	cout << c << " " << d << endl;

	return 0;
}
