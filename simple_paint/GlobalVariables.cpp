#include "GlobalVariables.h"


bool RectangleOf::contains(COORD point) const
{
    
    return (point.X >= startPoint.X && point.X <= endPoint.X) && (point.Y >= startPoint.Y && point.Y <= endPoint.Y);
}
bool RectangleOf::isNotValid(RectangleOf rectangle) {
    const bool isNullPoint = (rectangle.startPoint.X == 0 && rectangle.startPoint.Y == 0);
    const bool hasPositiveSides = rectangle.endPoint.X - rectangle.startPoint.X < 0 || rectangle.endPoint.Y - rectangle.startPoint.Y < 0;
    return hasPositiveSides && !isNullPoint;
}
