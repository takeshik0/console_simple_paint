#include "GlobalVariables.h"

bool RectangleOf::contains(COORD point) const
{
    return (point.X >= startPoint.X && point.X <= endPoint.X) && (point.Y >= startPoint.Y && point.Y <= endPoint.Y);
}
