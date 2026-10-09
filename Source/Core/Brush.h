#pragma once

#include "Object.h"
#include "Color.h"
#include "SharedDataStructs.h"

enum BrushStyle
{
    Solid,
    NoBrush
};

class Brush : public Object
{
	friend class Painter;
public:
	Brush();
	Brush( Brush& B );
	Brush( Color InColor, BrushStyle Style );

	virtual ~Brush() { if(data->DeReference()) delete data; }

	Color &GetColor() const     			  { return data->BrushColor;   }
	void SetColor(Color InColor)              { data->BrushColor = InColor;}

	BrushStyle& GetBrushStyle() const         { return data->Style;        }
	void SetBrushStyle(BrushStyle InStyle)    { data->Style = InStyle;     }
private:
	struct BrushData : public SharedData
	{
		Color BrushColor;
		BrushStyle Style;
	}* data;
};