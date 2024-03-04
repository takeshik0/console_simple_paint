#include "Menu.h"
#include <iostream>
//#include<array>

bool RectangleOf::contains(COORD point) const
{
    return (point.X >= startPoint.X && point.X <= endPoint.X) && (point.Y >= startPoint.Y && point.Y <= endPoint.Y);
}
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
                    printToCoordinates(borders.startPoint.Y + height, borders.startPoint.X + width + spaceBetwColors, FILLED_CELL);
                }
            }
            height++;//add space
            
            SetConsoleTextAttribute(hConsole, fColors[paletteWidth + 1]);
            for (; height <= ELEMENT_HEIGHT * 2; height++) {
                for (short width = 0; width < ELEMENT_WIDTH; width++) {
                    printToCoordinates(borders.startPoint.Y + height, borders.startPoint.X + width + spaceBetwColors, FILLED_CELL);
                }
            }
        }
    }
    
};

void createMenu()
{
     

    static const RectangleOf redColor{
        .startPoint = {.X = 552, .Y = 3,}, 
        .endPoint = {.X = 557, .Y = 6}
    };
    static const RectangleOf greenColor{
        .startPoint = {.X = 562, .Y = 3,},
        .endPoint = {.X = 567, .Y = 6}
    };
    static const RectangleOf blueColor{
        .startPoint = {.X = 572, .Y = 3,},
        .endPoint = {.X = 577, .Y = 6}
    };
    static const RectangleOf whiteColor{
       .startPoint = {.X = 552, .Y = 8,},
       .endPoint = {.X = 557, .Y = 11}
    };
    static const RectangleOf yellowColor{
        .startPoint = {.X = 562, .Y = 8,},
        .endPoint = {.X = 567, .Y = 11}
    };
    static const RectangleOf pinkColor{
        .startPoint = {.X = 572, .Y = 8,},
        .endPoint = {.X = 577, .Y = 11}
    };


    static const RectangleOf smallSizePen{
        .startPoint = {.X = 532, .Y = 4},
        .endPoint = {.X = 534, .Y = 5}
    };
    static const RectangleOf middleSizePen{
         .startPoint = {.X = 531, .Y = 8},
         .endPoint = {.X = 535, .Y = 10}
    };
    static const RectangleOf bigSizePen{
         .startPoint = {.X = 530, .Y = 13},
         .endPoint = {.X = 536, .Y = 16}
    };

    static const RectangleOf clearButton{
        .startPoint = {.X = 10, .Y = 2},
        .endPoint = {.X = 21, .Y = 11}
    };
    static const RectangleOf cleanButton{
         .startPoint = {.X = 542, .Y = 3,},
         .endPoint = {.X = 547, .Y = 6}
    };
    static const RectangleOf fillBucketButton{
         .startPoint = {.X = 202, .Y = 3},
         .endPoint = {.X = 212, .Y = 7}
    };
    static const RectangleOf sizeOfRectangle{
        .startPoint = {.X = 412, .Y = 4,},
        .endPoint = {.X = 427, .Y = 10}
    };

    const int MAX_WIDTH = 633;
    const int MENU_SIZE = 15;
    
    SetConsoleTextAttribute(hConsole, 10);//скидуємо до дефолт зеленого
    for (int i = 0; i < MENU_SIZE; i++)
    {
        if (i == 2)
        {

            std::cout << "\n";
            
            std::cout << "            CCCCCC  ";

            COORD menuCoords{ .X = 0, .Y = 3 };

            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                if (cleanButton.contains(menuCoords))
                {// пустий колір
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (redColor.contains(menuCoords)) 
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (greenColor.contains(menuCoords)) 
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (blueColor.contains(menuCoords)) 
                {//blue
                    SetConsoleTextAttribute(hConsole, 9);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
                
            }
            std::cout << "X";
            for (int i = 0; i < 8; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC      CC";

            menuCoords.Y++;

            for (int i = 0; i < MAX_WIDTH - 25; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords)) 
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (smallSizePen.contains(menuCoords))
                {// small pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (cleanButton.contains(menuCoords))
                {// пустий колір
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (redColor.contains(menuCoords)) 
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (greenColor.contains(menuCoords)) 
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (blueColor.contains(menuCoords)) 
                {//blue
                    SetConsoleTextAttribute(hConsole, 9);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }

            }
            std::cout << "X";
            for (int i = 0; i < 6; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";
            menuCoords.Y++;

            for (int i = 0; i < MAX_WIDTH - 24; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords))
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 257) && i <= MAX_WIDTH - 251)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (smallSizePen.contains(menuCoords))
                {// small pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (cleanButton.contains(menuCoords))
                {// пустий колір
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (redColor.contains(menuCoords))
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (greenColor.contains(menuCoords))
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (blueColor.contains(menuCoords))
                {//blue
                    SetConsoleTextAttribute(hConsole, 9);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }

            }
            std::cout << "X";
            for (int i = 0; i < 4; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";

            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 23; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords))
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 259) && i <= MAX_WIDTH - 249)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (cleanButton.contains(menuCoords))
                {// пустий колір
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (redColor.contains(menuCoords))
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (greenColor.contains(menuCoords))
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (blueColor.contains(menuCoords))
                {//blue
                    SetConsoleTextAttribute(hConsole, 9);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }

            }
            std::cout << "X";
            for (int i = 0; i < 2; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";

            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 22; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords))
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 260) && i <= MAX_WIDTH - 248)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else{std::cout << " ";}
                 
            }
            std::cout << "X";
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";

            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 23; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords))
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 260) && i <= MAX_WIDTH - 248)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (middleSizePen.contains(menuCoords))
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (whiteColor.contains(menuCoords))
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (yellowColor.contains(menuCoords))
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (pinkColor.contains(menuCoords))
                {//pink
                    SetConsoleTextAttribute(hConsole, 13);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else{std::cout << " ";}
                
            }
            std::cout << "X";
            for (int i = 0; i < 2; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";

            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 24; i++)
            {
                menuCoords.X = i;
                if (fillBucketButton.contains(menuCoords))
                {// заливка
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 259) && i <= MAX_WIDTH - 249)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (middleSizePen.contains(menuCoords))
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (whiteColor.contains(menuCoords))
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (yellowColor.contains(menuCoords))
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (pinkColor.contains(menuCoords))
                {//pink
                    SetConsoleTextAttribute(hConsole, 13);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            for (int i = 0; i < 4; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 25; i++)
            {
                menuCoords.X = i;
                if ((i >= MAX_WIDTH - 257) && i <= MAX_WIDTH - 251)
                {// коло
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (sizeOfRectangle.contains(menuCoords))
                {// квадрат
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (middleSizePen.contains(menuCoords))
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (whiteColor.contains(menuCoords))
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (yellowColor.contains(menuCoords))
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (pinkColor.contains(menuCoords))
                {//pink
                    SetConsoleTextAttribute(hConsole, 13);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            for (int i = 0; i < 6; i++)
            {
                std::cout << " ";
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "           CC     CC";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                 if (whiteColor.contains(menuCoords))
                 {//white
                     SetConsoleTextAttribute(hConsole, 15);
                     std::cout << "#";
                     SetConsoleTextAttribute(hConsole, 10);
                }
                 else if (yellowColor.contains(menuCoords))
                 {//yellow
                     SetConsoleTextAttribute(hConsole, 14);
                     std::cout << "#";
                     SetConsoleTextAttribute(hConsole, 10);
                }
                 else if (pinkColor.contains(menuCoords))
                 {//pink
                     SetConsoleTextAttribute(hConsole, 13);
                     std::cout << "#";
                     SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            menuCoords.Y++;
            for (int i = 0; i < 8; i++)
            {
                menuCoords.X = i;
                if (whiteColor.contains(menuCoords))
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (yellowColor.contains(menuCoords))
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if (pinkColor.contains(menuCoords))
                {//pink
                    SetConsoleTextAttribute(hConsole, 13);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "            CCCCCC  ";
            std::cout << "\n";
            std::cout << "                    ";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                if (bigSizePen.contains(menuCoords))
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else{std::cout << " ";} 
            }
            std::cout << "\n";
            std::cout << "                    ";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                if (bigSizePen.contains(menuCoords))
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "\n";
            std::cout << "                    ";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                if (bigSizePen.contains(menuCoords))
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "\n";
            std::cout << "                    ";
            menuCoords.Y++;
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                menuCoords.X = i;
                if (bigSizePen.contains(menuCoords))
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }

        }
        std::cout << "\n";
    }
    for (int i = 0; i < MAX_WIDTH + 7; i++)
    {
        std::cout << "|";
    }
    static const RectangleOf paletteCoord{
        .startPoint = {.X = 573, .Y = 4,},
        .endPoint = {.X = 578, .Y = 11}
    };
    Palette palette(paletteCoord);
}