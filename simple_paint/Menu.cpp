#include "Menu.h"
#include <iostream>
#include "GlobalVariables.h"
//#include<array>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

constexpr char FILLED_CELL = '#';

class Palette {
    static constexpr std::size_t ELEMENT_WIDTH = 6, ELEMENT_HEIGHT = 4;

    enum Color {
        Red = 12, Green = 10, Blue = 9, Pink = 13, Yellow, White
    };

    int fColors[6] = { Red, White, Green, Yellow, Blue, Pink };
    RectangleOf fBorders;
    //X = 552, Y = 3  X = 577, Y = 11
public:
    Palette(RectangleOf borders) : fBorders(borders) {
        for (short paletteWidth = 0,spaceBetwColors = 0; paletteWidth < 6; paletteWidth +=2, spaceBetwColors += 10)
        {
            SetConsoleTextAttribute(hConsole, fColors[paletteWidth]);
            short height = 0;
            for (; height < ELEMENT_HEIGHT; height++) {
                for (short width = 0; width < ELEMENT_WIDTH; width++) {
                    printToCoordinates( borders.startPoint.X + width + spaceBetwColors,borders.startPoint.Y + height, FILLED_CELL);
                }
            }
            height++;//add space
            
            SetConsoleTextAttribute(hConsole, fColors[paletteWidth + 1]);
            for (; height <= ELEMENT_HEIGHT * 2; height++) {
                for (short width = 0; width < ELEMENT_WIDTH; width++) {
                    printToCoordinates( borders.startPoint.X + width + spaceBetwColors,borders.startPoint.Y + height, FILLED_CELL);
                }
            }
        }
        SetConsoleTextAttribute(hConsole, Color::Green);
    }
    
};
//mistake create cuz COORD display x - 1, y - 1 coord
const int MEASURE_MISTAKE = 1;


void drawClearButton()
{
    SetConsoleTextAttribute(hConsole, 10);//green
    for (int i = clearButton.startPoint.X + 1; i < clearButton.endPoint.X; i++) {
        printToCoordinates(i, clearButton.startPoint.Y + 1, 'C');
        printToCoordinates(i, clearButton.endPoint.Y - 1, 'C');
    }
    for (int j = clearButton.startPoint.Y + 1; j < clearButton.endPoint.Y; j++) {
        printToCoordinates(clearButton.startPoint.X + 1, j, 'C');
    }
}

void drawCircleButton()
{
    SetConsoleTextAttribute(hConsole, 8);// gray
    short space = 3;
    for (short i = diameterOfCircle.startPoint.Y + MEASURE_MISTAKE; i <= diameterOfCircle.endPoint.Y; i++)
    {
        for (short j = diameterOfCircle.startPoint.X + MEASURE_MISTAKE + space; j <= diameterOfCircle.endPoint.X + MEASURE_MISTAKE - space; j++)
        {
            printToCoordinates(j, i, FILLED_CELL);
        }
        short mid = diameterOfCircle.startPoint.Y + (diameterOfCircle.endPoint.Y - diameterOfCircle.startPoint.Y)/2;
        i > mid ? space++ : space--;
    }
    SetConsoleTextAttribute(hConsole, 10);//green
}

void drawCleanerButton()
{
    SetConsoleTextAttribute(hConsole, 8);// gray
    for (short i = cleanButton.startPoint.Y + MEASURE_MISTAKE; i <= cleanButton.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = cleanButton.startPoint.X + MEASURE_MISTAKE; j <= cleanButton.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, FILLED_CELL);
        }
    }
    SetConsoleTextAttribute(hConsole, 10);//green
}

void drawFillBucketButton()
{
    SetConsoleTextAttribute(hConsole, 11);// light blue
    for (short i = fillBucket.startPoint.Y + MEASURE_MISTAKE; i <= fillBucket.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = fillBucket.startPoint.X + MEASURE_MISTAKE; j <= fillBucket.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, '/');// '/' for better looking
        }
    }
    SetConsoleTextAttribute(hConsole, 10);//green
}

void drawRectangleButton()
{
    SetConsoleTextAttribute(hConsole, 8);//gray
    for (short i = sizeOfRectangle.startPoint.Y + MEASURE_MISTAKE; i <= sizeOfRectangle.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = sizeOfRectangle.startPoint.X + MEASURE_MISTAKE; j <= sizeOfRectangle.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, '[');// '[' for better looking
        }
    }
    SetConsoleTextAttribute(hConsole, 10);//green
}

void drawBrushSizeButton()
{
    SetConsoleTextAttribute(hConsole, 8);//gray
    for (short i = smallSizePen.startPoint.Y + MEASURE_MISTAKE; i <= smallSizePen.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = smallSizePen.startPoint.X + MEASURE_MISTAKE; j <= smallSizePen.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, FILLED_CELL);
        }
    }

    for (short i = middleSizePen.startPoint.Y + MEASURE_MISTAKE; i <= middleSizePen.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = middleSizePen.startPoint.X + MEASURE_MISTAKE; j <= middleSizePen.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, FILLED_CELL);
        }
    }

    for (short i = bigSizePen.startPoint.Y + MEASURE_MISTAKE; i <= bigSizePen.endPoint.Y + MEASURE_MISTAKE; i++)
    {
        for (short j = bigSizePen.startPoint.X + MEASURE_MISTAKE; j <= bigSizePen.endPoint.X + MEASURE_MISTAKE; j++)
        {
            printToCoordinates(j, i, FILLED_CELL);
        }
    }
    SetConsoleTextAttribute(hConsole, 10);//green
}

void drawExitButton()
{
    SetConsoleTextAttribute(hConsole, 10);//green
    for (int i = 0; i < exitButton.endPoint.X - exitButton.startPoint.X + MEASURE_MISTAKE; i++) {
        printToCoordinates(exitButton.startPoint.X + i, exitButton.startPoint.Y + i, 'X');
        printToCoordinates(exitButton.endPoint.X - i, exitButton.startPoint.Y + i, 'X');
    }
}

void createMenu()
{

    //static const RectangleOf smallSizePen{
    //    .startPoint = {.X = 532, .Y = 4},
    //    .endPoint = {.X = 534, .Y = 5}
    //};
    //static const RectangleOf middleSizePen{
    //     .startPoint = {.X = 531, .Y = 8},
    //     .endPoint = {.X = 535, .Y = 10}
    //};
    //static const RectangleOf bigSizePen{
    //     .startPoint = {.X = 530, .Y = 13},
    //     .endPoint = {.X = 536, .Y = 16}
    //};
    //
    //static const RectangleOf clearButton{
    //    .startPoint = {.X = 10, .Y = 2},
    //    .endPoint = {.X = 21, .Y = 11}
    //};
    //static const RectangleOf cleanButton{
    //     .startPoint = {.X = 542, .Y = 3,},
    //     .endPoint = {.X = 547, .Y = 6}
    //};
    //static const RectangleOf fillBucketButton{
    //     .startPoint = {.X = 202, .Y = 3},
    //     .endPoint = {.X = 212, .Y = 7}
    //};
    //static const RectangleOf sizeOfRectangle{
    //    .startPoint = {.X = 412, .Y = 4,},
    //    .endPoint = {.X = 427, .Y = 10}
    //};



    const int MAX_WIDTH = 633;
    const int MENU_SIZE = 30;
    
    SetConsoleTextAttribute(hConsole, 10);//скидуємо до дефолт зеленого

    
    for (int i = 0; i < MENU_SIZE; i++)
    {
        std::cout << "\n";
    }
    for (int i = 0; i < MAX_WIDTH + 7; i++)
    {
        std::cout << "|";
    }

    drawClearButton();
    drawCircleButton();
    drawCleanerButton();
    drawFillBucketButton();
    drawRectangleButton();
    drawBrushSizeButton();
    drawExitButton();
    static const RectangleOf paletteCoord{
        .startPoint = {.X = 573, .Y = 4,},
        .endPoint = {.X = 578, .Y = 11}
    };
    Palette palette(paletteCoord);

}