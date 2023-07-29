#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
* string& operator=(const char* s);             //char*类型字符串 赋值给当前的字符串
* string& operator=(const string &s);         //把字符串s赋给当前的字符串
* string& operator=(char c);                          //字符赋值给当前的字符串
* string& assign(const char *s);                  //把字符串s赋给当前的字符串
* string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
* string& assign(const string &s);              //把字符串s赋给当前字符串
* string& assign(int n, char c);                 //用n个字符c赋给当前字符串
*/

void test01()
{
	string s1;
	s1 = "hello world";

	string s2;
	s2 = s1;

	string s3;
	s3 = 'a';

	string s4;
	s4.assign("hello c++");

	string s5;
	s5.assign("hello c++", 5);

	string s6;
	s6.assign(s5);

	string s7;
	s7.assign(10, 'w');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
}

/*
* `string& operator+=(const char* str);`                   //重载+=操作符
* `string& operator+=(const char c);`                         //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                     //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`	//字符串s中从pos开始的n个字符连接到字符串结尾
*/

void test02() {
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;

	str1 += ':';
	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 4);
	//str3.append(str2);
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;
}

int main2() {

	test01();
	test02();
	return 0;
}
