#include "CircleLinkedList.h"

template <class T>
CircleLinkedList<T>::CircleLinkedList()
{
	rear = new Node<T>();	//βָ��ָ��ͷ�ڵ�
	rear->next = rear;		//ͷ�ڵ��ָ����ָ���Լ�
}

template <class T>
CircleLinkedList<T>::CircleLinkedList(T a[], int n)
{
	rear = new Node<T>();	//βָ��ָ��ͷ�ڵ�
	rear->next = rear;		//ͷ�ڵ��ָ����ָ���Լ�

	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>();		//�����µĽڵ�
		s->data = a[i];
		s->next = rear->next;	//�µĽڵ�ָ��ͷ�ڵ�
		rear->next = s;			//βָ��ָ���½ڵ�
		rear = s;				//�ƶ�βָ��
	}
}

template <class T>
CircleLinkedList<T>::~CircleLinkedList()
{
	//��ͷ�ڵ㿪ʼ��ֱ��β�ڵ��ǰһ���ڵ㣬����ɾ��
	for (Node<T>* p = rear->next; p != rear;)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
	delete rear;
	cout << "����ѭ�������" << endl;
}

template <class T>
bool CircleLinkedList<T>::ListEmpty()
{
	return rear == rear->next;

}

template <class T>
void CircleLinkedList<T>::Clear()
{
	//��ͷ�ڵ㿪ʼ
	for (Node<T>* p = rear->next->next; p != rear->next;)
	{
		Node<T>* q = p;		//��ʱ�洢ɾ���ڵ�
		rear->next->next = p->next;		//ͷ�ڵ�ָ���¸��ڵ�

		//ɾ�����һ��Ԫ��ʱ���ƶ�βָ��ָ��ͷ�ڵ�
		if (p == rear)
		{
			rear = p->next;
		}
		p = p->next;		//pָ���¸��ڵ�
		
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
	//����Ԫ�ڵ㿪ʼ
	//û�б����꣬���һ�û������Ҫ�ҵ�Ԫ�أ����
	int count = 1;
	Node<T>* p;
	for (p = rear->next->next; p != rear->next && count < i; p = p->next)
	{
		++count;
	}

	//�����ˣ�û�ҵ�����i<1
	if (p == rear->next || count > i) throw "λ��";
	else return p->data;
}


template <class T>
Node<T>* CircleLinkedList<T>::LocateElement(T element)
{
	for (Node<T>* p = rear->next->next; p != rear->next; p = p->next)
	{
		if (p->data == element)
		{
			return p;
		}
	}
	return NULL;
}


template <class T>
int CircleLinkedList<T>::Locate(T element)
{
	int count = 0;
	for (Node<T>* p = rear->next->next; p != rear->next; p = p->next)
	{
		count++;
		if (p->data == element)
		{
			return count;
		}
	}
	return -1;
}

template <class T>
void CircleLinkedList<T>::Insert(int i, T element)
{
	int count = 0;
	Node<T>* p = rear->next;

	//��ͷ�ڵ㿪ʼ���ҵ���i-1��Ԫ��
	while (p != rear && count < i - 1)
	{
		p = p->next;
		count++;
	}
	
	/*
	for (p = rear->next; p != rear && count < i - 1;)
	{
		p = p->next
		count++;
	}*/

	//i<1 || i��������+1
	if (count != i - 1)
	{
		throw "λ��";
	}
	Node<T>* s = new Node<T>();
	s->data = element;
	s->next = p->next;
	p->next = s;

	if (p == rear) rear = p->next;	//������ڱ�β��ӣ���Ҫ�ƶ�βָ��
}

template <class T>
T CircleLinkedList<T>::Delete(int i)
{
	int count = 0;
	Node<T>* p = rear->next;

	while (p != rear && count < i - 1)
	{
		p = p->next;
		count++;
	}

	//i<1 || i��������+1
	if (count != i - 1)
	{
		throw "λ��";
	}

	Node<T>* q = p->next;
	T data = q->data;
	p->next = q->next;
	delete q;
	return data;
}

template <class T>
void CircleLinkedList<T>::printList()
{
	for (Node<T>* p = rear->next->next; p != rear->next; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

template<class T>
CircleLinkedList<T> CircleLinkedList<T>::Connect(CircleLinkedList<T>* list)
{
	Node<T>* head1 = this->rear->next;
	Node<T>* head2 = list->rear->next;
	this->rear->next = head2->next;		//L1��β����L2����Ԫ�ڵ�����
	delete head2;				//ɾ��L2��ͷ�ڵ�
	list->rear->next = head1;	//L2��β����L1��ͷ�ڵ�����
	rear = list->rear;

	return CircleLinkedList<T>();
}