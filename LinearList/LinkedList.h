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

using namespace std;

//节点元素
template <class T>
struct Node
{
	T data;			//数据域
	Node<T>* next;	//指针域
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
	T Get(int i);	//获取的下标为i的元素
	int Locate(T element);
	Node<T>* LocateElement(T element);
	void Insert(int index, T element);
	T Delete(int i);
	void printList();
private:
	Node<T>* head;	//单链表的头指针
};