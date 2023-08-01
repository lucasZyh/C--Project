#include "app.h"

app::app()
{
	this->initSpeech();//初始化成员属性
	this->createSpeaker();//创建选手
	this->loadRecord();//加载记录
}

app::~app()
{

}

void app::setV0(int v) { this->v0.push_back(v); }

void app::setV1(int v) { this->v1.push_back(v); }

void app::setV2(int v) { this->v2.push_back(v); }

void app::setSpeechNum(int num) { this->speechNum = num; }

void app::setSpeakerMap(int index, speaker sp) { this->Speaker.insert(make_pair(index, sp)); }

void app::setRecordMap(int index, vector<string> v) { this->record.insert(make_pair(index, v)); }

vector<int> app::getV0() { return this->v0; }

vector<int> app::getV1() { return this->v1; }

vector<int> app::getV2() { return this->v2; }

map<int, speaker> app::getSpeaker() { return this->Speaker; }

int app::getSpeechNum() { return this->speechNum; }

map<int, vector<string>> app::getRecord() { return this->record; }

/*
* @brief 显示菜单
*/
void app::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/*
* @brief 退出系统
*/
void app::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

/*
* @brief 初始化成员属性
*/
void app::initSpeech() {
	this->v0.clear();
	this->v1.clear();
	this->v2.clear();
	this->Speaker.clear();
	this->speechNum = 1;
	this->record.clear();
}

/*
* @brief 创建选手
*/
void app::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "选手";
		name += nameSeed[i];

		speaker sp;
		sp.setName(name);

		for (int j = 0; j < 2; j++) {
			sp.setScore(0, j);
		}

		this->setV0(i + 10001);//选手编号

		this->setSpeakerMap(i + 10001, sp);//选手编号和选手的对应关系
	}
}

/*
* @brief 开始比赛
*/
void app::startSpeech() {

	//抽签->比赛->结果

	//第一轮比赛
	this->speechDraw();
	this->speechContest();
	this->showScore();

	//第二轮比赛
	this->speechNum++;
	this->speechDraw();
	this->speechContest();
	this->showScore();

	//4、保存分数
	this->saveRecord();

	//5.数据重置
	this->initSpeech();//初始化成员属性
	this->createSpeaker();//创建选手
	this->loadRecord();//加载记录

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

/*
* @brief 抽签
*/
void app::speechDraw() {
	cout << "第 << " << this->getSpeechNum() << " >> 轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->getSpeechNum() == 1) {
		vector <int> v = this->getV0();

		random_shuffle(v.begin(), v.end());//打乱顺序

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		vector <int> v = this->getV1();

		random_shuffle(v.begin(), v.end());//打乱顺序

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}

/*
* @brief 比赛
*/
void app::speechContest() {
	cout << "------------- 第" << this->getSpeechNum() << "轮正式比赛开始：------------- " << endl;

	multimap<double, int, greater<int>> groupScore; //临时容器，保存key分数 value 选手编号 从大到小

	int num = 0; //记录人员数，6个为1组

	vector<int> v; //比赛选手容器

	if (this->getSpeechNum() == 1)
		v = this->getV0();
	else
		v = this->getV1();

	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++) {
		num++;

		//评委打分
		deque<double> score;
		for (int i = 0; i < 10; i++) {
			double s = (rand() % 401 + 600) / 10.f; //600-1000
			score.push_back(s);
		}
		sort(score.begin(), score.end(), greater<double>()); //从大到小排序
		score.pop_back(); //去掉一个最高分
		score.pop_front(); //去掉一个最低分
		double sum = accumulate(score.begin(), score.end(), 0); //求和
		double avg = sum / (double)score.size();

		//将平均分放入到map容器中
		this->Speaker[*it].setScore(avg, this->getSpeechNum() - 1);

		//将打分结果放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0) {

			if (this->getSpeechNum() == 1)
				cout << "第" << num / 6 << "小组比赛名次：" << endl;

			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "编号：" << it->second << " 姓名：" << this->Speaker[it->second].getName() << " 成绩：" << this->Speaker[it->second].getScore(this->getSpeechNum() - 1) << endl;
			}

			//取前三名
			int count = 0;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++) {
				if (this->getSpeechNum() == 1) {
					this->setV1((*it).second);
				}
				else {
					this->setV2((*it).second);
				}
			}
			groupScore.clear(); //清空临时容器
			cout << endl;
		}
	}
	cout << "------------- 第" << this->getSpeechNum() << "轮比赛完毕：------------- " << endl;
	system("pause");
}

/*
* @brief 显示最终结果
*/
void app::showScore() {
	cout << "---------第" << this->getSpeechNum() << "轮晋级选手信息如下：-----------" << endl;
	vector<int> v;

	if (this->getSpeechNum() == 1)
		v = this->getV0();
	else
		v = this->getV1();

	for_each(v.begin(), v.end(), [&](int id) {
		cout << "选手编号：" << id << " 姓名：" << this->Speaker[id].getName() << " 成绩：" << this->Speaker[id].getScore(this->getSpeechNum() - 1) << endl;
		});
	cout << endl;

	system("pause");
	system("cls");
}

/*
* @brief 保存记录
*/
void app::saveRecord() {

	ofstream ofs("speech.csv", ios::out | ios::app); //用输出流对象创建文件，用于追加写文件

	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		ofs << *it << "," << this->Speaker[*it].getName() << "," << this->Speaker[*it].getScore(1) << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
}

/*
* @brief 读取记录
*/
void app::loadRecord() {
	ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

	//判断文件是否存在
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch); //将上面读取的单个字符放回去

	string data;
	int index = 0; //记录人员数

	while (ifs >> data) {
		//cout << data << endl;
		vector<string> v; //存放6个数据

		int pos = -1; //查找逗号位置
		int start = 0; //起始位置

		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->setRecordMap(index, v);
		index++;
	}
	ifs.close();
}

/*
* @brief 显示往届记录
*/
void app::showRecord() {
	if (this->fileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		map <int, vector<string>>m = this->getRecord();

		for (int i = 0; i < m.size(); i++) {
			cout << "第" << i + 1 << "届" << endl;
			cout << "冠军编号：" << m[i][0] << " 姓名：" << m[i][1] << " 成绩：" << m[i][2] << endl;
			cout << "亚军编号：" << m[i][3] << " 姓名：" << m[i][4] << " 成绩：" << m[i][5] << endl;
			cout << "季军编号：" << m[i][6] << " 姓名：" << m[i][7] << " 成绩：" << m[i][8] << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* @brief 清空记录
*/
void app::clearRecord() {
	int select = 0;
	int flag = 0;

	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
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

	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc); //删除文件中的内容
		ofs.close();

		this->initSpeech();//初始化成员属性
		this->createSpeaker();//创建选手
		this->loadRecord();//加载记录

		cout << "清空成功" << endl;
	}
	system("cls");
}


