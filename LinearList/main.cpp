#include <iostream>
#include "SequenceList.cpp"

using namespace std;

int main(void) {
	int a[5] = {1, 2, 3,4, 5};
	SequenceList<int>* sq = new SequenceList<int>(a, 5);
	int len = sq->length();
	cout << len << endl;
	sq->trasverse();
	cout << sq->get(1) << endl;
	sq->insert(0, 20);
	sq->trasverse();
	sq->remove(2);
	sq->trasverse();
	return 0;
}