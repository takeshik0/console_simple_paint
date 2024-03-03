#pragma once
#include <Windows.h>


struct RectangleOf
{
    // Прямокутник задається лівою верхньою координатою та правою нижньою.
    COORD startPoint, endPoint;

    bool contains(COORD point) const;
};
void createMenu();