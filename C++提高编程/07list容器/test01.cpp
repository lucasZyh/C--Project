#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main1() {

	list <int> L;
	list <int> L1;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	L1 = L;

	printList(L);
	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);


	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);

	//清空
	L.clear();
	printList(L);

	printList(L1);
	L1.reverse();
	printList(L1);

	L1.sort();
	printList(L1);
	return 0;
}