#include <iostream>
#include "app.h"
#include "speaker.h"


using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int select = -1;
	int flag = 0;
	app app;

	//使用前需求先获得,因为放在循环中,每次都行指向一个新的map,所以需要放在循环外面
	//map <int, speaker> m = app.getSpeaker();


	while (true) {
		app.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> select;

		//输入错误处理
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> select;
			flag++;
		}

		switch (select) {
		case 1:
			cout << "开始演讲比赛" << endl;
			app.startSpeech();
			break;
		case 2:
			cout << "查看往届记录" << endl;
			app.showRecord();
			break;
		case 3:
			cout << "清空比赛记录" << endl;
			app.clearRecord();
			break;
		case 0:
			app.exitSystem();
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}

	}

	system("pause");
	return 0;
}
