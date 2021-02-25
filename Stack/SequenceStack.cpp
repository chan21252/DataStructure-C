#include "SequenceStack.h"

template<class T>
inline SequenceStack<T>::SequenceStack()
{
    base = new T[MAX_SIZE];

    if (!base) exit(OVERFLOW);

    top = base;
    capacity = MAX_SIZE;
}

template<class T>
bool SequenceStack<T>::Empty()
{
    return top == base;
}

template<class T>
int SequenceStack<T>::Length()
{
    return top - base;
}

template<class T>
void SequenceStack<T>::Clear()
{
    if (base)
    {
        top = base;
    }
}

template<class T>
void SequenceStack<T>::Destroy(SequenceStack<T>& stack)
{
    if (stack.base)
    {
        delete stack.base;
        stack.base = stack.top = NULL;
        stack.capacity = 0;
    }
}

template<class T>
void SequenceStack<T>::Push(T element)
{
    if (top - base == capacity)
    {
        throw "ջ����";
    }

    *top++ = element;     //*ָ�����㣬ȡָ��ָ���ֵ
    //*top = element;
    //top++;
}

template<class T>
T SequenceStack<T>::Pop()
{
    if (top == base)
    {
        throw "ջΪ��";
    }
    
    T element = *--top;
    return element;
}

template<class T>
void SequenceStack<T>::Traverse()
{
    for (T* p = top; p != base; --p)
    {
        cout << *p << " ";
    }

    cout << endl;
}
