#pragma once

/*
 * �ڵ�Ԫ��
 * 
 * @file:	Node.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/18
 */
template <class T>
struct Node
{
	T data;			//������
	Node<T>* next;	//ָ����
};