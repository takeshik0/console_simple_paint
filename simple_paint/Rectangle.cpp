#include "Rectangle.h"

void drawRectangle(const std::vector<std::vector<int>>& coordForRectangle)
{
    if (coordForRectangle.empty())
    {
        return;
    }
    // якщо не буде цього іфа, то програма, коли намагаються малювати не з правого кута в лівий, ламається, а з ним почати малювати інакше не можна
    bool isNotFromLeftToRightCorner = coordForRectangle.back().front() - coordForRectangle.front().front() < 0 || coordForRectangle.back().front() - coordForRectangle.front().back() < 0;
    if (isNotFromLeftToRightCorner)
    {
        return;
    }
    int currBottom = coordForRectangle.front().back();
    while (currBottom != coordForRectangle.back().back())
    {
        currBottom++;
        printToCoordinates(currBottom, coordForRectangle.front().front(), "8");
    }
    int currRight = coordForRectangle.front().front();
    while (currRight != coordForRectangle.back().front())
    {
        currRight++;
        printToCoordinates(coordForRectangle.front().back(), currRight, "8");
    }
    int currUp = coordForRectangle.back().back();
    while (currUp != coordForRectangle.front().back())
    {
        currUp--;
        printToCoordinates(currUp, coordForRectangle.back().front(), "8");
    }
    int currLeft = coordForRectangle.back().front();
    while (currLeft != coordForRectangle.front().front())
    {
        currLeft--;
        printToCoordinates(coordForRectangle.back().back(), currLeft, "8");
    }
    printToCoordinates(coordForRectangle.back().back(), coordForRectangle.back().front(), "8");

}