// Pen.h: interface for the Pen class.
//
//////////////////////////////////////////////////////////////////////

// modified Oct 5,2026 19:26 GMT +3

#if !defined(AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_)
#define AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"
#include <SharedDataStructs.h>
#include "Color.h"

enum PenStyle
{
	NoPen,
	SolidLine,
	Dot
};

class Pen : public Object
{
friend class Painter;
public:
	Pen();
	Pen( Pen& P );
	Pen( Color InColor, int InWidth );
	Pen( PenStyle ); // poprobuyem bez nazv v .h
	Pen( Color, int, PenStyle ); // rabotaen oxuenno tak chto continue bez nazv))))

	virtual ~Pen();
	
	int	GetWidth() const			  { return data->Width; }
    void SetWidth( int w )			  { data->Width = w;    }
    Color &GetColor()      			  { return data->Col;   }

	PenStyle GetStyle() const        { return data->Style; }
	void SetStyle( PenStyle S )      { data->Style = S;    }
private:
	struct PenData : public SharedData
	{
		Color Col;
		PenStyle Style;
		int Width;
	} *data;
};

#endif // !defined(AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_)
