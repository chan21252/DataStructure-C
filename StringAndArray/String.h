/*
 *
 * @file:	String.h
 * @version:1.0
 * @author:	chan
 * @date:	2021/03/04
 */
#pragma once
#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include <cstring>

using namespace std;

const char END_TAG = '\0';

class String
{
public:
	String(const char* str = nullptr);
	String(const String &str);
	~String();
	String& operator=(const String &str);
	int BF(char t[]);	//ÆÓËØµÄÄ£Ê½Æ¥Åä
private:
	char* chs;
	int size;
};
#endif

