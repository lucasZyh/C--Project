#include "Circle.h"

void Circle::setCenter(Point center) {
	this->center = center;
}
void Circle::setR(int r) {
	this->r = r;
}

Point Circle::getCenter() {
	return center;
}
int Circle::getR() {
	return r;
}