#include<iostream>

using namespace std;

//1�����캯������
// ���ղ��������Ϊ �вκ��޲ι���   �޲��ֳ�ΪĬ�Ϲ��캯��
// �������ͷ����Ϊ ��ͨ����Ϳ�������

class Person1 {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person1() {
		cout << "�޲ι��캯��!" << endl;
	}
	//�вι��캯��
	Person1(int a) {
		age = a;
		cout << "�вι��캯��!" << endl;
	}
	//�������캯��
	Person1(const Person1& p) {
		age = p.age;
		cout << "�������캯��!" << endl;
	}
	//��������
	~Person1() {
		cout << "��������!" << endl;
	}
public:
	int age;
};

//2�����캯���ĵ���

//�����вεĹ��캯��
void test02() {

	//2.1  ���ŷ�������
	Person1 p1(10);
	//ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
	//Person1 p2();

	//2.2 ��ʽ��
	Person1 p2 = Person1(10);
	Person1 p3 = Person1(p2);
	//Person1(10)����д������������  ��ǰ�н���֮����������

	//2.3 ��ʽת����
	Person1 p4 = 10; // Person1 p4 = Person1(10); 
	Person1 p5 = p4; // Person1 p5 = Person1(p4); 

	//ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
	//Person1 p5(p4);
}

int main2() {

	test02();

	return 0;
}
