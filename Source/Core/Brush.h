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

	

    Color BrushColor;
    BrushStyle Style;
};