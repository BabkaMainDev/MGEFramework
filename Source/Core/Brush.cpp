#include "Brush.h"

Brush::Brush()
{
	data = new BrushData;
	if(data)
	{
		data->Reference();
		data->BrushColor = Colors.Black;
		data->Style = Solid;
	}
}

Brush::Brush( Brush& B )
{
	data = B.data; 
}

Brush::Brush( Color InColor, BrushStyle Style )
{
	data = new BrushData;
	if(data)
	{
		data->Reference();
		data->BrushColor = InColor;
		data->Style = Style;
	}
}