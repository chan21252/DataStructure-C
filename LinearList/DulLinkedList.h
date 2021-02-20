#pragma once

/*
 * Ë«ÏòÑ­»·Á´±í
 * 
 * @file:	DulLinkedList.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/20
 */
#include <iostream>
#include "DulNode.h"

using namespace std;

template <class T>
class DulLinkedList
{
public:
	DulLinkedList();
	DulLinkedList(T arr[], int n);
	~DulLinkedList();
	int Length();
	bool IsEmpty();
	void Clear();
	T Get(int i);
	int locateElement(T element);
	void Insert(T element, int i);
	T Delete(int i);
	void Traverse();
private:
	DulNode<T>* head;
};

