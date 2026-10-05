#pragma once

#include "Size.h"
#include "Point.h"

struct Rect
{
    Point Position;
    Size Dimensions;

    Rect(Point InPosition, Size InSize)
        : Position(InPosition), Dimensions(InSize)
    {
    }

    Rect(int X, int Y, int Width, int Height)
        : Position(X, Y), Dimensions(Width, Height)
    {
    }
};