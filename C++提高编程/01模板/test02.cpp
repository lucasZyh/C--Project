#include <iostream>

using namespace std;

template <typename T>
void sortArry(T arr[], int len) {
	//选择排序
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}

		if (max != i) {
			T temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
		}
	}
}

template <typename T>
void printArry(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
	sortArry(charArr, num);
	printArry(charArr, num);
}

void test02()
{
	//测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	sortArry(intArr, num);
	printArry(intArr, num);
}

int main2() {

	test01();
	test02();

	return 0;
}