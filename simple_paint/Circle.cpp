#include "Circle.h"

void drawCircle(const std::vector<std::vector<int>>& coordForRectangle)
{
    if (coordForRectangle.empty())
    {
        return;
    }
    // якщо не буде цього іфа, то програма, коли намагаються малювати не з правого кута в лівий, ламається, а з ним почати малювати інакше не можна
    bool isNotFromLeftToRightCorner = coordForRectangle.back().front() - coordForRectangle.front().front() < 0 || coordForRectangle.back().back() - coordForRectangle.front().back() < 0;
    if (isNotFromLeftToRightCorner)
    {
        return;
    }
    int currBottom = coordForRectangle.front().back();
    int currBottomLeft = coordForRectangle.front().front();
    while (currBottom != coordForRectangle.back().back())
    {
        int mid = coordForRectangle.front().back() + (coordForRectangle.back().back() - coordForRectangle.front().back()) / 2;
        currBottom++;
        if (currBottom % 2 == 0 && !(currBottom > mid))
        {
            currBottomLeft--;
        }
        if (currBottom % 2 == 0 && currBottom > mid)
        {

            currBottomLeft++;
        }
        printToCoordinates(currBottom, currBottomLeft, "8");
    }

    int currRight = coordForRectangle.front().front();
    int currRightTop = coordForRectangle.front().back();
    while (currRight != coordForRectangle.back().front())
    {
        int mid = coordForRectangle.front().front() + (coordForRectangle.back().front() - coordForRectangle.front().front()) / 2;
        currRight++;
        if (currRight % 6 == 0 && !(currRight > mid))
        {
            currRightTop--;
        }
        if (currRight % 6 == 0 && currRight > mid)
        {
            currRightTop++;
        }


        printToCoordinates(currRightTop, currRight, "8");
    }
    int currUp = coordForRectangle.back().back();
    int currUPRight = coordForRectangle.back().front();
    while (currUp != coordForRectangle.front().back())
    {
        int mid = coordForRectangle.back().back() + (coordForRectangle.front().back() - coordForRectangle.back().back()) / 2;
        if (currUp % 2 == 0 && !(currUp < mid))
        {
            currUPRight++;
        }
        if (currUp % 2 == 0 && currUp < mid)
        {
            currUPRight--;
        }
        printToCoordinates(currUp, currUPRight, "8");
        currUp--;
    }
    int currLeft = coordForRectangle.back().front();
    int currLeftTop = coordForRectangle.back().back();
    while (currLeft != coordForRectangle.front().front())
    {
        int mid = coordForRectangle.back().front() + (coordForRectangle.front().front() - coordForRectangle.back().front()) / 2;
        if (currLeft % 6 == 0 && !(currLeft < mid))
        {
            currLeftTop++;
        }
        if (currLeft % 6 == 0 && (currLeft < mid))
        {
            currLeftTop--;
        }
        printToCoordinates(currLeftTop, currLeft, "8");
        currLeft--;
    }
    printToCoordinates(coordForRectangle.back().back(), coordForRectangle.back().front(), "8");

}