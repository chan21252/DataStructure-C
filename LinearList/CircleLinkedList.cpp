#include "CircleLinkedList.h"

template <class T>
void CircleLinkedList<T>::printList()
{
	for (Node<T>* p = rear->next->next; p != rear->next; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

template <class T>
T CircleLinkedList<T>::Delete(int i)
{
	
}

template <class T>
void CircleLinkedList<T>::Insert(int i, T element)
{

}

template <class T>
Node<T>* CircleLinkedList<T>::LocateElement(T element)
{
	return nullptr;
}

template <class T>
int CircleLinkedList<T>::Locate(T element)
{
	return 0;
}

template <class T>
CircleLinkedList<T>::CircleLinkedList()
{
	rear = new Node<T>();	//尾指针指向头节点
	rear->next = rear;		//头节点的指针域指向自己
}

template <class T>
CircleLinkedList<T>::CircleLinkedList(T a[], int n)
{
	rear = new Node<T>();	//尾指针指向头节点
	rear->next = rear;		//头节点的指针域指向自己

	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>();		//生成新的节点
		s->data = a[i];
		s->next = rear->next;	//新的节点指向头节点
		rear->next = s;			//尾指针指向新节点
		rear = s;				//移动尾指针
	}
}

template <class T>
CircleLinkedList<T>::~CircleLinkedList()
{
	//从头节点开始，直到尾节点的前一个节点，依次删除
	for (Node<T>* p = rear->next; p != rear;)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	delete rear;
	cout << "析构循环表结束" << endl;
}

template <class T>
bool CircleLinkedList<T>::ListEmpty()
{
	return rear == rear->next;

}

template <class T>
void CircleLinkedList<T>::Clear()
{
	//从头节点开始
	for (Node<T>* p = rear->next->next; p != rear->next;)
	{
		Node<T>* q = p;		//临时存储删除节点
		rear->next->next = p->next;		//头节点指向下个节点

		//删除最后一个元素时，移动尾指针指向头节点
		if (p == rear)
		{
			rear = p->next;
		}
		p = p->next;		//p指向下个节点
		
		delete q;
	}
}

template <class T>
int CircleLinkedList<T>::Length()
{
	int count = 0;
	for (Node<T>* p = rear->next->next; p != rear->next; p = p->next)
	{
		++count;
	}

	return count;
}

template <class T>
T CircleLinkedList<T>::Get(int i)
{
	int count = 0;

	//从首元节点开始
	//没有遍历完，并且还没有数到要找的元素，向后
	Node<T>* p;
	for (p = rear->next->next; p != rear->next && count < i; p = p->next)
	{
		++count;
	}

	//数完了，没找到
	if (count != i) throw "位置";
	else return p->data;
}