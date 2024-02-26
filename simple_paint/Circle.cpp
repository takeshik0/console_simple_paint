#include "Circle.h"

void drawCircle(std::vector<std::vector<int>>& coordForRectangle)
{
    if (coordForRectangle.size() == 0)
    {
        return;
    }
    if (coordForRectangle[coordForRectangle.size() - 1][0] - coordForRectangle[0][0] < 0 || coordForRectangle[coordForRectangle.size() - 1][1] - coordForRectangle[0][1] < 0)
    {
        return;
    }
    else
    {
        int currBottom = coordForRectangle[0][1];
        int currBottomLeft = coordForRectangle[0][0];
        while (currBottom != coordForRectangle[coordForRectangle.size() - 1][1] )
        {
            int mid = coordForRectangle[0][1] + (coordForRectangle[coordForRectangle.size() - 1][1] - coordForRectangle[0][1]) / 2;
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

        int currRight = coordForRectangle[0][0];
        int currRightTop = coordForRectangle[0][1];
        while (currRight != coordForRectangle[coordForRectangle.size() - 1][0] )
        {
            int mid = coordForRectangle[0][0] + (coordForRectangle[coordForRectangle.size() - 1][0] - coordForRectangle[0][0]) / 2;
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
        int currUp = coordForRectangle[coordForRectangle.size() - 1][1];
        int currUPRight = coordForRectangle[coordForRectangle.size() - 1][0];
        while (currUp != coordForRectangle[0][1])
        {
            int mid = coordForRectangle[coordForRectangle.size() - 1][1] + (coordForRectangle[0][1] - coordForRectangle[coordForRectangle.size() - 1][1]) / 2;
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
        int currLeft = coordForRectangle[coordForRectangle.size() - 1][0];
        int currLeftTop = coordForRectangle[coordForRectangle.size() - 1][1];
        while (currLeft != coordForRectangle[0][0])
        {
            int mid = coordForRectangle[coordForRectangle.size() - 1][0] + (coordForRectangle[0][0] - coordForRectangle[coordForRectangle.size() - 1][0]) / 2;
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
        printToCoordinates(coordForRectangle[coordForRectangle.size() - 1][1], coordForRectangle[coordForRectangle.size() - 1][0], "8");
    }
}