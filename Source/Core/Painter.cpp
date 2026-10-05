// Painter.cpp: implementation of the Painter class.
//
//////////////////////////////////////////////////////////////////////

#include "Painter.h"
#include "Color.h"
#include "Pen.h"
#include "Brush.h"
#include "Font.h"
#include <tchar.h>
#include "Rect.h"
#include "Pen.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Painter::Painter(HDC InDC): DC(InDC)
{
	//OutputDebugString(_T("ZAEBIS)))!!!\n"));
}

Painter::~Painter()
{

}

void Painter::FillBackground(Color InColor)
{
	//OutputDebugString(_T("SOSI HUY SOSUNOK!!!!!)))!!!\n"));
	HBRUSH Brush = CreateSolidBrush(RGB((int)InColor.GetR(), (int)InColor.GetG(), (int)InColor.GetB()));

    RECT WinRect;

	::FillRect(DC, &WinRect, Brush);

    DeleteObject(Brush);
}

void Painter::FillBackground(Color InColor, Rect InRect)
{
    HBRUSH Brush = CreateSolidBrush(RGB((int)InColor.GetR(), (int)InColor.GetG(), (int)InColor.GetB()));

    RECT WinRect;

	WinRect.left   = InRect.Position.X;
	WinRect.top    = InRect.Position.Y;
	WinRect.right  = InRect.Position.X + InRect.Dimensions.Width;
	WinRect.bottom = InRect.Position.Y + InRect.Dimensions.Height;

	::FillRect(DC, &WinRect, Brush);

    DeleteObject(Brush);
}

void Painter::DrawRect(Color InColor, Rect InRect, Pen InPen)
{

}

void Painter::FillRect(Color InColor, Rect InRect) // copy-past from void Painter::FillBackground(Color InColor, Rect InRect)
{
	HBRUSH Brush = CreateSolidBrush(RGB((int)InColor.GetR(), (int)InColor.GetG(), (int)InColor.GetB()));

    RECT WinRect;

	WinRect.left   = InRect.Position.X;
	WinRect.top    = InRect.Position.Y;
	WinRect.right  = InRect.Position.X + InRect.Dimensions.Width;
	WinRect.bottom = InRect.Position.Y + InRect.Dimensions.Height;

	::FillRect(DC, &WinRect, Brush);

    DeleteObject(Brush); 
}

void Painter::DrawText(const TCHAR *Text, Rect InRect, Color InColor)
{
    RECT WinRect;

	::SetBkMode(DC, TRANSPARENT);

	WinRect.left   = InRect.Position.X;
	WinRect.top    = InRect.Position.Y;
	WinRect.right  = InRect.Position.X + InRect.Dimensions.Width;
	WinRect.bottom = InRect.Position.Y + InRect.Dimensions.Height;

	::SetTextColor(DC, RGB((int)InColor.GetR(), (int)InColor.GetG(), (int)InColor.GetB()));
	::DrawText(DC, Text, -1, &WinRect, DT_LEFT | DT_TOP); // :: Inache pizdec!
}

void Painter::DrawLine(Point Begin, Point End)
{
	MoveToEx(DC, Begin.X, Begin.Y, NULL);
	LineTo(DC, End.X, End.Y);
}

void Painter::DrawLine(Point Begin, Point End, Pen InPen)
{
	SetPen(InPen);

	HPEN OldPen = (HPEN)SelectObject(DC, CurrentPen);

	MoveToEx(DC, Begin.X, Begin.Y, NULL);
	LineTo(DC, End.X, End.Y);

	SelectObject(DC, OldPen);
}

void Painter::SetPen(Pen InPen)
{
    pen = InPen;

    CurrentPen = CreatePen( PS_SOLID, pen.width(), RGB( (int)pen.color().GetR(), (int)pen.color().GetG(), (int)pen.color().GetB() ));
}
