/*
 * ѭ��������βָ��
 * 
 * @file:	CircleLinkedList.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/18
 */

#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class CircleLinkedList
{
public:
	CircleLinkedList();
	CircleLinkedList(T a[], int n);	//β�巨��������
	~CircleLinkedList();
	bool ListEmpty();
	void Clear();
	int Length();
	T Get(int i);			//��ȡ��i���ڵ�Ԫ��
	int Locate(T element);	//����Ԫ��TΪ�ڼ����ڵ�
	Node<T>* LocateElement(T element);	//����Ԫ��T��ָ��
	void Insert(int i, T element);		//�ڵ�i��Ԫ��ǰ����ڵ�
	T Delete(int i);		//ɾ����i���ڵ�
	void printList();
	CircleLinkedList<T> Connect(CircleLinkedList<T>* list);	//�ϲ�2��ѭ����
private:
	Node<T>* rear;			//βָ�룬ָ�����һ���ڵ�
};