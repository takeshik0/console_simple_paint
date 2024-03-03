#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Rectangle.h"
#include "Circle.h"


//#define DISPLAY_COORDS

constexpr char FILLED_CELL = '0';

bool onRightButtonPressed (INPUT_RECORD InputRecord)
{
    return InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED;
}
bool onLeftButtonPressed(INPUT_RECORD InputRecord)
{
    return InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
}

enum class BrushSize
{
    Small, Medium, Big
};

enum class BrushType 
{
    None, Cleaner, Circle, Rectangle, FillBucket
};

//треба переробити
void bucketAll(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords{ .X = x, .Y = y};
    DWORD count;
    CHAR_INFO charInfo;

    // Отримати інформацію про символ на вказаних координатах
    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&charInfo.Char.AsciiChar, 1, coords, &count);// танці з бубнами
    if (charInfo.Char.AsciiChar == '0')
    {
        printToCoordinates(y, x, "0");
        return;
    }



    bucketAll(x + 1, y + 1);
    bucketAll(x - 1, y - 1);
    bucketAll(x + 1, y - 1);
    bucketAll(x - 1, y + 1);


    printToCoordinates(y + 1, x + 1, "0");
    printToCoordinates(y - 1, x - 1, "0");
    printToCoordinates(y - 1, x + 1, "0");
    printToCoordinates(y + 1, x - 1, "0");
    printToCoordinates(y - 1, x, "0");
    printToCoordinates(y, x - 1, "0");
    printToCoordinates(y, x + 1, "0");
    printToCoordinates(y + 1, x, "0");

} //треба переробити

void draw(BrushSize brushSize, COORD coords,const std::string whatToDraw)
{
    std::string brushWidth;
    switch (brushSize)
    {
    case BrushSize::Small:
        printToCoordinates(coords.Y + 1, coords.X + 1, whatToDraw);
        break;
    case BrushSize::Medium:
        brushWidth = whatToDraw + whatToDraw;
        printToCoordinates(coords.Y + 1, coords.X + 1, brushWidth);
        printToCoordinates(coords.Y - 1, coords.X - 1, brushWidth);
        printToCoordinates(coords.Y, coords.X, brushWidth);
        break;
    case BrushSize::Big:
        brushWidth = whatToDraw + whatToDraw + whatToDraw + whatToDraw;
        printToCoordinates(coords.Y + 2, coords.X + 2, brushWidth);
        printToCoordinates(coords.Y + 1, coords.X + 1, brushWidth);
        printToCoordinates(coords.Y - 1, coords.X - 1, brushWidth);
        printToCoordinates(coords.Y - 2, coords.X - 2, brushWidth);
        printToCoordinates(coords.Y, coords.X, brushWidth);
        break;
    default:
        break;
    }
}


int main(int argc, char* argv[])
{
    makeFullScreenConsole();
    
    removeScroll();//видалено полосу прокрутки
    
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // отримуємо дескриптор
    INPUT_RECORD InputRecord; // використовується для повернення інформації про вхідні повідомлення у консольному вхідному буфері
    DWORD Events; // unsigned long
    COORD coords; // для координат X, Y


    /*block виділення консолі*/
    consoleSelectionBlock(hin);


    createMenu();// створюємо менюшку



    SetConsoleMode(hin, ENABLE_MOUSE_INPUT);// дозволяємо mouse input

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color change

    bool isExitPressed = false;



    BrushSize brushSize = BrushSize::Small;

    BrushType drawingType = BrushType::None;

    bool startOfRectangleSet = false;

    bool startOfCircleSet = false;


    COORD leftUpper{ .X = 0, .Y = 0 };
    COORD rightBottom{ .X = 0,.Y = 0 };



    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // зчитування 
        
        if (onRightButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            leftUpper = { 0,0 };
            rightBottom = { 0,0 };

            startOfRectangleSet = false;

            startOfCircleSet = false;

            RectangleOf clearButton{
                .startPoint = {.X = 10, .Y = 2},
                .endPoint = {.X = 21, .Y = 11}
            };
            if (clearButton.contains(coords))
            {// очистити все

                clear();

                createMenu();

                brushSize = BrushSize::Small;

                drawingType = BrushType::None;

                startOfRectangleSet = false;

                startOfCircleSet = false;

            }
        }
        if (onLeftButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            if (const bool isCanvasPressed = coords.Y > 30; isCanvasPressed)
            {
                switch (drawingType)
                {
                case BrushType::None:
                    draw(brushSize, coords, "0");
                    break;
                case BrushType::Cleaner: {
                    draw(brushSize, coords, " ");
                }break;
                case BrushType::Circle: {
                    if (!startOfCircleSet) {
                        leftUpper = coords;
                        startOfCircleSet = true;
                    }
                    rightBottom = coords;
                    drawCircle(leftUpper, rightBottom);
                }break;
                case BrushType::Rectangle:
                    if (!startOfRectangleSet) {
                        leftUpper = coords;
                        startOfRectangleSet = true;
                    }
                    rightBottom = coords;
                    drawRectangle(leftUpper, rightBottom);
                    break;
                case BrushType::FillBucket:
                    bucketAll(coords.X, coords.Y - 1);
                    break;
                default: 
                    break;
                }
            }
            RectangleOf smallSizePen{
                .startPoint = {.X = 512, .Y = 4},
                .endPoint = {.X = 514, .Y = 5}
            };

            if (smallSizePen.contains(coords))
            {// зміна на маленький розміру курсора
                brushSize = BrushSize::Small;
            }

            RectangleOf middleSizePen{
                .startPoint = {.X = 511, .Y = 8},
                .endPoint = {.X = 515, .Y = 10}
            };
            if (middleSizePen.contains(coords))
            {// зміна на середній розміру курсора
                brushSize = BrushSize::Medium;
            }

            RectangleOf bigSizePen{
                .startPoint = {.X = 510, .Y = 13},
                .endPoint = {.X = 516, .Y = 16}
            };
            if (bigSizePen.contains(coords))
            {// зміна на великий розміру курсора
                brushSize = BrushSize::Big;
            }

            RectangleOf exitButton{
                .startPoint = {.X = 607, .Y = 2},
                .endPoint = {.X = 617, .Y = 11}
            };
            if (exitButton.contains(coords))
            {// вихід
                isExitPressed = true;
            }
            RectangleOf clearButton{
                .startPoint = {.X = 10, .Y = 2},
                .endPoint = {.X = 21, .Y = 11}
            };
            if (clearButton.contains(coords))
            {// очистити
                clear();
                createMenu();
            }

            RectangleOf sizeOfRectangle{
                .startPoint = {.X = 402, .Y = 4,},
                .endPoint = {.X = 417, .Y = 10}
            };
            if (sizeOfRectangle.contains(coords))
            {// малювати квадратом
                drawingType = (drawingType == BrushType::Rectangle) ? BrushType::None : BrushType::Rectangle;
            }

            RectangleOf diameterOfCircle{
                .startPoint = {.X = 373, .Y = 5,},
                .endPoint = {.X = 385, .Y = 10}
            };
            if (diameterOfCircle.contains(coords))
            {// малювати коло
                drawingType = (drawingType == BrushType::Circle) ? BrushType::None : BrushType::Circle;
            }
            
            RectangleOf fullBucket{
                .startPoint = {.X = 202, .Y = 4,},
                .endPoint = {.X = 213, .Y = 9}
            };
            if (fullBucket.contains(coords))
            {// заливка
                drawingType = (drawingType == BrushType::FillBucket) ? BrushType::None : BrushType::FillBucket;
            }

            RectangleOf blueColor{
                .startPoint = {.X = 572, .Y = 3,},
                .endPoint = {.X = 577, .Y = 6}
            };
            if (blueColor.contains(coords))
            {// синій колір
                SetConsoleTextAttribute(hConsole, 9);
            }

            RectangleOf greenColor{
                .startPoint = {.X = 562, .Y = 3,},
                .endPoint = {.X = 567, .Y = 6}
            };
            if (greenColor.contains(coords))
            {// зелений колір
                SetConsoleTextAttribute(hConsole, 10);
            }

            RectangleOf redColor{
                .startPoint = {.X = 552, .Y = 3,},
                .endPoint = {.X = 557, .Y = 6}
            };
            if (redColor.contains(coords))
            {// червоний колір
                SetConsoleTextAttribute(hConsole, 12);
            }

            RectangleOf whiteColor{
                .startPoint = {.X = 552, .Y = 8,},
                .endPoint = {.X = 557, .Y = 11}
            };
            if (whiteColor.contains(coords))
            {// білий колір
                SetConsoleTextAttribute(hConsole, 15);
            }

            RectangleOf yellowColor{
                .startPoint = {.X = 562, .Y = 8,},
                .endPoint = {.X = 567, .Y = 11}
            };
            if (yellowColor.contains(coords))
            {// жовтий колір
                SetConsoleTextAttribute(hConsole, 14);
            }

            RectangleOf pinkColor{
                .startPoint = {.X = 572, .Y = 8,},
                .endPoint = {.X = 577, .Y = 11}
            };
            if(pinkColor.contains(coords))
            {// pink колір
                SetConsoleTextAttribute(hConsole, 13);
            }

            RectangleOf cleanButton{
                .startPoint = {.X = 542, .Y = 3,},
                .endPoint = {.X = 547, .Y = 6}
            };
            if (cleanButton.contains(coords))
            {// cleaner
                drawingType = (drawingType == BrushType::Cleaner) ? BrushType::None : BrushType::Cleaner;
            }
#ifdef DISPLAY_COORDS
            std::cout << "left - X" << coords.X << ", Y = " << coords.Y << std::endl;
#endif // DISPLAY_COORDS
 
        }
    }




    return 0;

}