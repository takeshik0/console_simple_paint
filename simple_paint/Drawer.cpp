#include "Drawer.h"
#include<cmath>


void drawCircle(RectangleOf circle)
{
    if (circle.isNotValid(circle)){
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
    if (rectangle.isNotValid(rectangle)) {
        return;
    }
    int currX = rectangle.startPoint.X;
    int currY = rectangle.startPoint.Y;
    while (currY != rectangle.endPoint.Y)
    {
        currY++;
        printToCoordinates( rectangle.startPoint.X,currY, '8');
    }
    while (currX != rectangle.endPoint.X)
    {
        currX++;
        printToCoordinates( currX,rectangle.startPoint.Y, '8');
    }
    while (currY != rectangle.startPoint.Y)
    {
        currY--;
        printToCoordinates( rectangle.endPoint.X,currY, '8');
    }
    while (currX != rectangle.startPoint.X)
    {
        currX--;
        printToCoordinates( currX,rectangle.endPoint.Y, '8');
    }
    printToCoordinates(rectangle.endPoint.X,rectangle.endPoint.Y, '8');

}