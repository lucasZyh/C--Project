#include <iostream>
#include "person.hpp"

using namespace std;

int main4() {


	person<string, int> p = person<string, int>("张三", 18);
	p.show();


	return 0;
}
