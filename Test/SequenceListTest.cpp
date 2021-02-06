/*
 * À≥–Ú±Ì≤‚ ‘¿‡
 * 
 * @file:	SequenceListTest.cpp
 * @version:1.0
 * @author:	chan
 * @date:	2021/02/04
 */

#include <iostream>
#include "pch.h"
#include "../LinearList/SequenceList.cpp"
#include "../LinearList/LinkedList.cpp"

using namespace std;

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

TEST(case2, testLinkedList) 
{

	LinkedList<int>* list = new LinkedList<int>();
	list->Insert(0, 2);
	list->Insert(1, 4);
	list->Insert(2, 6);
	list->Insert(3, 8);
	list->printList();
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}