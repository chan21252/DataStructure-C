#pragma once

/*
 * ˫������Ľڵ㣬ָ������ǰ���ͺ��
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