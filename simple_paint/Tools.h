#pragma once
#include <Windows.h>
void removeScroll();
void consoleSelectionBlock(HANDLE hin);
void printToCoordinates(int x, int y, const char* format, ...);
void clear();