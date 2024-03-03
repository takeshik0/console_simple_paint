#include "Drawer.h"
#include<cmath>

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

void drawCircle(RectangleOf Circle)
{
    if (Circle.startPoint.X == 0 && Circle.startPoint.Y == 0)
    {
        return;
    }
    bool isValid = Circle.endPoint.X - Circle.startPoint.X < 0 || Circle.endPoint.Y - Circle.startPoint.Y < 0;
    if (isValid)
    {
        return;
    }
    int centerX = (Circle.startPoint.X + Circle.endPoint.X) / 2;
    int centerY = (Circle.startPoint.Y + Circle.endPoint.Y) / 2;
    int radius = std::sqrt(std::pow(Circle.endPoint.X - Circle.startPoint.X, 2) + std::pow(Circle.endPoint.Y - Circle.startPoint.Y, 2)) / 2;
    
    // Виведення кола у консоль
    for (int y = 0; y <= centerY + radius; ++y) {
        for (int x = 0; x <= centerX + radius; ++x) {
            // Формула кола (x - centerX)^2 + (y - centerY)^2 = radius^2
            if (std::pow(x - centerX, 2) + std::pow(y - centerY, 2) <= std::pow(radius, 2)) {
                printToCoordinates(y, x, '8');
            }
        }
    }
}

void drawRectangle(RectangleOf Circle)
{
    if (Circle.startPoint.X == 0 && Circle.startPoint.Y == 0)
    {
        return;
    }
    // якщо не буде цього іфа, то програма, коли намагаються малювати не з правого кута в лівий, ламається, а з ним почати малювати інакше не можна
    bool isValid = Circle.endPoint.X - Circle.startPoint.X < 0 || Circle.endPoint.Y - Circle.startPoint.Y < 0;
    if (isValid)
    {
        return;
    }
    int currStartY = Circle.startPoint.Y;
    while (currStartY != Circle.endPoint.Y)
    {
        currStartY++;
        printToCoordinates(currStartY, Circle.startPoint.X, '8');
    }
    int currStartX = Circle.startPoint.X;
    while (currStartX != Circle.endPoint.X)
    {
        currStartX++;
        printToCoordinates(Circle.startPoint.Y, currStartX, '8');
    }
    int currEndY = Circle.endPoint.Y;
    while (currEndY != Circle.startPoint.Y)
    {
        currEndY--;
        printToCoordinates(currEndY, Circle.endPoint.X, '8');
    }
    int currEndX = Circle.endPoint.X;
    while (currEndX != Circle.startPoint.X)
    {
        currEndX--;
        printToCoordinates(Circle.endPoint.Y, currEndX, '8');
    }
    printToCoordinates(Circle.endPoint.Y, Circle.endPoint.X, '8');

}