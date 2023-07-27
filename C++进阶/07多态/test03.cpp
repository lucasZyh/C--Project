#include <iostream>

using namespace std;

class base {
public:
	virtual void fun() = 0;//纯虚函数
};


class son : public base {
public:
	void fun() {
		cout << "son" << endl;
	}
};

int main3() {
	son b;
	b.fun();
	base* b1 = new son;
	b1->fun();
	delete b1;
	return 0;

}
