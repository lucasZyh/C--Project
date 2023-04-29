#include <iostream>

using namespace std;

const double PI = 3.14;

class circel {
public:

	int r;

	void gerS() {
		cout << "S = " << PI * r * r << endl;
	}
};


int main1()
{
	circel c1;
	c1.r = 2;
	c1.gerS();
	system("pause");
	return 0;
}
