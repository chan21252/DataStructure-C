#pragma once

/*
 * 双向链表的节点，指针域有前驱和后继
 * 
 * @file:	DulNode.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/20
 */
template <class T>
struct DulNode
{
	T data;
	DulNode<T>* prior;
	DulNode<T>* next;
};