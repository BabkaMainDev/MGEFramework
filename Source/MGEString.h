// String.h: interface for the String class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRING_H__AF6B9D0A_55D6_4ED5_A36C_2AAE32103BBC__INCLUDED_)
#define AFX_STRING_H__AF6B9D0A_55D6_4ED5_A36C_2AAE32103BBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class String
{
private:
	char* Data;

	unsigned int Size;
	unsigned int Capacity;
public:
	String();
	String(char* InData);
	virtual ~String();

	int Length();
	int GetSize() { return Size; }

	char* GetData() { return Data; }

	String& operator=(const String& other)
	{
		if (this == &other) return *this;

		delete[] Data;

		Size = other.Size;
		Capacity = other.Capacity;

		Data = new char[Capacity];

		for (unsigned int i = 0; i <= Size; i++)
		{
			Data[i] = other.Data[i];
		}

		return *this;
	}

	String operator +=(String& other)
	{
		if (Data != 0) { delete[] Data; Data = 0; }
		if (&other == this) return *this;

		for (unsigned int i = 0; other.Data[i] != '\0'; i++)
		{
			Size++;
		}
		Capacity = (Size + 1) * 2;

		Data = new char[Capacity];

		for (unsigned int i = 0; i < Capacity; i++)
		{
			Data[i] = other.Data[i];
		}

		Data[Size] = '\0';
	}
};

#endif // !defined(AFX_STRING_H__AF6B9D0A_55D6_4ED5_A36C_2AAE32103BBC__INCLUDED_)
