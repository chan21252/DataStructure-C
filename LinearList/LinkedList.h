/*
 * 单链表
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
		bool isHeadInsert=true);	//默认头插法生成链表，false为尾插法
	~LinkedList();
	bool ListEmpty();
	void Clear();
	int Length();
	T Get(int i);			//获取第i个节点元素
	int Locate(T element);	//返回元素T为第几个节点
	Node<T>* LocateElement(T element);	//返回元素T的指针
	void Insert(int i, T element);		//在第i个元素前插入节点
	T Delete(int i);		//删除第i个节点
	void printList();
private:
	Node<T>* head;	//单链表的头指针

	void HeadInsert(T a[], int n);
	void TailInsert(T a[], int n);
};