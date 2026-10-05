#pragma once

#include "Color.h"

enum BrushStyle
{
    Solid,
    None
};

struct Brush
{
    Color BrushColor;
    BrushStyle Style;
};