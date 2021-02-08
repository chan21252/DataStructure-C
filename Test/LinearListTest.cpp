/*
 * ˳��������
 * 
 * @file:	LinearTest.cpp
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/04
 */

#include <iostream>
#include "pch.h"
#include "../LinearList/SequenceList.cpp"
#include "../LinearList/LinkedList.cpp"

using namespace std;

/**
 * ����˳���
 */
TEST(case1, testSequenceList) {
	int a[5] = { 1, 2, 3,4, 5 };

	SequenceList<int>* sq = new SequenceList<int>(a, 5);
	int len = sq->length();
	ASSERT_EQ(len, 5);

	sq->insert(2, 10);	//1 2 10 3 4 5
	sq->trasverse();
	EXPECT_TRUE(sq->get(2) == 10);
	EXPECT_TRUE(sq->get(5) == 5);

	sq->remove(0);
	sq->trasverse();
	EXPECT_TRUE(sq->get(0) == 2);
	len = sq->length();
	ASSERT_EQ(len, 5);
}

/**
 * ���Ե������Ա�
 */
TEST(case1, testLinkedList) 
{

	LinkedList<int>* list = new LinkedList<int>();
	list->Insert(1, 2);
	list->Insert(2, 4);
	list->Insert(3, 6);
	list->Insert(4, 8);
	list->printList();
	ASSERT_EQ(list->Get(1), 2);
	ASSERT_EQ(list->Get(4), 8);
	ASSERT_EQ(list->Length(), 4);

	list->Insert(1, 0);
	list->printList();
	list->Delete(1);
	list->printList();
	list->Delete(4);
	list->printList();
	ASSERT_EQ(list->Length(), 3);
	ASSERT_EQ(list->Get(3), 6);
	list->Clear();
	ASSERT_EQ(list->Length(), 0);
}

/**
 * ���Ե������Ա�ͷ�巨
 */
TEST(case2, testLinkedList)
{
	char arr[5] = {'a', 'b', 'c', 'd', 'e'};
	LinkedList<char>* list = new LinkedList<char>(arr, 5);
	list->printList();
	ASSERT_EQ(list->Get(1), 'a');
	ASSERT_EQ(list->Get(4), 'd');
	ASSERT_EQ(list->Length(), 5);
}

/**
 * ���Ե������Ա�β�巨
 */
TEST(case3, testLinkedList)
{
	char arr[5] = { 'H', 'E', 'L', 'L', 'O' };
	LinkedList<char>* list = new LinkedList<char>(arr, 5, false);
	list->printList();
	ASSERT_EQ(list->Get(1), 'H');
	ASSERT_EQ(list->Get(4), 'L');
	ASSERT_EQ(list->Length(), 5);
}



int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}