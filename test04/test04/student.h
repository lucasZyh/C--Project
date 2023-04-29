#pragma once
#include <iostream>

using namespace std;

class student {
private:
	string name;
	int id;
public:
	void setname(string name);
	string getname();
	void setid(int id);
	int getid();
};

