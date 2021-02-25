#pragma once

/*
 * ˫��ѭ������
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
	void Connect(DulLinkedList<T>* list);		//˫�������ĺϲ�
	static DulLinkedList<T>* sortedMerge(DulLinkedList<T>* listA, 
		DulLinkedList<T>* listB);	//����ϲ�
	void sortedMerge(DulLinkedList<T>* list);	//����ϲ�����ռ���µĿռ�
	bool isSorted();
private:
	DulNode<T>* head;
};
