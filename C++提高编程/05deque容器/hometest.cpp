#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
class Person
{
private:
	string m_Name; //姓名
	int m_Score;  //平均分

public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string getName()
	{
		return this->m_Name;
	}

	int getScore()
	{
		return this->m_Score;
	}

	void setScore(int score)
	{
		this->m_Score = score;
	}

	void setName(string name)
	{
		this->m_Name = name;
	}
};
int main() {

	srand((unsigned int)time(NULL));

	vector <Person> v;

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		//将创建的person对象 放入到容器中
		v.push_back(p);
	}

	for_each(v.begin(), v.end(), [](Person& p) {cout << "姓名： " << p.getName() << "  平均分： " << p.getScore() << endl; });

	for (vector<Person> ::iterator it = v.begin(); it != v.end(); it++) {

		//打分
		deque<int> d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; //60~100
			d.push_back(score);
		}

		//排序
		sort(d.begin(), d.end());


		for (deque<int> ::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//求平均分
		int sum = 0;
		for (deque<int> ::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		//将平均分 赋值给选手
		it->setScore(avg);
	}

	cout << "打分后： " << endl;
	for_each(v.begin(), v.end(), [](Person& p) {cout << "姓名： " << p.getName() << "  平均分： " << p.getScore() << endl; });

	return 0;
}

