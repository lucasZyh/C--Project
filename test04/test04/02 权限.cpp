#include <iostream>
#include "student.h"
using namespace std;

int main2()
{
	student s;
	s.setname("Tom");
	s.setid(1001);
	cout << "name = " << s.getname() << endl;
	cout << "id = " << s.getid() << endl;
	system("pause");
	return 0;
}

