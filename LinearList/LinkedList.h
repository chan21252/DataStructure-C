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

using namespace std;

//�ڵ�Ԫ��
template <class T>
struct Node
{
	T data;			//������
	Node<T>* next;	//ָ����
};

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T a[], int n);
	~LinkedList();
	bool ListEmpty();
	void Clear();
	int Length();
	T Get(int i);	//��ȡ���±�Ϊi��Ԫ��
	int Locate(T element);
	Node<T>* LocateElement(T element);
	void Insert(int index, T element);
	T Delete(int i);
	void printList();
private:
	Node<T>* head;	//�������ͷָ��
};