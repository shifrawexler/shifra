#pragma once
#include <iostream>
using namespace std;
class myString
{
private:
    int len;
	char* str;
	void setString(const char* s);
public: 
	char* getString()const { return str; }
	myString(const char* s);//constructor
	myString(const myString& ms); //copy constructor
	~myString(); //destructor
	myString insert(int index, const char* str);
	myString operator=(const myString& s)const;
	bool operator< (const myString&)const;
	bool operator> (const myString&)const;
	bool operator<= (const myString&)const;
	bool operator>= (const myString&)const;
	bool operator!= (const myString&)const;
	char& operator[](int index);
	void print() const;
	void eqtingBigSmall();
};
