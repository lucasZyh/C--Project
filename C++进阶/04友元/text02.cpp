#include<iostream>

using namespace std;

class Building;

class goodGay
{
public:

	goodGay();
	void visit();

private:
	Building* building;
};


class Building
{
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class goodGay;

public:
	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}


int main() {

	goodGay gg;
	gg.visit();
	return 0;
}
