#pragma once

/*
 * 节点元素
 * 
 * @file:	Node.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/18
 */
template <class T>
struct Node
{
	T data;			//数据域
	Node<T>* next;	//指针域
};