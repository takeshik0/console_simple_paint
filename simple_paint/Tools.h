#pragma once
#include <Windows.h>
#include <format>

struct RectangleOf
{
    // Прямокутник задається лівою верхньою координатою та правою нижньою.
    COORD leftUpper, rightBottom;

    bool contains(COORD point);
};
void makeFullScreanConsole();
void removeScroll();
void consoleSelectionBlock(HANDLE hin);
void printToCoordinates(int x, int y, std::string_view value);
void clear();

