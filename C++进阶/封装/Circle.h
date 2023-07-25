#pragma once
#include "Point.h"
class Circle {
private:
	Point center;
	int r;

public:
	void setCenter(Point center);
	void setR(int r);

	Point getCenter();
	int getR();
};

