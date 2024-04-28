#pragma once
#include <Windows.h>



void makeFullScreenConsole();
void removeScroll();
void consoleSelectionBlock(HANDLE hin);
void printToCoordinates(int x, int y, const char value);
void clear();

