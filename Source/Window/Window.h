// Window.h: interface for the Window class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOW_H__93A4EC72_8184_4ADC_B349_16898B428ABB__INCLUDED_)
#define AFX_WINDOW_H__93A4EC72_8184_4ADC_B349_16898B428ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windows.h"
#include "../Core/Color.h"

class Painter;

class Window  
{
public:
	virtual void Construct(Painter& P);
	void OnPaint();
	void exec();
	Window();
	virtual ~Window();

	const TCHAR* Title;
	int Width;
	int Height;

	bool Create();
	inline void SetBackgroundColor(Color InColor) { BackgroundColor = InColor; bHasBackgroundColor = 1;} 
private:
    HWND Handle;

	bool bHasBackgroundColor;

	Color BackgroundColor;
};

#endif // !defined(AFX_WINDOW_H__93A4EC72_8184_4ADC_B349_16898B428ABB__INCLUDED_)
