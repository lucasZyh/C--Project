#include<iostream>

using namespace std;

class Building
{
	//���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
	friend void goodGay(Building* building);
public:
	string m_SittingRoom; //����

private:
	string m_BedRoom; //����

public:

	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}
};


void goodGay(Building* building)
{
	cout << "�û������ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û������ڷ��ʣ� " << building->m_BedRoom << endl;
}


int main1() {

	Building b;
	goodGay(&b);

	cout << "Hello World!" << endl;

	return 0;
}
