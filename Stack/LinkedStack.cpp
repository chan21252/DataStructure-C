#include "LinkedStack.h"

template<class T>
inline LinkedStack<T>::LinkedStack()
{
	top = NULL;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
	while (top != NULL)
	{
		Node<T>* q = top;
		top = top->next;
		delete q;
	}
	delete top;
}

template<class T>
bool LinkedStack<T>::Empty()
{
	return top == NULL;
}

template<class T>
int LinkedStack<T>::Length()
{
	int count = 0;
	for (Node<T>* p = top; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}

template<class T>
void LinkedStack<T>::Clear()
{
	while (top != NULL)
	{
		Node<T>* q = top;
		top = top->next;
		delete q;
	}
}

template<class T>
void LinkedStack<T>::Destroy(LinkedStack<T>& stack)
{
	while (stack.top != NULL)
	{
		Node<T>* q = stack.top;
		stack.top = stack.top->next;
		delete q;
	}
	delete stack.top;
}

template<class T>
void LinkedStack<T>::Push(T element)
{
	Node<T>* s = new Node<T>();
	s->data = element;
	s->next = top;
	top = s;
}

template<class T>
T LinkedStack<T>::Pop()
{
	if (top == NULL)
	{
		throw "Õ»¿Õ";
	}
	T data = top->data;
	Node<T>* p = top;
	top = top->next;
	delete p;

	return data;
}

template<class T>
T LinkedStack<T>::GetTop()
{
	if (top != NULL)
	{
		return top->data;
	}
}

template<class T>
void LinkedStack<T>::Traverse()
{
	for (Node<T>* p = top; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}