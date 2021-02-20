#include "DulLinkedList.h"

template<class T>
DulLinkedList<T>::DulLinkedList()
{
	head = new DulNode<T>();
	head->prior = head;
	head->next = head;
}

template<class T>
DulLinkedList<T>::DulLinkedList(T arr[], int n)
{
	head = new DulNode<T>();
	head->prior = head;
	head->next = head;

	//头插法生成链表
	for (int i = n-1; i >=0; i--)
	{
		DulNode<T>* s = new DulNode<T>;
		s->data = arr[i];

		DulNode<T>* p = head->next;

		head->next = s;
		s->prior = head;
		s->next = p;
		p->prior = s;
	}
}

template<class T>
DulLinkedList<T>::~DulLinkedList()
{

	for (DulNode<T>* p = head->next; p != head;)
	{
		DulNode<T>* q = p;
		p = p->next;
		delete q;
	}

	delete head;
	cout << "析构双向链表结束" << endl;
}

template<class T>
int DulLinkedList<T>::Length()
{
	int count = 0;
	for (DulNode<T>* p = head->next; p != head; p = p->next)
	{
		++count;
	}
	return count;
}

template<class T>
bool DulLinkedList<T>::IsEmpty()
{
	return head->prior == head;
}

template<class T>
void DulLinkedList<T>::Clear()
{
	for (DulNode<T>* p = head->next; p != head;)
	{
		DulNode<T>* q = p;
		p = p->next;
		delete q;
	}
	head->next = head;
	head->prior = head;
}

template<class T>
T DulLinkedList<T>::Get(int i)
{
	int count = 1;
	DulNode<T>* p;
	for (p = head->next; p != head && count < i; p = p->next)
	{
		++count;
	}

	if (p == head || count > i) throw "位置";
	else return p->data;
}

template<class T>
int DulLinkedList<T>::locateElement(T element)
{
	int count = 1;
	DulNode<T>* p;
	for (p = head->next; 
		p != head && p->data != element; p = p->next)
	{
		++count;
	}

	if (p == head) return -1;
	else return count;
}

template<class T>
void DulLinkedList<T>::Insert(T element, int i)
{
	int count = 1;
	DulNode<T>* p = head->next;
	
	// 找到第i个元素，在第i个元素前插入
	while (p != head && count < i)
	{
		p = p->next;
		count++;
		
	}

	if (count < i) throw "位置";
	else 
	{
		DulNode<T>* s = new DulNode<T>;
		s->data = element;

		s->prior = p->prior;	//p-1 <- s
		s->next = p;			//s -> p
		p->prior->next = s;		//p-1 -> s
		p->prior = s;			//s <- p
	}
}

template<class T>
T DulLinkedList<T>::Delete(int i)
{
	int count = 0;
	DulNode<T>* p = head;

	for (p = head; p != head->prior && count < i - 1; p = p->next)
	{
		count++;

	}

	if (p == head->prior || count > i - 1) throw "位置"; 
	
	DulNode<T>* q = p->next;	//要删除的节点
	T data = q->data;

	p->next = q->next;
	q->next->prior = p;
	delete q;

	return data;
}


template<class T>
void DulLinkedList<T>::Traverse()
{
	for (DulNode<T>* p = head->next; p != head; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

