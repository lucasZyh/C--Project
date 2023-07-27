#include "app.h"

app::app()
{
	ifstream ifs(FILENAME, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	//存在，是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	//存在，且不为空
	int num = this->getFilewWorkerNum();
	this->workerNum = num;

	//测试代码
	//cout << "职工人数为：" << num << endl;

	this->workerArray = new worker * [this->workerNum];//开辟空间
	this->initWorker();//将文件中的数据，存到数组中

	//测试代码
	//for (int i = 0; i < workerNum; i++)
	//{
	//	cout << "职工号： " << this->workerArray[i]->getId()
	//		<< " 职工姓名： " << this->workerArray[i]->getName()
	//		<< " 部门： " << this->workerArray[i]->getDeptName() << endl;
	//}

}

app::~app()
{

}

/*
* @brief 显示菜单
* @param 无
* @return 无
*/
void app::showMenu() {

	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/*
* @brief 退出系统
* @param 无
* @return 无
*/
void app::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

/*
* @brief 添加职工
* @param 无
* @return 无
*/
void app::addWorker() {

	int addNum = 0;//添加职工数量
	cout << "请输入要添加的职工数量：" << endl;
	cin >> addNum;

	//防止输入错误数据类型，导致死循环
	int flag = 0;
	while (cin.fail()) {
		if (flag == 0)
			cout << "请输入正确的数据类型" << endl;
		cin.clear();
		cin.ignore();
		cin >> addNum;
		flag++;
	}

	if (addNum > 0) {
		int newSize = this->workerNum + addNum;//计算新空间大小
		worker** newSpace = new worker * [newSize];//开辟新空间

		//将原空间下数据存放到新空间下
		if (this->workerArray != NULL) {
			for (int i = 0; i < this->workerNum; i++) {
				newSpace[i] = this->workerArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int deptId;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			//防止输入错误数据类型，导致死循环
			flag = 0;
			while (cin.fail()) {
				if (flag == 0)
					cout << "请输入正确的数据类型" << endl;
				cin.clear();
				cin.ignore();
				cin >> id;
				flag++;
			}

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			worker* worker = NULL;

			//死循环，防止输入错误信息
			while (true) {
				cin >> deptId;
				//防止输入错误数据类型，导致死循环
				int flag = 0;
				while (cin.fail()) {
					if (flag == 0)
						cout << "请输入正确的数据类型" << endl;
					cin.clear();
					cin.ignore();
					cin >> deptId;
					flag++;
				}

				switch (deptId)
				{
				case 1://员工
					worker = new employee(id, name, deptId);
					break;
				case 2://经理
					worker = new manager(id, name, deptId);
					break;
				case 3://老板
					worker = new boss(id, name, deptId);
					break;
				default:
					cout << "输入有误，请重新输入" << endl;
					continue;
				}
				break;
			}
			//将创建的职工指针存放到数组中
			//该方法会提示缓冲区溢出，不过不影响程序执行，可以换成下面的语句解决
			//newSpace[this->workerNum + i] = worker;
			*(newSpace + this->workerNum + i) = worker;
		}

		delete[] this->workerArray;//释放原有空间

		this->workerArray = newSpace;//更改新空间的指向

		this->workerNum = newSize;//更新新的职工人数

		this->isEmpty = false;//更新文件状态

		cout << "成功添加" << addNum << "名新职工！" << endl;//提示信息

		this->saveFile();//保存数据到文件中
	}
	else {
		cout << "输入数据有误！" << endl;
	}
	system("pause");
	system("cls");
}

/*
* @brief 保存文件
* @param 无
* @return 无
*/
void app::saveFile() {

	ofstream ofs(FILENAME, ios::out);//创建输出流对象

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->workerNum; i++) {
		ofs << this->workerArray[i]->getId() << " "
			<< this->workerArray[i]->getName() << " "
			<< this->workerArray[i]->getDeptId() << endl;
	}

	ofs.close();//关闭文件
}

/*
* @brief 获取文件中的职工人数
* @param 无
* @return 文件中的职工人数
*/
int app::getFilewWorkerNum() {

	ifstream ifs(FILENAME, ios::in);//创建输入流对象

	int id;
	string name;
	int deptId;
	int num = 0;

	//统计人数
	while (ifs >> id && ifs >> name && ifs >> deptId) {
		num++;
	}

	ifs.close();//关闭文件

	return num;
}

/*
* @brief 初始化职工
* @param 无
* @return 无
*/
void app::initWorker() {
	ifstream ifs(FILENAME, ios::in);//创建输入流对象

	int id;
	string name;
	int deptId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> deptId) {
		worker* worker = NULL;
		if (deptId == 1) {//普通员工
			worker = new employee(id, name, deptId);
		}
		else if (deptId == 2) {//经理
			worker = new manager(id, name, deptId);
		}
		else {//老板
			worker = new boss(id, name, deptId);
		}
		this->workerArray[index] = worker;
		index++;
	}
	ifs.close();
}

/*
* @brief 显示职工
* @param 无
* @return 无
*/
void app::showWorker() {

	if (this->isEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->workerNum; i++) {
			this->workerArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

/*
* @brief 删除职工
* @param 无
* @return 无
*/
void app::delWorker() {

	if (this->isEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的职工编号：" << endl;
		int id;
		cin >> id;

		//防止输入错误数据类型，导致死循环
		int flag = 0;
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> id;
			flag++;
		}

		//查找职工是否存在
		int index = this->checkWorkerExist(id);

		if (index != -1) {
			for (int i = index; i < this->workerNum - 1; i++) {
				//数据前移
				this->workerArray[i] = this->workerArray[i + 1];
			}
			this->workerNum--;//更新数组中记录人员个数

			this->saveFile();//更新文件中的人员信息

			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工！" << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* @brief 检测职工是否存在
* @param 职工编号
* @return 职工所在数组中的位置，不存在返回-1
*/
int app::checkWorkerExist(int id) {
	int index = -1;
	for (int i = 0; i < this->workerNum; i++) {
		if (this->workerArray[i]->getId() == id) {
			index = i;
			break;
		}
	}
	return index;
}

/*
* @brief 修改职工
* @param 无
* @return 无
*/
void app::changeWorker() {

	if (this->isEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要修改的职工编号：" << endl;
		int id;
		cin >> id;

		//防止输入错误数据类型，导致死循环
		int flag = 0;
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> id;
			flag++;
		}

		//查找职工是否存在
		int index = this->checkWorkerExist(id);
		if (index == -1) {
			cout << "修改失败，查无此人" << endl;
		}
		else {
			delete this->workerArray[index];//删除原有职工

			int newId = 0;
			string newName = "";
			int newDeptId = 0;

			cout << "查到：" << id << "号职工" << endl;
			cout << "请输入新的职工号：" << endl;
			cin >> newId;

			//防止输入错误数据类型，导致死循环
			flag = 0;
			while (cin.fail()) {
				if (flag == 0)
					cout << "请输入正确的数据类型" << endl;
				cin.clear();
				cin.ignore();
				cin >> newId;
				flag++;
			}

			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			cout << "请输入新的部门：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			worker* worker = NULL;

			//死循环，防止输入错误信息
			while (true) {
				cin >> newDeptId;

				//防止输入错误数据类型，导致死循环
				flag = 0;
				while (cin.fail()) {
					if (flag == 0)
						cout << "请输入正确的数据类型" << endl;
					cin.clear();
					cin.ignore();
					cin >> newDeptId;
					flag++;
				}

				switch (newDeptId)
				{
				case 1://员工
					worker = new employee(newId, newName, newDeptId);
					break;
				case 2://经理
					worker = new manager(newId, newName, newDeptId);
					break;
				case 3://老板
					worker = new boss(newId, newName, newDeptId);
					break;
				default:
					cout << "输入有误，请重新输入" << endl;
					continue;
				}
				break;
			}

			this->workerArray[index] = worker;//保存新的职工信息
			cout << "修改成功！" << endl;
			this->saveFile();//更新文件中的职工信息
		}
	}
	system("pause");
	system("cls");
}

/*
* @brief 查找职工
* @param 无
* @return 无
*/
void app::findWorker() {

	if (this->isEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;

		while (true) {
			cin >> select;

			//防止输入错误数据类型，导致死循环
			int flag = 0;
			while (cin.fail()) {
				if (flag == 0)
					cout << "请输入正确的数据类型" << endl;
				cin.clear();
				cin.ignore();
				cin >> select;
				flag++;
			}

			if (select == 1) {//按职工编号查找
				cout << "请输入要查找的职工编号：" << endl;
				int id;
				cin >> id;

				//防止输入错误数据类型，导致死循环
				flag = 0;
				while (cin.fail()) {
					if (flag == 0)
						cout << "请输入正确的数据类型" << endl;
					cin.clear();
					cin.ignore();
					cin >> id;
					flag++;
				}

				int index = this->checkWorkerExist(id);
				if (index != -1) {
					cout << "查找成功！该职工信息如下：" << endl;
					this->workerArray[index]->showInfo();
				}
				else {
					cout << "查无此人！" << endl;
				}
				break;
			}
			else if (select == 2) {//按姓名查找
				cout << "请输入要查找的姓名：" << endl;
				string name;
				cin >> name;

				bool flag = false;//标志是否查到

				for (int i = 0; i < this->workerNum; i++) {
					if (this->workerArray[i]->getName() == name) {
						cout << "查找成功！该职工信息如下：" << endl;
						this->workerArray[i]->showInfo();
						flag = true;
					}
				}
				if (flag == false) {
					cout << "查无此人！" << endl;
				}
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
				continue;
			}
		}

	}
	system("pause");
	system("cls");
}

/*
* @brief 排序职工
* @param 无
* @return 无
*/
void app::sortWorker() {
	if (this->isEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;

		while (true) {
			cin >> select;

			//防止输入错误数据类型，导致死循环
			int flag = 0;
			while (cin.fail()) {
				if (flag == 0)
					cout << "请输入正确的数据类型" << endl;
				cin.clear();
				cin.ignore();
				cin >> select;
				flag++;
			}

			//升序排序
			if (select == 1) {
				for (int i = 0; i < this->workerNum; i++) {
					int min = i;
					for (int j = i + 1; j < this->workerNum; j++) {//找到最小值
						if (this->workerArray[min]->getId() > this->workerArray[j]->getId()) {
							min = j;
						}
					}
					if (min != i) {//交换位置
						worker* temp = this->workerArray[min];
						this->workerArray[min] = this->workerArray[i];
						this->workerArray[i] = temp;
					}
				}

				cout << "排序成功！" << endl;
				this->saveFile();//更新文件中的职工信息
				this->showWorker();//显示排序后的职工信息

				break;
			}

			//降序排序
			else if (select == 2) {
				for (int i = 0; i < this->workerNum; i++) {
					int max = i;
					for (int j = i + 1; j < this->workerNum; j++) {//找到最大值
						if (this->workerArray[max]->getId() < this->workerArray[j]->getId()) {
							max = j;
						}
					}
					if (max != i) {//交换位置
						worker* temp = this->workerArray[max];
						this->workerArray[max] = this->workerArray[i];
						this->workerArray[i] = temp;
					}
				}

				cout << "排序成功！" << endl;
				this->saveFile();//更新文件中的职工信息
				this->showWorker();//显示排序后的职工信息

				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
				continue;
			}
		}
	}
	system("pause");
	system("cls");

}

/*
* @brief 清空文件
* @param 无
* @return 无
*/
void app::clearFile() {

	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;

	while (true) {
		cin >> select;

		//防止输入错误数据类型，导致死循环
		int flag = 0;
		while (cin.fail()) {
			if (flag == 0)
				cout << "请输入正确的数据类型" << endl;
			cin.clear();
			cin.ignore();
			cin >> select;
			flag++;
		}

		if (select == 1) {

			ofstream ofs(FILENAME, ios::trunc);//删除文件中的内容
			ofs.close();

			//删除堆区中的数据
			if (this->workerArray != NULL) {
				for (int i = 0; i < this->workerNum; i++) {
					if (this->workerArray[i] != NULL) {
						delete this->workerArray[i];
					}
				}
				this->workerNum = 0;
				delete[] this->workerArray;
				this->workerArray = NULL;
				this->isEmpty = true;
			}
			cout << "清空成功！" << endl;
			break;
		}
		else if (select == 2) {
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			continue;
		}
	}
	system("pause");
	system("cls");
}