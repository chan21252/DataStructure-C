#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main(void) {

	LinkedList<int>* list = new LinkedList<int>();
	list->Insert(1, 2);
	list->Insert(2, 4);
	list->Insert(3, 6);
	list->Insert(4, 8);
	list->printList();
	
	return 0;
}