#include "Rectangle.h"

void drawRectangle(const std::vector<std::vector<int>>& coordForRectangle)
{
    if (coordForRectangle.empty())
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
        while (currBottom != coordForRectangle[coordForRectangle.size() - 1][1])
        {
            printToCoordinates(currBottom, coordForRectangle[0][0], "8");
            currBottom++;
            printToCoordinates(currBottom, coordForRectangle[0][0], "8");
        }
        int currRight = coordForRectangle[0][0];
        while (currRight != coordForRectangle[coordForRectangle.size() - 1][0])
        {
            printToCoordinates(coordForRectangle[0][1], currRight, "8");

            currRight++;
            printToCoordinates(coordForRectangle[0][1], currRight, "8");
        }
        int currUp = coordForRectangle[coordForRectangle.size() - 1][1];
        while (currUp != coordForRectangle[0][1])
        {
            printToCoordinates(currUp, coordForRectangle[coordForRectangle.size() - 1][0], "8");
            currUp--;
            printToCoordinates(currUp, coordForRectangle[coordForRectangle.size() - 1][0], "8");
        }
        int currLeft = coordForRectangle[coordForRectangle.size() - 1][0];
        while (currLeft != coordForRectangle[0][0])
        {
            printToCoordinates(coordForRectangle[coordForRectangle.size() - 1][1], currLeft, "8");
            currLeft--;
            printToCoordinates(coordForRectangle[coordForRectangle.size() - 1][1], currLeft, "8");
        }
        printToCoordinates(coordForRectangle[coordForRectangle.size() - 1][1], coordForRectangle[coordForRectangle.size() - 1][0], "8");
    }
}