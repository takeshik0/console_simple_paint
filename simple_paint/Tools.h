#pragma once
#include <Windows.h>
#include <format>

void makeFullScreanConsole();
void removeScroll();
void consoleSelectionBlock(HANDLE hin);
void printToCoordinates(int x, int y, std::string_view value);
void clear();

