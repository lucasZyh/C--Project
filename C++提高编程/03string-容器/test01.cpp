#include <iostream>
#include <vector>
using namespace std;

int main1() {

	string s1 = "helll";

	const char* str = "hello world";
	string s2(str);

	string s3(s2);

	string s4(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	return 0;
}
