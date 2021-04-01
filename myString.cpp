#include <cstring>
#include <string>
#pragma warning (disable: 4996)
#include "myString.h"
#include  <iostream>
#include<cstdlib>
using namespace std;

myString::myString(const char* s)
{
	setString(s);
}

void myString::setString(const char* s)
{
	if (s)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	else str = NULL;
}

myString::myString(const myString& ms)
{
	setString(ms.getString());
}

myString::~myString()
{
	if (str)
		delete[] str;
	str = NULL;
}

myString myString::insert(int index, const char* str)
{

	if (index < 0 || strlen(this->str) < index)
	{
		cout << "ERROR\n";
		str = NULL;
		return str;//i think i have an issue here
	}
	
	int newLen = strlen(this->str) + strlen(str);
	char* temp=new char[newLen+1];
	int i;
	for (i = 0; i < index; i++)
		temp[i] = str[i];   // the string 'b'
	for (int j = 0; j < strlen(this->str);j++,i++)
		temp[i] = this->str[j]; // The string 'a'
	for (int k = index; k < strlen(this->str); k++, i++)
		temp[i] = str[k];
	temp[i] = NULL;
	//delete[]this->str;
	//this->str = temp;
	myString NewStr(temp);
	return NewStr;
}
bool myString::operator>(const myString& ms) const
{
	if (strcmp(str, ms.str) > 0)
		return true;
	return false;
}
bool myString::operator<(const myString& ms) const
{
	if (strcmp(str, ms.str) <0)
		return true;
	return false;
}
bool myString::operator>=(const myString& ms) const
{
	if (strcmp(str, ms.str) >= 0||strcmp(str,ms.str)==0)
		return true;
	return false;
}
bool myString::operator<=(const myString& ms) const
{
	if (strcmp(str, ms.str) < 0 || strcmp(str, ms.str)==0)
		return true;
	return false;
}
bool myString::operator!=(const myString& ms) const
{
	if (strcmp(str, ms.str) == 0)
		return false;
	return true;
}
myString & myString::operator[](int index)
{
	if(index >=0 && index < strlen(str))
	    return this->str[index];
	cout << "ERROR" << endl;
	exit(-1);
}
void myString::print()
{
	if (str!=NULL)
		cout << str << endl;
}

void  myString::eqtingBigSmall()
{
	for (int i = 0; this->getString()[i]; i++)
	{
		if (this->getString()[i] > 65 && this->getString()[i] < 91)
			this->getString()[i] += 32;
	}
}
