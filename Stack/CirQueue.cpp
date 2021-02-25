#include "CirQueue.h"

template<class T>
inline CirQueue<T>::CirQueue()
{
	queue = new T[QUEUE_MAX_SIZE];
	front = rear = 0;
}

template<class T>
CirQueue<T>::~CirQueue()
{
}

template<class T>
void CirQueue<T>::Clear()
{
	rear = front = 0;
}

template<class T>
int CirQueue<T>::Length()
{
	return (rear - front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

template<class T>
bool CirQueue<T>::Empty()
{
	return front == rear;
}

template<class T>
bool CirQueue<T>::Full()
{
	return (rear + 1) % QUEUE_MAX_SIZE == front;
}

template<class T>
T CirQueue<T>::GetHead()
{
	if (front != rear)
	{
		return data[front];
	}

	return NULL;
}

template<class T>
void CirQueue<T>::EnQueue(T element)
{
	if ((rear + 1) % QUEUE_MAX_SIZE == front)
	{
		throw "…œ“Á";
	}
	queue[rear] = element;
	rear = (rear + 1) % QUEUE_MAX_SIZE;
}

template<class T>
T CirQueue<T>::DeQueue()
{
	if (front == rear)
	{
		throw "œ¬“Á";
	}
	T x = queue[front];
	front = (front + 1) % QUEUE_MAX_SIZE;
	return x;
}

template<class T>
void CirQueue<T>::Traverse()
{
	for (int i = front; i != rear; i = (++i) % QUEUE_MAX_SIZE)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}