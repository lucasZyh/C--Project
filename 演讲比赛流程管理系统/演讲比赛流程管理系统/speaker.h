#pragma once
#include <iostream>
using namespace std;

class speaker
{
private:
	string name;
	double score[2];
public:
	speaker();
	~speaker();
	void setName(string name);
	string getName();
	void setScore(double score, int index);
	double getScore(int index);

};

