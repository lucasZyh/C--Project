#pragma once
#include <iostream>
using namespace std;

template <class T>
class myArray {
private:
	T* pArray;//指向一个堆空间，这个空间存储真正的数据
	int capacity;//容量
	int size;//大小
public:

	//构造函数
	myArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->pArray = new T[this->capacity];
	}

	//拷贝构造,深拷贝,防止浅拷贝
	myArray(const myArray& arr) {
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pArray = new T[this->capacity];
		for (int i = 0; i < this->size; i++) {
			this->pArray[i] = arr.pArray[i];
		}
	}

	//析构函数
	~myArray() {
		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = NULL;
			this->pArray = 0;
			this->size = 0;
		}
	}

	//获取容量
	int getCapacity() {
		return this->capacity;
	}

	//获取大小
	int getSize() {
		return this->size;
	}

	//重载=
	myArray& operator=(const myArray& arr) {

		if (this->pArray != NULL) {
			delete[] this->pArray;
			this->pArray = 0;
			this->size = 0;
		}

		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pArray = new T[this->capacity];
		for (int i = 0; i < this->size; i++) {
			//this->pArray[i] = arr.pArray[i];
			this->*(this->pArray + i) = *(arr.pArray + i);
		}

		return *this;
	}

	//重载[],可以通过下标访问数组元素
	T& operator[](int index) {
		return this->pArray[index];
	}

	//尾插法
	void pushBack(T value) {
		if (this->size >= this->capacity) {
			cout << "数组已满" << endl;
			return;
		}
		this->pArray[this->size] = value;
		this->size++;
	}

	//尾删法
	void popBack() {
		if (this->size <= 0) {
			cout << "数组为空" << endl;
			return;
		}
		this->size--;
	}
};