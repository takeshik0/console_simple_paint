#pragma once
#include <array>
#include <optional>
#include "GlobalVariables.h"
#include "Tools.h"


static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



class Palette {
    const char FILLED_CELL = '#';
    static constexpr std::size_t ELEMENT_WIDTH = 6, ELEMENT_HEIGHT = 4;

    enum Color {
        Red = 12, Green = 10, Blue = 9, Pink = 13, Yellow, White , None
    };

    std::array<Color, 6> fColors = { Red, White, Green, Yellow, Blue, Pink };
    RectangleOf fBorders;
public:
    Palette(RectangleOf borders);

    std::optional <Palette::Color> selectColor(COORD point);
};