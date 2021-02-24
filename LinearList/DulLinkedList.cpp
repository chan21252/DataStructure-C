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

template<class T>
void DulLinkedList<T>::Connect(DulLinkedList<T>* list)
{
	DulNode<T>* rear1 = this->head->prior;	//表1的尾节点
	DulNode<T>* rear2 = list->head->prior;	//表2的尾节点

	DulNode<T>* firstNode2 = list->head->next;	//表2的首元节点
	rear1->next = firstNode2;			//表1尾节点的后继指向表2的首元节点
	firstNode2->prior = rear1;			//表2首元节点的前驱指向表1的尾节点

	rear2->next = this->head;			//表2尾节点的后继指向表1的头节点
	this->head->prior = rear2;			//表1头节点的前驱指向表2的尾节点

	delete list->head;
}

template<class T>
DulLinkedList<T>* DulLinkedList<T>::sortedMerge(DulLinkedList<T>* listA, DulLinkedList<T>* listB)
{
	if (!(listA->isSorted() && listB->isSorted()))
	{
		throw "无序";
	}

	DulNode<T>* p1 = listA->head->next;
	DulNode<T>* p2 = listB->head->next;
	DulLinkedList<T>* listC = new DulLinkedList<T>;
	int i = 1;
	while (p1 != listA->head && p2 != listB->head)
	{
		if (p1->data <= p2->data)
		{
			listC->Insert(p1->data, i);
			p1 = p1->next;
		}
		else 
		{
			listC->Insert(p2->data, i);
			p2 = p2->next;
		}
		i++;
	}

	if (p1 == listA->head)
	{
		while (p2 != listB->head)
		{
			listC->Insert(p2->data, i++);
			p2 = p2->next;
		}
	}

	if (p2 == listB->head)
	{
		while (p1 != listA->head)
		{
			listC->Insert(p1->data, i++);
			p1 = p1->next;
		}
	}
	return listC;
}

template<class T>
void DulLinkedList<T>::sortedMerge(DulLinkedList<T>* list)
{
	if (!(this->isSorted() && list->isSorted()))
	{
		throw "无序";
	}

	DulNode<T>* pa = head->next;
	DulNode<T>* pb = list->head->next;
	DulNode<T>* pc = head;

	while (pa != head && pb != head) {
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pa->prior = pc;
			pc = pa;
			pa = pa->next;
		}
		else 
		{
			pc->next = pb;
			pb->prior = pc;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa != head ? pa : pb;
	if (pa != head)
	{
		pa->prior = pc;
	}
	if (pb != head) 
	{
		pb->prior = pc;
		// pc的头节点在a上，表b的表尾和表a的头节点连接
		list->head->prior->next = head;
		head->prior = list->head->prior;
	}
}

template<class T>
bool DulLinkedList<T>::isSorted()
{	
	DulNode<T>* p = head->next;

	while (p != head->prior)
	{
		if (p->data > p->next->data)
		{
			return false;
		}
		p = p->next;
	}
	return true;
}

