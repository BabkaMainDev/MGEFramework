// Painter.h: interface for the Painter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTER_H__F1BA90BD_5398_4F32_B63A_6ECE4630FA4D__INCLUDED_)
#define AFX_PAINTER_H__F1BA90BD_5398_4F32_B63A_6ECE4630FA4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "Color.h"
#include "Brush.h"
#include "Rect.h"
#include "Pen.h"

class Painter  
{
public:
	void DrawLine(Point Begin, Point End, Pen InPen);
	void DrawLine(Point Begin, Point End);
	void DrawRect(Color InColor, Rect InRect, Pen InPen );
	void DrawText(const TCHAR* Text, Rect InRect, Color InColor);
	void FillRect(Color InColor, Rect InRect);
	void FillBackground(Color InColor);
	void FillBackground(Color InColor, Rect InRect);
	Painter(HDC InDC);
	virtual ~Painter();

	void SetPen( Pen InPen );

	inline Pen GetPen()           { return pen;  };
	//inline void SetPen(Pen InPen) { pen = InPen; };
private:
	Pen pen; // ne Pen tak kak compiler punch by belt

	HPEN CurrentPen;

	HDC DC;
};

#endif // !defined(AFX_PAINTER_H__F1BA90BD_5398_4F32_B63A_6ECE4630FA4D__INCLUDED_)
