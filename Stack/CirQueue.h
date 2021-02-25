/*
 * ˳��洢��ѭ������
 * @file:	CirQueue.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/25
 */
#pragma once
#ifndef SequenceQueue_h
#define SequenceQueue_h

#include <iostream>

using namespace std;

const int QUEUE_MAX_SIZE = 6;

template<class T>
class CirQueue
{
public:
	CirQueue();
	~CirQueue();
	void Clear();
	int Length();
	bool Empty();
	bool Full();
	T GetHead();
	void EnQueue(T element);
	T DeQueue();
	void Traverse();
private:
	T* queue;	//���ݿռ�
	int front;	//����ָ��
	int rear;	//��βָ��
};
#endif