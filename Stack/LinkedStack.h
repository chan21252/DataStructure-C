/*
 * Á´Ê½´æ´¢µÄÕ»
 * @file:	LinkedStack.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/25
 */
#pragma once
#ifndef LinkedStack_h
#define LinkedStack_h

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class LinkedStack
{
public:
	LinkedStack();
	~LinkedStack();
	bool Empty();
	int Length();
	void Clear();
	static void Destroy(LinkedStack<T>& stack);
	void Push(T element);
	T Pop();
	T GetTop();
	void Traverse();
private:
	Node<T>* top;
};
#endif