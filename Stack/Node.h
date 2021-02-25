/*
 *
 * @file:	Node.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/25
 */

#pragma once
#ifndef Node_h
#define Node_h

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};
#endif