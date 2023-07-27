#include<iostream>

using namespace std;

class person {
public:
	int A;
	int B;

	person() {};
	person(int a, int b) {
		A = a;
		B = b;
	}

	person operator+(person& p) {
		person temp;
		temp.A = this->A + p.A;
		temp.B = this->B + p.B;
		return temp;
	}
};

ostream& operator<<(ostream& out, person& p) {
	out << "a:" << p.A << " b:" << p.B;
	return out;
}

int main1() {

	person p1(10, 10);
	person p2(20, 20);

	person p3 = p1 + p2;

	cout << p3.A << endl;
	cout << p3.B << endl;

	cout << p3 << endl;

	return 0;
}

