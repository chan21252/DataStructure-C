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
	int count = 0;

	//����Ԫ�ڵ㿪ʼ
	//û�б����꣬���һ�û������Ҫ�ҵ�Ԫ�أ����
	Node<T>* p;
	for (p = rear->next->next; p != rear->next && count < i; p = p->next)
	{
		++count;
	}

	//�����ˣ�û�ҵ�
	if (count != i) throw "λ��";
	else return p->data;
}