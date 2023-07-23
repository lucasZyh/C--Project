#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//��ϵ�˽ṹ��
struct person
{
	string name;
	string sex;
	int age;
	string phone;
	string address;
};

//ͨѶ¼�ṹ��
struct AdderssBook
{
	struct person Array[MAX];
	int size;
};

void show();//��ʾ�˵�����
int select();//ѡ����
void addPerson(AdderssBook* ab);//�����ϵ��
void showPerson(AdderssBook* ab);//��ʾ��ϵ��
void deletePerson(AdderssBook* ab);//ɾ����ϵ��
void findPerson(AdderssBook* ab);//������ϵ��
void modifyPerson(AdderssBook* ab);//�޸���ϵ��
void clearPerson(AdderssBook* ab);//�����ϵ��

int main() {
	AdderssBook ab = {};
	ab.size = 0;
	while (true) {
		show();//��ʾ�˵�����
		int num = select();//ѡ����
		switch (num) {
			case 1:
				cout << "�����ϵ��" << endl;
				addPerson(&ab);
				break;
			case 2:
				cout << "��ʾ��ϵ��" << endl;
				showPerson(&ab);
				break;
			case 3:
				cout << "ɾ����ϵ��" << endl;
				deletePerson(&ab);
				break;
			case 4:
				cout << "������ϵ��" << endl;
				findPerson(&ab);
				break;
			case 5:
				cout << "�޸���ϵ��" << endl;
				modifyPerson(&ab);
				break;
			case 6:
				cout << "�����ϵ��" << endl;
				clearPerson(&ab);
				break;
			case 0:
				cout << "�˳�ͨѶ¼" << endl;
				return 0;
				break;	
			default:
				cout << "�������" << endl;
				break;
		}
	}

	return 0;
}

/*
* ��ʾ�˵�����
*/
void show() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

/*
* ѡ����
*/
int select() {
	int select = 0;
	cout << "��ѡ���ܣ�" << endl;
	cin >> select;
	return select;
}

/*
* �����ϵ��
*/
void addPerson(AdderssBook *ab) {
	if (ab->size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		ab->Array[ab->size].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1....��" << endl;
		cout << "2....Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1) {
				ab->Array[ab->size].sex = "��";
				break;
			}
			else if (sex == 2) {
				ab->Array[ab->size].sex = "Ů";
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}

		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		ab->Array[ab->size].age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		ab->Array[ab->size].phone = phone;

		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		ab->Array[ab->size].address = address;

		ab->size++;

		cout << "��ӳɹ�" << endl;
		system("cls");
	}
}

/*
* ��ʾ��ϵ��
*/
void showPerson(AdderssBook* ab) {
	if (ab->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < ab->size; i++) {
			cout << "������" << ab->Array[i].name << "\t";
			cout << "�Ա�" << ab->Array[i].sex << "\t";
			cout << "���䣺" << ab->Array[i].age << "\t";
			cout << "�绰��" << ab->Array[i].phone << "\t";
			cout << "סַ��" << ab->Array[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* �ж���ϵ���Ƿ����
* ���ڷ���λ�ã������ڷ���-1
*/
int checkPerson(AdderssBook* ab, string name) {
	for (int i = 0; i < ab->size; i++) {
		if (ab->Array[i].name == name) {
			return i;
		}
	}
	return -1;
}

/*
* ɾ����ϵ��
*/
void deletePerson(AdderssBook* ab) {
	string name;
	cout << "������Ҫɾ������ϵ��������" << endl;
	cin >> name;
	int index = checkPerson(ab, name);

	if (index == -1) {
		cout << "��ϵ�˲�����" << endl;
	}
	else {
		for (int i = index; i < ab->size; i++) {
			ab->Array[i] = ab->Array[i + 1];
		}
		ab->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

/*
* ������ϵ��
*/
void findPerson(AdderssBook* ab) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int index = checkPerson(ab, name);
	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "������" << ab->Array[index].name << "\t";
		cout << "�Ա�" << ab->Array[index].sex << "\t";
		cout << "���䣺" << ab->Array[index].age << "\t";
		cout << "�绰��" << ab->Array[index].phone << "\t";
		cout << "סַ��" << ab->Array[index].address << endl;
	}
	system("pause");
	system("cls");
}

/*
* �޸���ϵ��
*/
void modifyPerson(AdderssBook* ab) {
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;

	int index = checkPerson(ab, name);

	if (index == -1) {
		cout << "��ϵ�˲�����" << endl;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		ab->Array[index].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1....��" << endl;
		cout << "2....Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1) {
				ab->Array[index].sex = "��";
				break;
			}
			else if (sex == 2) {
				ab->Array[index].sex = "Ů";
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}

		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		ab->Array[index].age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		ab->Array[index].phone = phone;

		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		ab->Array[index].address = address;

		cout << "�޸ĳɹ�" << endl;
		system("cls");
	}
}

/*
* �����ϵ��
*/
void clearPerson(AdderssBook* ab) {
	ab->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}