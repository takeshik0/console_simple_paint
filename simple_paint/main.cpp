#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Drawer.h"
#include "GlobalVariables.h"



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

Brush brush;

class Button
{
public:
    RectangleOf fRectangle;

    bool isClicked(COORD point) const {
        return (point.X >= fRectangle.startPoint.X && point.X <= fRectangle.endPoint.X) && (point.Y >= fRectangle.startPoint.Y && point.Y <= fRectangle.endPoint.Y);
    }
    void onClick(Brush::Type whatToSwich)
    {
        brush.switchType(whatToSwich);
    }

private:

};

Button cleanerButton = { cleanButton };
Button rectangleButton = { sizeOfRectangle };
Button circleButton = { diameterOfCircle  };
Button fillButton = { fillBucket };



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
        printToCoordinates( x,y, FILLED_CELL);
        return;
    }



    fillerBucket(x + 1, y + 1);
    fillerBucket(x - 1, y - 1);
    fillerBucket(x + 1, y - 1);
    fillerBucket(x - 1, y + 1);


    printToCoordinates( x + 1,y + 1, FILLED_CELL);
    printToCoordinates( x - 1,y - 1, FILLED_CELL);
    printToCoordinates( x + 1,y - 1, FILLED_CELL);
    printToCoordinates( x - 1,y + 1, FILLED_CELL);
    printToCoordinates( x,y - 1, FILLED_CELL);
    printToCoordinates( x - 1,y, FILLED_CELL);
    printToCoordinates( x + 1,y, FILLED_CELL);
    printToCoordinates( x,y + 1, FILLED_CELL);
}

void draw(Brush brush, COORD coords,const char whatToDraw)
{
    switch (brush.getSize())
    {
    case Brush::Size::Small:
        printToCoordinates( coords.X + 1,coords.Y + 1, whatToDraw);
        break;
    case Brush::Size::Medium:
        for (int i = 0; i < 2; i++)
        {
            printToCoordinates( coords.X + 1,coords.Y + 1, whatToDraw);
            printToCoordinates( coords.X - 1,coords.Y - 1, whatToDraw);
            printToCoordinates( coords.X,coords.Y, whatToDraw);
            i == 1 ? coords.X -= 2 : coords.X++;
        }
        break;
    case Brush::Size::Big:
        for (int i = 0; i < 6; i++)
        {
            printToCoordinates( coords.X + 2,coords.Y + 2, whatToDraw);
            printToCoordinates( coords.X + 1,coords.Y + 1, whatToDraw);
            printToCoordinates( coords.X - 1,coords.Y - 1, whatToDraw);
            printToCoordinates( coords.X - 2,coords.Y - 2, whatToDraw);
            printToCoordinates( coords.X,coords.Y, whatToDraw);
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




    COORD startPoint{ .X = 0, .Y = 0 };
    COORD endPoint{ .X = 0,.Y = 0 };

    bool startOfRectangleSet = false;

    bool startOfCircleSet = false;
    
    bool isExitPressed = false;
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

            
            if (cleanerButton.isClicked(coords))
            {// cleaner
                cleanerButton.onClick(Brush::Type::Cleaner);
            }

            if (rectangleButton.isClicked(coords))
            {
                rectangleButton.onClick(Brush::Type::Rectangle);
            }

            if (circleButton.isClicked(coords))
            {
                circleButton.onClick(Brush::Type::Circle);
            }

            if (fillButton.isClicked(coords))
            {// заливка
                fillButton.onClick(Brush::Type::FillBucket);
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

