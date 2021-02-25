/*
 * 栈测试类
 *
 * @file:	SequenceStackTest.cpp
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/24
 */

#include <iostream>
#include "pch.h"
#include "../Stack/SequenceStack.cpp"
#include "../Stack/LinkedStack.cpp"
#include "../Stack/CirQueue.cpp"

using namespace std;

/**
 * 测试顺序栈
 */
TEST(case1, testSequenceStack) {
	SequenceStack<char>* stack = new SequenceStack<char>;
	stack->Push('H');
	stack->Push('e');
	stack->Push('l');
	stack->Push('l');
	stack->Push('0');
	stack->Traverse();
	int length = stack->Length();
	cout << "栈的长度：" << length << endl;
	cout << "出栈的顺序：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << stack->Pop() << " ";
	}
	cout << endl;
	stack->Clear();
	cout << "栈的长度：" << stack->Length() << endl;
	SequenceStack<char>::Destroy(*stack);
}

/**
 * 测试链栈
 */
TEST(case1, testLinkedStack) {
	LinkedStack<char>* stack = new LinkedStack<char>;
	stack->Push('H');
	stack->Push('e');
	stack->Push('l');
	stack->Push('l');
	stack->Push('0');
	stack->Traverse();
	int length = stack->Length();
	cout << "栈的长度：" << length << endl;
	cout << "出栈的顺序：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << stack->Pop() << " ";
	}
	cout << endl;
	stack->Clear();
	cout << "栈的长度：" << stack->Length() << endl;
	LinkedStack<char>::Destroy(*stack);
}

/**
 * 测试循环队列
 */
TEST(case1, testCirQueue) {
	CirQueue<char>* queue = new CirQueue<char>;
	queue->EnQueue('A');
	queue->EnQueue('B');
	queue->EnQueue('C');
	queue->EnQueue('D');
	queue->EnQueue('E');
	queue->Traverse();
	int length = queue->Length();
	cout << "队列的长度：" << length << endl;
	cout << "出队的顺序：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << queue->DeQueue() << " ";
	}
	cout << endl;
}

/**
 * 测试循环队列
 */
TEST(case2, testCirQueue) {
	CirQueue<char>* queue = new CirQueue<char>;
	queue->EnQueue('A');
	queue->EnQueue('B');
	queue->EnQueue('C');
	queue->EnQueue('D');
	queue->EnQueue('E');
	queue->Traverse();

	int length = queue->Length();
	cout << "队列的长度：" << length << endl;
	cout << "出队的顺序：" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << queue->DeQueue() << " ";
	}
	queue->Traverse();
	queue->EnQueue('F');
	queue->EnQueue('G');

	queue->Traverse();
	cout << "队列的长度：" << queue->Length() << endl;
	cout << endl;
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}