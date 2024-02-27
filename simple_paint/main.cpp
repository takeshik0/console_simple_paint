#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Rectangle.h"
#include "Circle.h"

//#define DISPLAY_COORDS

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

enum class DrawingType 
{
    None, Cleaner, Circle, Quadro, FullBucket
};

struct RectangleOf 
{
    // Прямокутник задається лівою верхньою координатою та правою нижньою.
    COORD leftUpper, rightBottom;

    bool contains(COORD point) {

        return (point.X >= leftUpper.X && point.X <= rightBottom.X) && (point.Y >= leftUpper.Y && point.Y <= rightBottom.Y);
    };
};

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

}

void draw(BrushSize &brushSize, COORD coords, std::string whatToDraw)
{
    if (brushSize == BrushSize::Small)
    {
        printToCoordinates(coords.Y + 1, coords.X + 1, whatToDraw);
    }
    if (brushSize == BrushSize::Medium)
    {
        printToCoordinates(coords.Y + 1, coords.X + 1, whatToDraw + whatToDraw);
        printToCoordinates(coords.Y - 1, coords.X - 1, whatToDraw + whatToDraw);
        printToCoordinates(coords.Y, coords.X, whatToDraw + whatToDraw);
    }
    if (brushSize == BrushSize::Big)
    {
        printToCoordinates(coords.Y + 2, coords.X + 2, whatToDraw + whatToDraw + whatToDraw + whatToDraw);//не думаю що це правильно
        printToCoordinates(coords.Y + 1, coords.X + 1, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coords.Y - 1, coords.X - 1, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coords.Y - 2, coords.X - 2, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coords.Y, coords.X, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
    }
}



int main(int argc, char* argv[])
{
    makeFullScreanConsole();
    
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

    DrawingType drawingType = DrawingType::None;

    std::vector<std::vector<int>> coordsForRectangle;



    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // зчитування 
        
        if (onRightButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            coordsForRectangle.clear();

            RectangleOf clearButton{
                .leftUpper = {.X = 10, .Y = 2},
                .rightBottom = {.X = 21, .Y = 11}
            };
            if (clearButton.contains(coords))
            {// очистити все

                clear();

                createMenu();

                isExitPressed = false;

                brushSize = BrushSize::Small;

                drawingType = DrawingType::None;


            }
        }
        if (onLeftButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            if (coords.Y > 30 && !(drawingType == DrawingType::Quadro) && !(drawingType == DrawingType::Circle) && !(drawingType == DrawingType::FullBucket))
            {// заборона малювати на менюшці
                if (!(drawingType == DrawingType::Cleaner))
                {
                    draw(brushSize, coords, "0");
                    
                }
                else
                {// cleaner mode
                    draw(brushSize, coords, " ");
                }
                
            }
            else if (coords.Y > 30 && (drawingType == DrawingType::Quadro) && !(drawingType == DrawingType::Circle))
            {
                coordsForRectangle.push_back({ coords.X + 1 ,coords.Y + 1 });
            }
            else if (coords.Y > 30 && !(drawingType == DrawingType::Quadro) && (drawingType == DrawingType::Circle))
            {
                coordsForRectangle.push_back({ coords.X + 1 ,coords.Y + 1 });
            }

            RectangleOf smallSizePen{
                .leftUpper = {.X = 512, .Y = 4},
                .rightBottom = {.X = 514, .Y = 5}
            };

            if (smallSizePen.contains(coords))
            {// зміна на маленький розміру курсора
                brushSize = BrushSize::Small;
            }

            RectangleOf middleSizePen{
                .leftUpper = {.X = 511, .Y = 8},
                .rightBottom = {.X = 515, .Y = 10}
            };
            if (middleSizePen.contains(coords))
            {// зміна на середній розміру курсора
                brushSize = BrushSize::Medium;
            }

            RectangleOf bigSizePen{
                .leftUpper = {.X = 510, .Y = 13},
                .rightBottom = {.X = 516, .Y = 16}
            };
            if (bigSizePen.contains(coords))
            {// зміна на великий розміру курсора
                brushSize = BrushSize::Big;
            }

            RectangleOf exitButton{
                .leftUpper = {.X = 607, .Y = 2},
                .rightBottom = {.X = 617, .Y = 11}
            };
            if (exitButton.contains(coords))
            {// вихід
                isExitPressed = true;
            }
            RectangleOf clearButton{
                .leftUpper = {.X = 10, .Y = 2},
                .rightBottom = {.X = 21, .Y = 11}
            };
            if (clearButton.contains(coords))
            {// очистити
                clear();
                createMenu();
            }

            RectangleOf sizeOfRectangle{
                .leftUpper = {.X = 402, .Y = 4,},
                .rightBottom = {.X = 417, .Y = 10}
            };
            if (sizeOfRectangle.contains(coords))
            {// малювати квадратом
                if (!(drawingType == DrawingType::Quadro))
                {
                    drawingType = DrawingType::Quadro;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }

            RectangleOf diameterOfCircle{
                .leftUpper = {.X = 373, .Y = 5,},
                .rightBottom = {.X = 385, .Y = 10}
            };
            if (diameterOfCircle.contains(coords))
            {// малювати коло
                if (!(drawingType == DrawingType::Circle))
                {
                    drawingType = DrawingType::Circle;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
            
            RectangleOf fullBucket{
                .leftUpper = {.X = 202, .Y = 4,},
                .rightBottom = {.X = 213, .Y = 9}
            };
            if (fullBucket.contains(coords))
            {// заливка
                if (!(drawingType == DrawingType::FullBucket))
                {
                    drawingType = DrawingType::FullBucket;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }

            RectangleOf blueColor{
                .leftUpper = {.X = 572, .Y = 3,},
                .rightBottom = {.X = 577, .Y = 6}
            };
            if (blueColor.contains(coords))
            {// синій колір
                SetConsoleTextAttribute(hConsole, 9);
            }

            RectangleOf greenColor{
                .leftUpper = {.X = 562, .Y = 3,},
                .rightBottom = {.X = 567, .Y = 6}
            };
            if (greenColor.contains(coords))
            {// зелений колір
                SetConsoleTextAttribute(hConsole, 10);
            }

            RectangleOf redColor{
                .leftUpper = {.X = 552, .Y = 3,},
                .rightBottom = {.X = 557, .Y = 6}
            };
            if (redColor.contains(coords))
            {// червоний колір
                SetConsoleTextAttribute(hConsole, 12);
            }

            RectangleOf whiteColor{
                .leftUpper = {.X = 552, .Y = 8,},
                .rightBottom = {.X = 557, .Y = 11}
            };
            if (whiteColor.contains(coords))
            {// білий колір
                SetConsoleTextAttribute(hConsole, 15);
            }

            RectangleOf yellowColor{
                .leftUpper = {.X = 562, .Y = 8,},
                .rightBottom = {.X = 567, .Y = 11}
            };
            if (yellowColor.contains(coords))
            {// жовтий колір
                SetConsoleTextAttribute(hConsole, 14);
            }

            RectangleOf pinkColor{
                .leftUpper = {.X = 572, .Y = 8,},
                .rightBottom = {.X = 577, .Y = 11}
            };
            if(pinkColor.contains(coords))
            {// pink колір
                SetConsoleTextAttribute(hConsole, 13);
            }

            RectangleOf cleanButton{
                .leftUpper = {.X = 542, .Y = 3,},
                .rightBottom = {.X = 547, .Y = 6}
            };
            if (cleanButton.contains(coords))
            {// cleaner
                if (!(drawingType == DrawingType::Cleaner))
                {
                    drawingType = DrawingType::Cleaner;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
#ifdef DISPLAY_COORDS
            std::cout << "left - X" << coords.X << ", Y = " << coords.Y << std::endl;
#endif // DISPLAY_COORDS
 
        }
        if (drawingType == DrawingType::Quadro && !(drawingType == DrawingType::Circle))
        {
            drawRectangle(coordsForRectangle);
        }
        if (drawingType == DrawingType::Circle)
        {
            drawCircle(coordsForRectangle);
        }
        if (drawingType == DrawingType::FullBucket && coords.Y >30)
        {
            
            bucketAll(coords.X,coords.Y - 1);
        }
    }




    return 0;

}