// String.cpp: implementation of the String class.
//
//////////////////////////////////////////////////////////////////////

#include "MGEString.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

String::String()
{
	Size = 0;
	Capacity = 0;
}

String::String(char* InData)
{
	unsigned int i = 0;

	for (i = 0; InData[i] != '\0'; i++)
	{
		Size++;
	}
	Capacity = (Size + 1) * 2;

	Data = new char[Capacity];

	for (i = 0; i < Capacity; i++)
	{
		Data[i] = InData[i];
	}

	Data[Size] = '\0';
}

String::~String()
{
	delete Data;
}

int String::Length()
{
	return Capacity;
}
