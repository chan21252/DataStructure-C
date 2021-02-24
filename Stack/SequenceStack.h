/*
 * Ë³ÐòÕ»
 *
 * @file:	SequenceStack.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/24
 */
#pragma once
#ifndef SequenceStack_h
#define SequenceStack_h

#include<iostream>

using namespace std;

const int MAX_SIZE = 100;

template<class T>
class SequenceStack
{
public:
    SequenceStack();

    bool Empty();
    int Length();
    void Clear();
    static void Destroy(SequenceStack<T> &stack);
    void Push(T element);
    T Pop();
    void Traverse();
private:
    T* base;		//Õ»µ×
    T* top;			//Õ»¶¥
    int capacity;	//Ë³ÐòÕ»µÄÈÝÁ¿
};
#endif