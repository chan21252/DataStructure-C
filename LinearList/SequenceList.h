/*
 * ˳���
 * 
 * @file:	SequenceList.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/03
 */
#pragma once
#ifndef SequenceList_h
#define SequenceList_h

#include <iostream>

using namespace std;

//��󳤶�
const int MAX_SIZE = 100;

//���Ͳ���
template <class T>

class SequenceList {
public:
	SequenceList();
	SequenceList(const T a[], int n);

	~SequenceList();

	int length();
	void destroy();
	void clear();
	bool isEmpty();
	T get(int index);
	void set(int index, T element);
	int indexOf(T element);
	void insert(int index, T element);
	void remove(int index);
	void trasverse();

private:
	int size;	//˳���Ԫ�ظ���
	T *data;	//ָ�룬ָ��Ԫ������
};

#endif // !SequenceList_h