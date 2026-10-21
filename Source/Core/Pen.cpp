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
	if( data )
	{
		data->Width = 8;
		data->Col = Color();
		data->Style = SolidLine;
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
		data->Style = SolidLine;
	}
}

Pen::Pen( PenStyle S )
{
	data = new PenData;
	if ( data )
	{
		data->Col = Color();
		data->Width = 8;
		data->Style = S;
	}
}

Pen::Pen( Color InColor, int InWidth, PenStyle S )
{
	data = new PenData;
	if (data)
	{
		data->Width = InWidth;
		data->Col = InColor;
		data->Style = S;
	}
}

Pen::~Pen()
{
	if(data->DeReference())	delete data;
}