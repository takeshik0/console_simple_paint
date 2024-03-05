#include "Drawer.h"
#include<cmath>

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

void drawCircle(RectangleOf circle)
{
    if (circle.startPoint.X == 0 && circle.startPoint.Y == 0)
    {
        return;
    }
    bool isValid = circle.endPoint.X - circle.startPoint.X < 0 || circle.endPoint.Y - circle.startPoint.Y < 0;
    if (isValid)
    {
        return;
    }
    int centerX = (circle.startPoint.X + circle.endPoint.X) / 2;
    int centerY = (circle.startPoint.Y + circle.endPoint.Y) / 2;
    int radius = std::sqrt(std::pow(circle.endPoint.X - circle.startPoint.X, 2) + std::pow(circle.endPoint.Y - circle.startPoint.Y, 2)) / 2;
    
    // Виведення кола у консоль
    for (int y = 0; y <= centerY + radius; ++y) {
        for (int x = 0; x <= centerX + radius; ++x) {
            // Формула кола (x - centerX)^2 + (y - centerY)^2 = radius^2
            if (std::pow(x - centerX, 2) + std::pow(y - centerY, 2) <= std::pow(radius, 2)) {
                printToCoordinates( x,y, '8');
            }
        }
    }
}

void drawRectangle(RectangleOf rectangle)
{
    if (rectangle.startPoint.X == 0 && rectangle.startPoint.Y == 0)
    {
        return;
    }
    // якщо не буде цього іфа, то програма, коли намагаються малювати не з правого кута в лівий, ламається, а з ним почати малювати інакше не можна
    bool isValid = rectangle.endPoint.X - rectangle.startPoint.X < 0 || rectangle.endPoint.Y - rectangle.startPoint.Y < 0;
    if (isValid)
    {
        return;
    }
    int currStartY = rectangle.startPoint.Y;
    while (currStartY != rectangle.endPoint.Y)
    {
        currStartY++;
        printToCoordinates( rectangle.startPoint.X,currStartY, '8');
    }
    int currStartX = rectangle.startPoint.X;
    while (currStartX != rectangle.endPoint.X)
    {
        currStartX++;
        printToCoordinates( currStartX,rectangle.startPoint.Y, '8');
    }
    int currEndY = rectangle.endPoint.Y;
    while (currEndY != rectangle.startPoint.Y)
    {
        currEndY--;
        printToCoordinates( rectangle.endPoint.X,currEndY, '8');
    }
    int currEndX = rectangle.endPoint.X;
    while (currEndX != rectangle.startPoint.X)
    {
        currEndX--;
        printToCoordinates( currEndX,rectangle.endPoint.Y, '8');
    }
    printToCoordinates(rectangle.endPoint.X,rectangle.endPoint.Y, '8');

}