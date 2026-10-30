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
    String(const String& Other);
    virtual ~String();

    int Length();
    int GetSize() { return Size; }

    char* GetData() { return Data; }

    String& operator=(const String& Other)
    {
        if (this == &Other)
            return *this;

        char* NewData = new char[Other.Capacity];

        for (unsigned int i = 0; i <= Other.Size; i++)
        {
            NewData[i] = Other.Data[i];
        }

        delete[] Data;

        Data = NewData;
        Size = Other.Size;
        Capacity = Other.Capacity;

        return *this;
    }

    String& operator+=(const String& Other)
    {
        if (this == &Other)
        {
            return *this;
        }

        unsigned int OtherSize = Other.Size;
        unsigned int NewSize = Size + OtherSize;
        unsigned int NewCapacity = Capacity;

        if (NewSize + 1 > NewCapacity)
        {
            NewCapacity = (NewSize + 1) * 2;
        }

        char* NewData = new char[NewCapacity];

        unsigned int i;

        for (i = 0; i < Size; i++)
        {
            NewData[i] = Data[i];
        }

        for (unsigned int j = 0; j < OtherSize; j++, i++)
        {
            NewData[i] = Other.Data[j];
        }

        NewData[NewSize] = '\0';

        delete[] Data;

        Data = NewData;
        Size = NewSize;
        Capacity = NewCapacity;

        return *this;
    }

    String operator+(const String& Other) const
    {
        String Result(*this);
        Result += Other;
        return Result;
    }

    bool operator==(const String& Other) const
    {
        if (Size != Other.Size)
            return false;

        for (unsigned int i = 0; i < Size; i++)
        {
            if (Data[i] != Other.Data[i])
                return false;
        }

        return true;
    }
};

#endif // !defined(AFX_STRING_H__AF6B9D0A_55D6_4ED5_A36C_2AAE32103BBC__INCLUDED_)
