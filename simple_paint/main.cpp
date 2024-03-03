#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Drawer.h"

static const RectangleOf redColor{
    .startPoint = {.X = 572, .Y = 3,},
    .endPoint = {.X = 577, .Y = 6}
};
static const RectangleOf greenColor{
    .startPoint = {.X = 582, .Y = 3,},
    .endPoint = {.X = 587, .Y = 6}
};
static const RectangleOf blueColor{
    .startPoint = {.X = 592, .Y = 3,},
    .endPoint = {.X = 597, .Y = 6}
};
static const RectangleOf whiteColor{
   .startPoint = {.X = 572, .Y = 8,},
   .endPoint = {.X = 577, .Y = 11}
};
static const RectangleOf yellowColor{
    .startPoint = {.X = 582, .Y = 8,},
    .endPoint = {.X = 587, .Y = 11}
};
static const RectangleOf pinkColor{
    .startPoint = {.X = 592, .Y = 8,},
    .endPoint = {.X = 597, .Y = 11}
};


static const RectangleOf smallSizePen{
    .startPoint = {.X = 552, .Y = 4},
    .endPoint = {.X = 554, .Y = 5}
};
static const RectangleOf middleSizePen{
     .startPoint = {.X = 551, .Y = 8},
     .endPoint = {.X = 555, .Y = 10}
};
static const RectangleOf bigSizePen{
     .startPoint = {.X = 550, .Y = 13},
     .endPoint = {.X = 556, .Y = 16}
};

static const RectangleOf clearButton{
    .startPoint = {.X = 10, .Y = 2},
    .endPoint = {.X = 21, .Y = 11}
};
static const RectangleOf cleanButton{
     .startPoint = {.X = 542, .Y = 3,},
     .endPoint = {.X = 547, .Y = 6}
};
//static const RectangleOf fillBucketButton{
//     .startPoint = {.X = 262, .Y = 3},
//     .endPoint = {.X = 272, .Y = 7}
//};
static const RectangleOf sizeOfRectangle{
    .startPoint = {.X = 432, .Y = 4,},
    .endPoint = {.X = 447, .Y = 10}
};
static const RectangleOf exitButton{
     .startPoint = {.X = 627, .Y = 2},
     .endPoint = {.X = 637, .Y = 11}
};
static const RectangleOf diameterOfCircle{
    .startPoint = {.X = 393, .Y = 5,},
    .endPoint = {.X = 405, .Y = 10}
};
static const RectangleOf fillBucket{
     .startPoint = {.X = 222, .Y = 4,},
     .endPoint = {.X = 233, .Y = 9}
};


//#define DISPLAY_COORDS

constexpr char FILLED_CELL = '0';

class Brush {
public:
    enum class Type {
        None, Cleaner, Circle, Rectangle, FillBucket
    };

    enum class Size {
        Small, Medium, Big
    };

    void setSize(Size size) { fSize = size; }
    Size getSize() const { return fSize; }

    void switchType(Type type) {
        fType = (fType == type) ? Type::None : type;
    }
    Type getType() const { return fType; }

private:
    Type fType = Type::None;
    Size fSize = Size::Small;
};


bool isRightButtonPressed (INPUT_RECORD InputRecord)
{
    return InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED;
}
bool isLeftButtonPressed(INPUT_RECORD InputRecord)
{
    return InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
}


//треба переробити
void fillerBucket(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords{ .X = x, .Y = y };
    DWORD count;
    CHAR_INFO charInfo;

    // Отримати інформацію про символ на вказаних координатах
    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&charInfo.Char.AsciiChar, 1, coords, &count);// танці з бубнами
    if (charInfo.Char.AsciiChar == FILLED_CELL)
    {
        printToCoordinates(y, x, FILLED_CELL);
        return;
    }



    fillerBucket(x + 1, y + 1);
    fillerBucket(x - 1, y - 1);
    fillerBucket(x + 1, y - 1);
    fillerBucket(x - 1, y + 1);


    printToCoordinates(y + 1, x + 1, FILLED_CELL);
    printToCoordinates(y - 1, x - 1, FILLED_CELL);
    printToCoordinates(y - 1, x + 1, FILLED_CELL);
    printToCoordinates(y + 1, x - 1, FILLED_CELL);
    printToCoordinates(y - 1, x, FILLED_CELL);
    printToCoordinates(y, x - 1, FILLED_CELL);
    printToCoordinates(y, x + 1, FILLED_CELL);
    printToCoordinates(y + 1, x, FILLED_CELL);
}

void draw(Brush brush, COORD coords,const char whatToDraw)
{
    switch (brush.getSize())
    {
    case Brush::Size::Small:
        printToCoordinates(coords.Y + 1, coords.X + 1, FILLED_CELL);
        break;
    case Brush::Size::Medium:
        for (int i = 0; i < 2; i++)
        {
            printToCoordinates(coords.Y + 1, coords.X + 1, FILLED_CELL);
            printToCoordinates(coords.Y - 1, coords.X - 1, FILLED_CELL);
            printToCoordinates(coords.Y, coords.X, FILLED_CELL);
            i == 1 ? coords.X -= 2 : coords.X++;
        }
        break;
    case Brush::Size::Big:
        for (int i = 0; i < 6; i++)
        {
            printToCoordinates(coords.Y + 2, coords.X + 2, FILLED_CELL);
            printToCoordinates(coords.Y + 1, coords.X + 1, FILLED_CELL);
            printToCoordinates(coords.Y - 1, coords.X - 1, FILLED_CELL);
            printToCoordinates(coords.Y - 2, coords.X - 2, FILLED_CELL);
            printToCoordinates(coords.Y, coords.X, FILLED_CELL);
            i == 3 ? coords.X -= 4 : coords.X++;
        }
        break;
    default:
        break;
    }
}



int main()
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

    bool startOfRectangleSet = false;

    bool startOfCircleSet = false;


    COORD startPoint{ .X = 0, .Y = 0 };
    COORD endPoint{ .X = 0,.Y = 0 };


    Brush brush;
    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // зчитування 
        
        if (isRightButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            startPoint = { 0,0 };
            endPoint = { 0,0 };

            startOfRectangleSet = false;

            startOfCircleSet = false;

            if (clearButton.contains(coords))
            {// очистити все

                clear();

                createMenu();
                
                brush.setSize(Brush::Size::Small);

                brush.switchType(Brush::Type::None);

                startOfRectangleSet = false;

                startOfCircleSet = false;

            }
        }
        if (isLeftButtonPressed(InputRecord))
        {
            coords = InputRecord.Event.MouseEvent.dwMousePosition;

            if (exitButton.contains(coords))
            {// вихід
                isExitPressed = true;
            }

            if (clearButton.contains(coords))
            {// очистити
                clear();
                createMenu();
            }

            if (const bool isCanvasPressed = coords.Y > 30; isCanvasPressed)
            {
                switch (brush.getType())
                {
                case Brush::Type::None:
                    draw(brush, coords, '0');
                    break;
                case Brush::Type::Cleaner: {
                    draw(brush, coords, ' ');
                }break;
                case Brush::Type::Circle: {
                    RectangleOf Circle;
                    if (!startOfCircleSet) {
                        Circle.startPoint = coords;
                        startOfCircleSet = true;
                    }
                    Circle.endPoint = coords;
                    drawCircle(Circle);
                }break;
                case Brush::Type::Rectangle:
                    RectangleOf Rectangle;
                    if (!startOfRectangleSet) {
                        Rectangle.startPoint = coords;
                        startOfRectangleSet = true;
                    }
                    Rectangle.endPoint = coords;
                    drawRectangle(Rectangle);
                    break;
                case Brush::Type::FillBucket:
                    fillerBucket(coords.X, coords.Y - 1);
                    break;
                default: 
                    break;
                }
            }
            if (smallSizePen.contains(coords))
            {// зміна на маленький розміру курсора
                brush.setSize(Brush::Size::Small);
            }

            if (middleSizePen.contains(coords))
            {// зміна на середній розміру курсора
                brush.setSize(Brush::Size::Medium);
            }

            if (bigSizePen.contains(coords))
            {// зміна на великий розміру курсора
                brush.setSize(Brush::Size::Big);
            }

            if (cleanButton.contains(coords))
            {// cleaner
                brush.switchType(Brush::Type::Cleaner);
            }



            if (sizeOfRectangle.contains(coords))
            {// малювати квадратом
                brush.switchType(Brush::Type::Rectangle);
            }

            if (diameterOfCircle.contains(coords))
            {// малювати коло
                brush.switchType(Brush::Type::Circle);
            }

            if (fillBucket.contains(coords))
            {// заливка
                brush.switchType(Brush::Type::FillBucket);
            }
            

            if (blueColor.contains(coords))
            {// синій колір
                SetConsoleTextAttribute(hConsole, 9);
            }


            if (greenColor.contains(coords))
            {// зелений колір
                SetConsoleTextAttribute(hConsole, 10);
            }


            if (redColor.contains(coords))
            {// червоний колір
                SetConsoleTextAttribute(hConsole, 12);
            }


            if (whiteColor.contains(coords))
            {// білий колір
                SetConsoleTextAttribute(hConsole, 15);
            }

            if (yellowColor.contains(coords))
            {// жовтий колір
                SetConsoleTextAttribute(hConsole, 14);
            }

            if(pinkColor.contains(coords))
            {// pink колір
                SetConsoleTextAttribute(hConsole, 13);
            }

#ifdef DISPLAY_COORDS
            std::cout << "left - X" << coords.X << ", Y = " << coords.Y << std::endl;
#endif // DISPLAY_COORDS
 
        }
    }




    return 0;

}

