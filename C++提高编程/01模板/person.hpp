#pragma once
#include <iostream>
using namespace std;

template <class nameT, class ageT>
class person {
public:
	nameT name;
	ageT age;

	person(nameT name, ageT age);
	void show();
};

template <class nameT, class ageT>
person<nameT, ageT>::person(nameT name, ageT age) {
	this->name = name;
	this->age = age;
}

template <class nameT, class ageT>
void person<nameT, ageT>::show() {
	cout << this->name << " " << this->age << endl;
}
