#include <iostream>
#include "app.h"

using namespace std;

int main() {
	app app;
	int n;
	while (true) {
		app.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> n;

		//防止输入错误数据类型，导致死循环
		int flag = 0;
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> n;
			flag++;
		}

		switch (n) {
		case 0: //退出系统
			app.exitSystem();
			break;
		case 1: //添加职工
			app.addWorker();
			break;
		case 2: //显示职工
			app.showWorker();
			break;
		case 3: //删除职工
			app.delWorker();
			break;
		case 4: //修改职工
			app.changeWorker();
			break;
		case 5: //查找职工
			app.findWorker();
			break;
		case 6: //排序职工
			app.sortWorker();
			break;
		case 7: //清空文件
			app.clearFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}
