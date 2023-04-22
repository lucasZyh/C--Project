#include <iostream>

using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string name; //����
	string sex; //�Ա�1�� 2Ů
	int age; //����
	string phoneNum; //�绰
	string addr; //סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int num = 0; //ͨѶ¼����Ա����
};


void show();
void check(int* select, struct Addressbooks* books);
void addPerson(struct Addressbooks* books);
void showPerson(struct Addressbooks* books);
void deletePerson(struct Addressbooks* books);
int checkPerson(struct Addressbooks* books, string name);
void foundPerson(struct Addressbooks* books);
void modifyPerson(struct Addressbooks* books);
void cleanPerson(struct Addressbooks* books);

int main()
{
	int select = -1;
	struct Addressbooks books;
	check(&select, &books);

	return 0;
}

/*
* ��ʾ�˵�
*/
void show()
{
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
void check(int* select, struct Addressbooks* books) {
	while (*select)
	{
		show();
		cout << "����������ѡ��" << endl;
		cin >> *select;

		switch (*select) {
		case 1:
			cout << "-------�����ϵ��-------" << endl;
			addPerson(books);
			break;
		case 2:
			cout << "-------��ʾ��ϵ��-------" << endl;
			showPerson(books);
			break;
		case 3:
			cout << "-------ɾ����ϵ��-------" << endl;
			deletePerson(books);
			break;
		case 4:
			cout << "-------������ϵ��-------" << endl;
			foundPerson(books);
			break;
		case 5:
			cout << "-------�޸���ϵ��-------" << endl;
			modifyPerson(books);
			break;
		case 6:
			cout << "-------�����ϵ��-------" << endl;
			cleanPerson(books);
			break;
		case 0:
			cout << "�˳�ͨѶ¼����ӭ�´�ʹ��" << endl;
			break;
		default:
			cout << "������������������" << endl;
			break;
		}
	}
}

/*
* �����ϵ��
*/
void addPerson(struct Addressbooks* books){
	//�ж�ͨѶ¼�Ƿ���
	if (books->num == MAX) {
		cout << "��ǰͨѶ¼�Ѿ�����,�޷����" << endl;
		return;
	}
	else {
		//�������
		cout << "��������ϵ�������� ";
		cin >> books->personArray[books->num].name;
		//����Ա�
		int n = 0;
		cout << "��ѡ����ϵ���Ա� " << endl;
		while (1)
		{
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> n;
			if (n == 1) {
				books->personArray[books->num].sex = "��";
				break;
			}
			else if (n == 2) {
				books->personArray[books->num].sex = "Ů";
				break;
			}
			else {
				cout << "��������ȷ��ѡ��" << endl;
			}
		}
		//�������
		cout << "��ѡ����ϵ�����䣺 ";
		cin >> books->personArray[books->num].age;
		//��ӵ绰
		cout << "��ѡ����ϵ�˵绰�� ";
		cin >> books->personArray[books->num].phoneNum;
		//���סַ
		cout << "��ѡ����ϵ��סַ�� ";
		cin >> books->personArray[books->num].addr;
		//����ͨѶ¼����
		books->num++;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

/*
* ��ʾ��ϵ��
*/
void showPerson(struct Addressbooks* books) {
	if (books->num == 0) {
		cout << "��ǰͨѶ¼Ϊ�գ��������ϵ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < books->num; i++) {
			cout << "��ţ�" << i + 1 << endl;
			cout << "������" << books->personArray[i].name << endl;
			cout << "�Ա�" << books->personArray[i].sex << endl;
			cout << "���䣺" << books->personArray[i].age << endl;
			cout << "�绰��" << books->personArray[i].phoneNum << endl;
			cout << "סַ��" << books->personArray[i].addr << endl;
			cout << "******************" << endl;
		}
		system("pause");
		system("cls");
	}
}
/*
* ɾ����ϵ��
*/
void deletePerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "��������Ҫɾ������ϵ�������� ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = index; i < books->num; i++) {
			books->personArray[i] = books->personArray[i + 1];
		}
		books->num--;
		cout << "ɾ���ɹ�" << endl;
	}

	system("pause");
	system("cls");
}

//�ж���ϵ���Ƿ����
int checkPerson(struct Addressbooks* books, string name) {
	for (int i = 0; i < books->num; i++) {
		if (books->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

/*
* ������ϵ��
*/
void foundPerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "��������Ҫ��ѯ����ϵ�������� ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "��ţ�" << index + 1 << endl;
		cout << "������" << books->personArray[index].name << endl;
		cout << "�Ա�" << books->personArray[index].sex << endl;
		cout << "���䣺" << books->personArray[index].age << endl;
		cout << "�绰��" << books->personArray[index].phoneNum << endl;
		cout << "סַ��" << books->personArray[index].addr << endl;
		cout << "��ѯ�ɹ�" << endl;
	}

	system("pause");
	system("cls");
}

/*
*�޸���ϵ��
*/
void modifyPerson(struct Addressbooks* books) {
	string name;
	int index = 0;

	cout << "��������Ҫ�޸ĵ���ϵ�������� ";
	cin >> name;
	index = checkPerson(books, name);

	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		//�������
		cout << "�������޸ĺ���ϵ�������� ";
		cin >> books->personArray[index].name;
		//����Ա�
		int n = 0;
		cout << "��ѡ���޸ĺ���ϵ���Ա� " << endl;
		while (1)
		{
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> n;
			if (n == 1) {
				books->personArray[index].sex = "��";
				break;
			}
			else if (n == 2) {
				books->personArray[index].sex = "Ů";
				break;
			}
			else {
				cout << "��������ȷ��ѡ��" << endl;
			}
		}
		//�������
		cout << "��ѡ���޸ĺ���ϵ�����䣺 ";
		cin >> books->personArray[index].age;
		//��ӵ绰
		cout << "��ѡ���޸ĺ���ϵ�˵绰�� ";
		cin >> books->personArray[index].phoneNum;
		//���סַ
		cout << "��ѡ���޸ĺ���ϵ��סַ�� ";
		cin >> books->personArray[index].addr;

		cout << "�޸ĳɹ�" << endl;
	}

	system("pause");
	system("cls");
}

/*
*�����ϵ��
*/
void cleanPerson(struct Addressbooks* books){
	books->num = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

