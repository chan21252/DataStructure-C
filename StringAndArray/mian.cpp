#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	char s[10] = { 'a', 'b', 'c', 'a', 'b', 'c', 'a', 'c', 'b','\0' };
	char t[6] = { 'a', 'b', 'c', 'a', 'c', '\0'};
	String str = "abcabcacb";
	int index = str.BF(t);
	cout << "index: " << index << endl;
	return 0;
}