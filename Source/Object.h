// Object.h: interface for the Object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__7AF5792A_C3C7_4FC9_AD5D_F91186953B19__INCLUDED_)
#define AFX_OBJECT_H__7AF5792A_C3C7_4FC9_AD5D_F91186953B19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Core/Color.h"

struct BaseColors
{
    Color Red;
    Color Green;
    Color Blue;
    Color White;
    Color Black;
    Color Gray;

    BaseColors();
};

class Object  
{
public:
	Object();

	static BaseColors Colors;

	virtual ~Object();
};

#endif // !defined(AFX_OBJECT_H__7AF5792A_C3C7_4FC9_AD5D_F91186953B19__INCLUDED_)
