/*
 * ������
 * 
 * @file:	LinkedList.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/04
 */
#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T a[], int n, 
		bool isHeadInsert=true);	//Ĭ��ͷ�巨��������falseΪβ�巨
	~LinkedList();
	bool ListEmpty();
	void Clear();
	int Length();
	T Get(int i);			//��ȡ��i���ڵ�Ԫ��
	int Locate(T element);	//����Ԫ��TΪ�ڼ����ڵ�
	Node<T>* LocateElement(T element);	//����Ԫ��T��ָ��
	void Insert(int i, T element);		//�ڵ�i��Ԫ��ǰ����ڵ�
	T Delete(int i);		//ɾ����i���ڵ�
	void printList();
private:
	Node<T>* head;	//�������ͷָ��

	void HeadInsert(T a[], int n);
	void TailInsert(T a[], int n);
};