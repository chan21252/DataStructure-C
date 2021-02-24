#include "SequenceList.h"

template <class T>
SequenceList<T>::SequenceList()
{
	this->data = new T[MAX_SIZE];
	if (!data)
	{
		throw "��ʼ��˳����쳣";
	}
	this->size = 0;
}

template <class T>
SequenceList<T>::SequenceList(const T a[], int n)
{
	if (n > MAX_SIZE)
	{
		throw "���鳤�ȳ�����󳤶�";
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
		throw "�±�Խ��";
	}
	return data[index];
}

template<class T>
void SequenceList<T>::set(int index, T element)
{
	if (index < 0 || index > size - 1)
	{
		throw "�±�Խ��";
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
		throw "����λ��Խ��";
	}

	if (size == MAX_SIZE)
	{
		throw "˳�������";
	}

	//����λ�ú�֮���Ԫ�غ���һλ
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
		throw "ɾ��λ��Խ��";
	}

	if (isEmpty())
	{
		throw "˳���Ϊ��";
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
		throw "���";
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
		throw "����";
	}

	int lengthA = ListA->length();
	int lengthB = ListB->length();
	int lengthC = lengthA + lengthB;
	if (lengthC > MAX_SIZE)
	{
		throw "�������";
	}

	SequenceList<T>* ListC = new SequenceList<T>;
	
	int p1 = 0, p2 = 0;		//ȡԪ�صı��
	int i = 0;			//�����Ա����ı��
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
	
	//��AԪ��ȡ����
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


