#include "SequenceList.h"

template <class T>
SequenceList<T>::SequenceList()
{
	this->data = new T[MAX_SIZE];
	if (!data)
	{
		throw "初始化顺序表异常";
	}
	this->size = 0;
}

template <class T>
SequenceList<T>::SequenceList(const T a[], int n)
{
	if (n > MAX_SIZE)
	{
		throw "数组长度超过最大长度";
	}

	data = new T[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	this->size = n;
}

template<class T>
SequenceList<T>::~SequenceList()
{
}

template<class T>
int SequenceList<T>::length()
{
	return this->size;
}


template<class T>
void SequenceList<T>::destroy()
{
	this->~SequenceList();
	delete this;
}

template<class T>
void SequenceList<T>::clear()
{
	this->size = 0;
}

template<class T>
bool SequenceList<T>::isEmpty()
{
	return size == 0;
}

template<class T>
T SequenceList<T>::get(int i)
{
	if (i < 0 || i > size - 1)
	{
		throw "下标越界";
	}
	return data[i];
}

template<class T>
int SequenceList<T>::indexOf(T element)
{
	for (int i=0; i< size; i++)
	{
		if (data[i] == element)
		{
			return i;
		}
	}

	return -1;
}

template<class T>
void SequenceList<T>::insert(int index, T element)
{
	if (index < 0 || index > size - 1)
	{
		throw "插入位置越界";
	}

	if (size == MAX_SIZE)
	{
		throw "顺序表已满";
	}

	//插入位置和之后的元素后移一位
	for (int i = size - 1; i >= index; i--)
	{
		data[i + 1] = data[i];
	}

	data[index] = element;
	size++;
}

template<class T>
void SequenceList<T>::remove(int index)
{
	if (index < 0 || index > size - 1)
	{
		throw "删除位置越界";
	}

	if (isEmpty())
	{
		throw "顺序表为空";
	}

	for (int i = index + 1; i < size; i++)
	{
		data[i - 1] = data[i];
	}
	size--;
}

template<class T>
void SequenceList<T>::trasverse()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
