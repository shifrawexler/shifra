#include <cstring>
#include <string>
#pragma warning (disable: 4996)
#include "myString.h"
#include  <iostream>
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
		temp[i] = str[i];
	for (int j = 0; j < strlen(this->str);j++,i++)
		temp[i] = this->str[j];
	for (int k = index; k < strlen(this->str); k++, i++)
		temp[i] = str[k];
	temp[i] = NULL;
	delete[]this->str;
	this->str = temp;
	return *this;
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
	if (strcmp(str, ms.str) > 0||strcmp(str,ms.str)==0)
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
myString & myString::operator[]( char tav)
{
	int index, index1;
	cin >> index1;
	index = index1;
	if (index >= strlen(this->str))
	{
		cout << "Error\n";
		this->str = NULL;
		return *this;
	}
	else
	{
		char* temp = new char[strlen(this->str) + 1];
		int i;
		for (i = 0; i < index; i++)
			temp[i] = this->str[i];
		temp[i++] = tav;
		for(;i<strlen(this->str)+1;i++)
			temp[i]= this->str[i];
		//not sure if i should do delete here
		this->str = temp;
		return *this;
	}
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
