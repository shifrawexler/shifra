/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <cstring>
#include <string>
#pragma warning (disable: 4996)
#include "myString.h"
using namespace std;
int main()
{
	//cout << "enter 2 words\n";
	int n = 0,index;
	char a1[50], b1[50], tav;
	cin >> a1;
	//cout << endl;
	cin >> b1;
	//cout << endl;
	//cout<<"enter an index\n";
	cin >> n;
	myString a(a1), b(b1);
	if (a > b)
		cout << "a>b" << endl;
	else
	{
		if (a < b)
			cout << "a<b" << endl;
		else
			cout << "a=b" << endl;
	}
	//if (n > strlen(a1))
	//{
	//	cout << "ERROR\n";
		//for (int i = 0; i < strlen(a1); i++)
		//	*(a1 + i) = 0;
		//*a1 = NULL;
	//}
	myString NewString = a.insert(n, b.getString());
	NewString.print();
	cin >> tav >> index;
	NewString[index] = tav;
	NewString.print();
	return 0;
}
