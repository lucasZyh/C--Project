#include<iostream>

using namespace std;

class Cube {
private:
	int L;
	int W;
	int H;

public:

	void setL(int L) {
		this->L = L;
	}
	void setW(int W) {
		this->W = W;
	}
	void setH(int H) {
		this->H = H;
	}

	int getL() {
		return L;
	}
	int getW() {
		return W;
	}
	int getH() {
		return H;
	}

	int getS() {
		return 2 * (L * W + L * H + W * H);
	}
	int getV() {
		return L * W * H;
	}

	bool chearSame(Cube& c) {
		if (L == c.getL() && W == c.getW() && H == c.getH()) {
			return true;
		}
		return false;
	}
};


int main3() {
	Cube c1;
	c1.setL(10);
	c1.setW(20);
	c1.setH(30);

	cout << "长：" << c1.getL() << "\t宽：" << c1.getW() << "\t高：" << c1.getH() << endl;
	cout << "表面积：" << c1.getS() << "\t体积：" << c1.getV() << endl;

	Cube c2{};
	c2.setL(100);
	c2.setW(20);
	c2.setH(30);

	if (c1.chearSame(c2)) {
		cout << "c1和c2相等" << endl;
	}
	else {
		cout << "c1和c2不相等" << endl;
	}

	return 0;
}
