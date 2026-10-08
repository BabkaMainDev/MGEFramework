#pragma once

#include "Color.h"

enum BrushStyle
{
    Solid,
    None
};

class Brush
{
	friend class Painter;

	struct BrushData
	{
		Color BrushColor;
		BrushStyle Style;
	}* data;
};