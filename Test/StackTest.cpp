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
	try
	{
		stack->Pop();
	}
	catch (const exception& e)
	{
		cerr << "exception caught: " << e.what() << endl;
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}