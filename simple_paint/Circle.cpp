#include "Circle.h"

void drawCircle(const COORD leftUpper, const COORD rightBottom)
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
    int currBottomLeft = leftUpper.X;
    while (currBottom != rightBottom.Y)
    {
        int mid = leftUpper.Y + (rightBottom.Y - leftUpper.Y) / 2;
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

    int currRight = leftUpper.X;
    int currRightTop = leftUpper.Y;
    while (currRight != rightBottom.X)
    {
        int mid = leftUpper.X + (rightBottom.X - leftUpper.X) / 2;
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
    int currUp = rightBottom.Y;
    int currUPRight = rightBottom.X;
    while (currUp != leftUpper.Y)
    {
        int mid = rightBottom.Y + (leftUpper.Y - rightBottom.Y) / 2;
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
    int currLeft = rightBottom.X;
    int currLeftTop = rightBottom.Y;
    while (currLeft != leftUpper.X)
    {
        int mid = rightBottom.X + (leftUpper.X - rightBottom.X) / 2;
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
    printToCoordinates(rightBottom.Y, rightBottom.X, "8");

}