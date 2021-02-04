
#include "LinkedList.h"

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
void LinkedList<T>::Insert(int i, T element)
{

}

template <class T>
int LinkedList<T>::Locate(T element)
{

}

template <class T>
T LinkedList<T>::Get(int i)
{
	int count = 1;
	Node<T>* p = head->next;

	while (p != NULL && count < i)
	{
		p->next;
		count++;
	}

	if (p == NULL) throw "Ë÷ÒýÔ½½ç";
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

template <class T>
LinkedList<T>::~LinkedList()
{

}

template <class T>
LinkedList<T>::LinkedList(T a[], int n)
{

}

template <class T>
LinkedList<T>::LinkedList()
{

}