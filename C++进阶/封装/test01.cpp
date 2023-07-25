#include<iostream>

using namespace std;

class circle {
public:
	int r;

	double getS() {
		return 3.14 * r * r;
	}
};


int main1()
{
	cout << "Hello World!" << endl;

	circle c;
	c.r = 10;

	cout << c.getS() << endl;
	return 0;
}
