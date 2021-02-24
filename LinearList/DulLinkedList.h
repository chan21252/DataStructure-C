#pragma once

/*
 * 双向循环链表
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
	void Connect(DulLinkedList<T>* list);		//双向链表的合并
	static DulLinkedList<T>* sortedMerge(DulLinkedList<T>* listA, 
		DulLinkedList<T>* listB);	//有序合并
	bool isSorted();
private:
	DulNode<T>* head;
};

