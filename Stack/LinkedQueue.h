/*
 * а╢й╫╤сап
 * @file:	LinkedQueue.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/26
 */
#pragma once
#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();
	void Clear();
	int Length();
	bool Empty();
	T GetHead();
	void EnQueue(T element);
	T DeQueue();
	void Traverse();
private:
	Node<T>* front;
	Node<T>* rear;
};
#endif