// Pen.h: interface for the Pen class.
//
//////////////////////////////////////////////////////////////////////

// modified Oct 4,2026 16:15 GMT +3

#if !defined(AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_)
#define AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <SharedDataStructs.h>
#include "Color.h"

class Pen  
{
friend class Painter;
public:
	Pen();
	Pen( Pen& P );
	Pen( Color InColor, int InWidth );

	virtual ~Pen();
	
	int	GetWidth() const			  { return data->Width; }
    void SetWidth( int w )			  { data->Width = w;    }
    Color &GetColor()      			  { return data->Col;   }
private:
	struct PenData : public SharedData
	{
		Color Col;
		int Width;
	} *data;
};

#endif // !defined(AFX_PEN_H__FD5C5558_D318_49D1_B7B5_6052CB7C4ABF__INCLUDED_)
