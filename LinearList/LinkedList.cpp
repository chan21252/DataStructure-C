#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>;		//生成头节点，头指针指向头节点
	head->next = NULL;		//头节点的next为NULL
}

template <class T>
LinkedList<T>::LinkedList(T a[], int n, bool isHeadInsert)
{
	new (this)LinkedList<T>();	//生成空链表

	if (isHeadInsert)
	{
		HeadInsert(a, n);
	}
	else {
		TailInsert(a, n);
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while (head != NULL)
	{
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
}

template<class T>
bool LinkedList<T>::ListEmpty()
{
	return head->next == NULL;
	
}

template<class T>
void LinkedList<T>::Clear()
{
	Node<T>* p = head->next;
	Node<T>* q;

	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
}

template <class T>
void LinkedList<T>::printList()
{
	Node<T>* p = head->next;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
T LinkedList<T>::Delete(int i)
{
	/*
	* 找到第i-1个元素，
	* 保存第i个元素(i-1个元素的后继)
	* i-1个元素指向i+1个元素
	* 删除第i个元素
	*/
	Node<T>* p = head;
	int count = 0;
	while (p != NULL && count < i -1)
	{
		p = p->next;
		count++;
	}

	//p->next == NULL避免i-1个节点是最后一个元素的情况
	if (p == NULL || p->next == NULL ||count > i)
	{
		throw "位置越界";
	}
	Node<T>* q = p->next;
	p->next = p->next->next;

	T t = q->data;	//临时存储要删除的元素数据
	delete q;

	return t;
}

template <class T>
void LinkedList<T>::Insert(int i, T element)
{
	/*
	* 找到第i-1个元素，
	* 新节点的后继指向第i个节点
	* i-1个元素的后继指向新节点
	*/
	Node<T>* p = head;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}

	if (p == NULL || count > i) throw "位置越界";
	
	Node<T>* s = new Node<T>();
	s->data = element;

	s->next = p->next;
	p->next = s;
}

template <class T>
int LinkedList<T>::Locate(T element)
{
	/*
	* 从首元节点开始，向后查找
	* 当前节点元素是否等于要查找的元素
	*/
	Node<T>* p = head->next;
	int count = 1;

	while (p != NULL && p->data != element)
	{
		p = p->next;
		count++;
	}

	if (p == NULL) return -1;
	else return count;
}

template<class T>
Node<T>* LinkedList<T>::LocateElement(T element)
{
	Node<T>* p = head->next;
	while (p != NULL && p->data != element)
	{
		p = p->next;
	}

	if (p == NULL) return nullptr;
	else return p;
}

template <class T>
T LinkedList<T>::Get(int i)
{
	/*
	* 从首元节点开始，向后查找
	* 当前元素是不是第i个元素
	*/
	Node<T>* p = head->next;
	int count = 1;

	//是否已经找到最后，并且不是第i个元素
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}

	if (p == NULL || count > i) throw "位置";
	else return p->data;
}

template <class T>
int LinkedList<T>::Length()
{
	//从第一个节点开始计数，不为空+1
	Node<T>* p = head->next;
	int count = 0;

	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}


template<class T>
void LinkedList<T>::HeadInsert(T a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>* s = new Node<T>();
		s->data = a[i];

		s->next = head->next;
		head->next = s;
	}
}

template<class T>
void LinkedList<T>::TailInsert(T a[], int n)
{
	Node<T>* tail = head;
	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>();
		s->data = a[i];

		tail->next = s;
		tail = s;
	}
	tail->next = NULL;	//建议完毕，尾指针指向空
}