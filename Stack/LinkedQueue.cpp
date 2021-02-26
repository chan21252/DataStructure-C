#include "LinkedQueue.h"


template<class T>
LinkedQueue<T>::LinkedQueue()
{
	front = rear = (Node<T>*)malloc(sizeof(Node<T>));
	if (!front) exit(OVERFLOW);
	front->next = NULL;
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	
	while (front != NULL)
	{
		Node<T>* p = front;
		front = front->next;
		free(p);
	}
}

template<class T>
void LinkedQueue<T>::Clear()
{
	while (front != rear)
	{
		Node<T>* p = front->next;
		free(front);
		front = p;
	}
}

template<class T>
int LinkedQueue<T>::Length()
{
	int count = 0;
	for (Node<T>* p = front->next; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}

template<class T>
bool LinkedQueue<T>::Empty()
{
	return front == rear;
}

template<class T>
T LinkedQueue<T>::GetHead()
{
	if (rear == front)
	{
		throw "©у╤сап";
	}
	return front->next->data;
}

template<class T>
void LinkedQueue<T>::EnQueue(T element)
{
	Node<T>* s = new Node<T>;
	s->data = element;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
T LinkedQueue<T>::DeQueue()
{
	if (front == rear)
	{
		throw "обрГ";
	}
	Node<T>* p = front->next;
	T x = p->data;
	front->next = p->next;
	delete p;
	return x;
}

template<class T>
void LinkedQueue<T>::Traverse()
{
	for (Node<T>* p = front->next; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

