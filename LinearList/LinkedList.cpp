#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>;		//����ͷ�ڵ㣬ͷָ��ָ��ͷ�ڵ�
	head->next = NULL;		//ͷ�ڵ��nextΪNULL
}

template <class T>
LinkedList<T>::LinkedList(T a[], int n, bool isHeadInsert)
{
	new (this)LinkedList<T>();	//���ɿ�����

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
	* �ҵ���i-1��Ԫ�أ�
	* �����i��Ԫ��(i-1��Ԫ�صĺ��)
	* i-1��Ԫ��ָ��i+1��Ԫ��
	* ɾ����i��Ԫ��
	*/
	Node<T>* p = head;
	int count = 0;
	while (p != NULL && count < i -1)
	{
		p = p->next;
		count++;
	}

	//p->next == NULL����i-1���ڵ������һ��Ԫ�ص����
	if (p == NULL || p->next == NULL ||count > i)
	{
		throw "λ��Խ��";
	}
	Node<T>* q = p->next;
	p->next = p->next->next;

	T t = q->data;	//��ʱ�洢Ҫɾ����Ԫ������
	delete q;

	return t;
}

template <class T>
void LinkedList<T>::Insert(int i, T element)
{
	/*
	* �ҵ���i-1��Ԫ�أ�
	* �½ڵ�ĺ��ָ���i���ڵ�
	* i-1��Ԫ�صĺ��ָ���½ڵ�
	*/
	Node<T>* p = head;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}

	if (p == NULL || count > i) throw "λ��Խ��";
	
	Node<T>* s = new Node<T>();
	s->data = element;

	s->next = p->next;
	p->next = s;
}

template <class T>
int LinkedList<T>::Locate(T element)
{
	/*
	* ����Ԫ�ڵ㿪ʼ��������
	* ��ǰ�ڵ�Ԫ���Ƿ����Ҫ���ҵ�Ԫ��
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
	* ����Ԫ�ڵ㿪ʼ��������
	* ��ǰԪ���ǲ��ǵ�i��Ԫ��
	*/
	Node<T>* p = head->next;
	int count = 1;

	//�Ƿ��Ѿ��ҵ���󣬲��Ҳ��ǵ�i��Ԫ��
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}

	if (p == NULL || count > i) throw "λ��";
	else return p->data;
}

template <class T>
int LinkedList<T>::Length()
{
	//�ӵ�һ���ڵ㿪ʼ��������Ϊ��+1
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
	tail->next = NULL;	//������ϣ�βָ��ָ���
}