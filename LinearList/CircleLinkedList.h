/*
 * 循环链表，带尾指针
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
	CircleLinkedList(T a[], int n);	//尾插法生成链表
	~CircleLinkedList();
	bool ListEmpty();
	void Clear();
	int Length();
	T Get(int i);			//获取第i个节点元素
	int Locate(T element);	//返回元素T为第几个节点
	Node<T>* LocateElement(T element);	//返回元素T的指针
	void Insert(int i, T element);		//在第i个元素前插入节点
	T Delete(int i);		//删除第i个节点
	void printList();
	CircleLinkedList<T> Connect(CircleLinkedList<T>* list);	//合并2个循环表
private:
	Node<T>* rear;			//尾指针，指向最后一个节点
};