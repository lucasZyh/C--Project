#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <fstream>
#include "speaker.h"
using namespace std;

class app
{
private:
	vector<int>v0;//比赛选手 容器  12人
	vector<int>v1;//第一轮晋级容器  6人
	vector<int>v2;//胜利前三名容器  3人
	map<int, speaker> Speaker;//存放编号 以及对应的 具体选手 容器
	int speechNum;//比赛轮数
	map<int, vector<string>> record;//往届记录
	bool fileIsEmpty;//文件是否为空

public:
	app();// 空参构造

	~app();//析构函数

	vector<int> getV0();//获取
	vector<int> getV1();//获取第一轮晋级选手
	vector<int> getV2();//获取第二轮晋级选手
	map<int, speaker> getSpeaker();//获取选手
	int getSpeechNum();//获取比赛轮数
	map<int, vector<string>> getRecord();//获取记录

	void setV0(int v);//设置比赛选手
	void setV1(int v);//设置第一轮晋级选手
	void setV2(int v);//设置第二轮晋级选手
	void setSpeechNum(int num);//设置比赛轮数
	void setSpeakerMap(int index, speaker sp);//设置选手
	void setRecordMap(int index, vector<string> v);//设置记录

	void showMenu();//显示菜单

	void exitSystem();//退出系统

	void initSpeech();//初始成员属性

	void createSpeaker();//创建选手

	void startSpeech();//开始比赛

	void speechDraw();//抽签

	void speechContest();//比赛

	void showScore();//显示比赛成绩

	void saveRecord();//保存记录

	void loadRecord();//加载记录

	void showRecord();//显示记录

	void clearRecord();//清空记录
};

