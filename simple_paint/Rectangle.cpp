#include "Rectangle.h"

void drawRectangle(const COORD leftUpper, const COORD rightBottom)
{
    if (leftUpper.X == 0 && leftUpper.Y == 0)
    {
        return;
    }
    // якщо не буде цього іфа, то програма, коли намагаються малювати не з правого кута в лівий, ламається, а з ним почати малювати інакше не можна
    bool isNotFromLeftToRightCorner = rightBottom.X - leftUpper.X < 0 || rightBottom.Y - leftUpper.Y < 0;
    if (isNotFromLeftToRightCorner)
    {
        return;
    }
    int currBottom = leftUpper.Y;
    while (currBottom != rightBottom.Y)
    {
        currBottom++;
        printToCoordinates(currBottom, leftUpper.X, "8");
    }
    int currRight = leftUpper.X;
    while (currRight != rightBottom.X)
    {
        currRight++;
        printToCoordinates(leftUpper.Y, currRight, "8");
    }
    int currUp = rightBottom.Y;
    while (currUp != leftUpper.Y)
    {
        currUp--;
        printToCoordinates(currUp, rightBottom.X, "8");
    }
    int currLeft = rightBottom.X;
    while (currLeft != leftUpper.X)
    {
        currLeft--;
        printToCoordinates(rightBottom.Y, currLeft, "8");
    }
    printToCoordinates(rightBottom.Y, rightBottom.X, "8");

}