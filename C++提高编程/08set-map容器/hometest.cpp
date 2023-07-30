#include <iostream>
#include <vector>
#include <map>

using namespace std;

class worker {
private:
	string name;
	int salary;

public:

	worker() {};

	worker(string name, int salary, int status) {
		this->name = name;
		this->salary = salary;
	}
	string getName() {
		return this->name;
	}
	int getSalary() {
		return this->salary;
	}

	void setName(string name) {
		this->name = name;
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
};

int main()
{
	srand((unsigned int)time(NULL));

	vector <worker> workers;
	string workerName = "ABCDEFGHIJ";

	//创建员工
	for (int i = 0; i < 10; i++) {
		worker w;
		string s = "员工";
		s += workerName[i];
		w.setName(s);
		w.setSalary(rand() % 10000 + 10000);
		workers.push_back(w);
	}

	//员工分组
	multimap <int, worker> workerGroup;
	for (vector<worker> ::iterator it = workers.begin(); it != workers.end(); it++) {

		int depId = rand() % 3 + 1;// 1 2 3
		workerGroup.insert(make_pair(depId, *it));
	}

	for (multimap<int, worker> ::iterator it = workerGroup.begin(); it != workerGroup.end(); it++) {
		cout << "部门编号： " << it->first << " 姓名： " << it->second.getName() << " 工资： " << it->second.getSalary() << endl;
	}

	//策划、美术、研发
	cout << "策划部门： " << endl;
	multimap <int, worker> ::iterator pos = workerGroup.find(1);
	int count = workerGroup.count(1);
	int index = 0;
	for (; pos != workerGroup.end() && index < count; pos++, index++) {
		cout << "姓名： " << pos->second.getName() << " 工资： " << pos->second.getSalary() << endl;
	}
	cout << "----------------------" << endl;

	cout << "美术部门： " << endl;
	pos = workerGroup.find(2);
	count = workerGroup.count(2);
	index = 0;
	for (; pos != workerGroup.end() && index < count; pos++, index++) {
		cout << "姓名： " << pos->second.getName() << " 工资： " << pos->second.getSalary() << endl;
	}
	cout << "----------------------" << endl;
	cout << "研发部门： " << endl;
	pos = workerGroup.find(3);
	count = workerGroup.count(3);
	index = 0;
	for (; pos != workerGroup.end() && index < count; pos++, index++) {
		cout << "姓名： " << pos->second.getName() << " 工资： " << pos->second.getSalary() << endl;
	}

	return 0;
}