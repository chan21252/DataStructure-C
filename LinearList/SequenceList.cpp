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
T SequenceList<T>::get(int index)
{
	if (index < 0 || index > size - 1)
	{
		throw "下标越界";
	}
	return data[index];
}

template<class T>
void SequenceList<T>::set(int index, T element)
{
	if (index < 0 || index > size - 1)
	{
		throw "下标越界";
	}
	data[index] = element;
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
	if (index < 0 || index > size)
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

template<class T>
void SequenceList<T>::connect(SequenceList* L)
{
	int lengthB = L->length();

	if (size + lengthB > MAX_SIZE)
	{
		throw "溢出";
	}

	for (int i = 0; i < lengthB; i++)
	{
		T element = L->get(i);
		this->insert(size, element);
	}
}

template<class T>
SequenceList<T>* SequenceList<T>::sortedMerge(SequenceList<T>* ListA, SequenceList<T>* ListB)
{
	if (!(ListA->isSorted() && ListB->isSorted()))
	{
		throw "无序";
	}

	int lengthA = ListA->length();
	int lengthB = ListB->length();
	int lengthC = lengthA + lengthB;
	if (lengthC > MAX_SIZE)
	{
		throw "长度溢出";
	}

	SequenceList<T>* ListC = new SequenceList<T>;
	
	int p1 = 0, p2 = 0;		//取元素的标记
	int i = 0;			//新线性表插入的标记
	while (p1 < lengthA && p2 < lengthB)
	{
		T e1 = ListA->get(p1);
		T e2 = ListB->get(p2);
		if (e1 <= e2)
		{
			ListC->insert(i, e1);
			p1++;
		}
		else
		{
			ListC->insert(i, e2);
			p2++;
		}
		i++;
	}
	
	//表A元素取完了
	if (p1 == lengthA)
	{
		for (int i = p2; i < lengthB; i++)
		{
			ListC->insert(ListC->size, ListB->get(i));
		}
	}

	if (p2 == lengthB)
	{
		for (int i = p1; i < lengthA; i++)
		{
			ListC->insert(ListC->size, ListA->get(i));
		}
	}

	return ListC;
}

template<class T>
bool SequenceList<T>::isSorted()
{
	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] > data[i + 1])
		{
			return false;
		}
	}
	return true;
}


