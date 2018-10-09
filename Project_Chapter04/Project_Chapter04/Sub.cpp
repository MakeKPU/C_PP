#include "pch.h"
#include "Sub.h"


Sub::Sub()
{
}

void Sub::someOtherMethod()
{
	cout << "I can access base class data member mProtectedInt." << endl;
	cout << "Its valueis " << mProtectedInt << endl;
	//cout << "The value of mPrivateInt is " << mPrivateInt << endl; //¿À·ù!
}

void Sub::someMethod()
{
	cout << "This is Sub's version of someMethod()." << endl;
}


Sub::~Sub()
{
}
