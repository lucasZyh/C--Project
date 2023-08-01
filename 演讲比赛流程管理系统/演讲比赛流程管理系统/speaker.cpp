#include "speaker.h"

speaker::speaker()
{
}

speaker::~speaker()
{
}

void speaker::setName(string name)
{
	this->name = name;
}

string speaker::getName()
{
	return this->name;
}

void speaker::setScore(double score, int index)
{
	this->score[index] = score;
}

double speaker::getScore(int index)
{
	return this->score[index];
}

