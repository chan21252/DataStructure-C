
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>;		//生成头节点，头指针指向头节点
	head->next = NULL;		//头节点的next为NULL
}

template <class T>
LinkedList<T>::LinkedList(T a[], int n)
{

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
	if (head->next == NULL)
	{
		return;
	}

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

}

template <class T>
void LinkedList<T>::Insert(int index, T element)
{
	Node<T>* p = head;
	int pos = 0;
	while (p != NULL && pos < index - 1)
	{
		p = p->next;
		pos++;
	}

	if ( p == NULL || pos > index)
	{
		cout << "下标越界" << endl;
		return;
	}

	Node<T>* s = new Node<T>();	//新节点
	s->data = element;
	s->next = p->next;
	p->next = s;
}

template <class T>
int LinkedList<T>::Locate(T element)
{
	Node<T>* p = head->next;
	int index = 0;
	while (p != NULL && p->data != element)
	{
		p->next;
		index ++;
	}

	if (p == NULL) return -1;
	else return index;
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
	Node<T>* p = head->next;
	int index = 0;

	while (p != NULL && index < i )
	{
		p = p->next;
		index++;
	}

	//p==NULL说明i太大了
	//index>i说明i<0
	if (p == NULL || index > i) throw "下标越界";
	else return p->data;
}

template <class T>
int LinkedList<T>::Length()
{
	int count = 0;
	Node<T>* p = head->next;

	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}