// Pen.cpp: implementation of the Pen class.
//
//////////////////////////////////////////////////////////////////////

#include "Pen.h"
#include "Color.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Pen::Pen()
{
	data = new PenData;
	if(data)
	{
		data->Width = 0;
		data->Col = Color(255, 255, 255);
	}
}

Pen::Pen(Pen &P)
{
	data = P.data;
	data->Reference();
}

Pen::Pen( Color InColor, int InWidth )
{
	data = new PenData;
    if( data )
	{
		data->Width = InWidth;
		data->Col = InColor;
	}
}

Pen::~Pen()
{
	if(data->DeReference())	delete data;
}