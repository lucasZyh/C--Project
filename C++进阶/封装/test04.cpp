#include<iostream>
#include "point.h"
#include "Circle.h"

using namespace std;


void cheekIn(Point p, Circle c) {
	int x = p.getX();
	int y = p.getY();
	int r = c.getR();
	int centerX = c.getCenter().getX();
	int centerY = c.getCenter().getY();

	if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) < r * r) {
		cout << "点在圆内" << endl;
	}
	else if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) == r * r) {
		cout << "点在圆上" << endl;
	}
	else {
		cout << "点在圆外" << endl;
	}
}

int main() {
	Point p;
	p.setX(2);
	p.setY(0);

	Circle c;
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);
	c.setR(10);

	cheekIn(p, c);

	return 0;
}
