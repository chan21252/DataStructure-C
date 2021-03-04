#include "String.h"

//¹Ø±Õ±àÒë¾¯¸æ
#pragma warning(disable : 4996)

String::String(const char* str /*= nullptr*/)
{
	if (str == nullptr)
	{
		chs = new char[1];
		chs[0] = END_TAG;
		size = 0;
	}
	else
	{
		size = strlen(str);
		chs = new char[size + 1];
		strcpy(chs, str);
	}
}

String::String(const String& str)
{
	size = str.size;
	chs = new char[size + 1];
	strcpy(chs, str.chs);
}

String::~String()
{
	delete[] chs;
}

String& String::operator=(const String& str)
{
	if (this == &str)
	{
		return *this;
	}
	size = strlen(str.chs);
	chs = new char[size + 1];
	strcpy(chs, str.chs);
	return *this;
}

int String::BF(char t[])
{
	int i = 0, j = 0;
	int _chs_size = sizeof(t);
	while (chs[i] != END_TAG && t[j] != END_TAG)
	{
		if (chs[i] == t[j]) 
		{
			i++; j++;
		}
		else
		{
			i = i - j+ 1;
			j = 0;
		}
	}

	if (t[j] == END_TAG) return i - j;
	else return -1;
}
