#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Rectangle.h"
#include "Circle.h"


void printToCoordinates(int x, int y, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(format, args);
    va_end(args);
    fflush(stdout);
}

//bool checkCoords(int x, int y)
//{
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD coord;
//    coord.X = x; // X-координата
//    coord.Y = y;  // Y-координата
//    DWORD count;
//    CHAR_INFO charInfo;
//    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&charInfo.Char.AsciiChar, 1, coord, &count);// танці з бубнами
//    if (charInfo.Char.AsciiChar == '0')
//    {
//        printToCoordinates(y, x, "0");
//        return true;
//    }
//    return false;
//}

void bucketAll(int x, int y)
{//повинно пряцювати,якщо зрозуміти як вийти з рекурсії, але я хз як

    // типу if (x,y != " ") return, я не знайшов як дізнатися значиння у консолі за координатами. знайшов але тепер воно погано працює
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x; // X-координата
    coord.Y = y;  // Y-координата
    DWORD count;
    CHAR_INFO charInfo;

    // Отримати інформацію про символ на вказаних координатах
    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&charInfo.Char.AsciiChar, 1, coord, &count);// танці з бубнами
    if (charInfo.Char.AsciiChar == '0')
    {
        printToCoordinates(y, x, "0");
        return;
    }

    //if (checkCoords(x + 1, y + 1))return;
    //if (checkCoords(x - 1, y - 1))return;
    //if (checkCoords(x + 1, y - 1))return;
    //if (checkCoords(x - 1, y + 1))return;
    //if (checkCoords(x + 1, y + 1))return;
    //if (checkCoords(x + 1, y + 1))return;




    bucketAll(x + 1, y + 1);
    bucketAll(x - 1, y - 1);
    bucketAll(x + 1, y - 1);
    bucketAll(x - 1, y + 1);
    //bucketAll(x + 1, y);


    printToCoordinates(y + 1, x + 1, "0");
    printToCoordinates(y - 1, x - 1, "0");
    printToCoordinates(y - 1, x + 1, "0");
    printToCoordinates(y + 1, x - 1, "0");
    printToCoordinates(y - 1, x, "0");
    printToCoordinates(y, x - 1, "0");
    printToCoordinates(y, x + 1, "0");
    printToCoordinates(y + 1, x, "0");


    //bucketAll(x + 1, y);
    //bucketAll(x - 1, y);
    //bucketAll(x, y + 1);
    //bucketAll(x, y - 1);

    //printToCoordinates(y - 1, x, "0");


    //bucketAll(x, y - 1);




}

int main(int argc, char* argv[])
{
    
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //full screan console

    removeScroll();//видалено полосу прокрутки
    
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // отримуємо дескриптор
    INPUT_RECORD InputRecord; // використовується для повернення інформації про вхідні повідомлення у консольному вхідному буфері
    DWORD Events; // unsigned long
    COORD coord; // для координат X, Y


    /*block виділення консолі*/
    consoleSelectionBlock(hin);


    createMenu();// створюємо менюшку



    SetConsoleMode(hin, ENABLE_MOUSE_INPUT);// дозволяємо mouse input

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color change

    bool isExitPressed = false;

    bool isCleanerActive = false;

    bool isSmallSizePressed = true;

    bool isMediumSizePressed = false;

    bool isBigSizePressed = false;

    bool isQuadroPressed = false;

    bool isCirclePressed = false;

    bool isFullBucketPressed = false;

    bool popBack = true;

    std::vector<std::vector<int>> coordForRectangle;


    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // зчитування 
        
        if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // права кнопка
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            coordForRectangle.clear();
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 10 && coord.X <= 21)
            {// очистити use
                clear();
                createMenu();
                isExitPressed = false;

                isCleanerActive = false;

                isSmallSizePressed = true;

                isMediumSizePressed = false;

                isBigSizePressed = false;

                isQuadroPressed = false;

                isCirclePressed = false;

            }
            //isQuadroPressed = false;
            //std:e:cout << "right - X" << coord.X << ", Y = " << coord.Y << std::endl;
            //break; 
        }
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // ліва кнопка
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            if (coord.Y > 30 && !isQuadroPressed && !isCirclePressed && !isFullBucketPressed)
            {// заборона малювати на менюшці
                if (!isCleanerActive)
                {
                    if (isSmallSizePressed)
                    {
                        printToCoordinates(coord.Y + 1 , coord.X + 1 ,"0");
                    }
                    if (isMediumSizePressed)
                    {
                        printToCoordinates(coord.Y + 1, coord.X + 1, "00");
                        printToCoordinates(coord.Y - 1, coord.X - 1, "00");
                        printToCoordinates(coord.Y, coord.X, "00");
                    }
                    if (isBigSizePressed)
                    {
                        printToCoordinates(coord.Y + 2, coord.X + 2, "0000");
                        printToCoordinates(coord.Y + 1, coord.X + 1, "0000");
                        printToCoordinates(coord.Y - 1, coord.X - 1, "0000");
                        printToCoordinates(coord.Y - 2, coord.X - 2, "0000");
                        printToCoordinates(coord.Y, coord.X, "0000");
                    }
                    
                }
                else //if (isCleanerActive)
                {// cleaner mode
                    if (isSmallSizePressed)
                    {
                        printToCoordinates(coord.Y + 1, coord.X + 1, " ");
                    }
                    if (isMediumSizePressed)
                    {
                        printToCoordinates(coord.Y + 1, coord.X + 1, "  ");
                        printToCoordinates(coord.Y - 1, coord.X - 1, "  ");
                        printToCoordinates(coord.Y, coord.X, "  ");
                    }
                    if (isBigSizePressed)
                    {
                        printToCoordinates(coord.Y + 2, coord.X + 2, "    ");
                        printToCoordinates(coord.Y + 1, coord.X + 1, "    ");
                        printToCoordinates(coord.Y - 1, coord.X - 1, "    ");
                        printToCoordinates(coord.Y - 2, coord.X - 2, "    ");
                        printToCoordinates(coord.Y, coord.X, "    ");
                    }
                }
                
            }
            else if (coord.Y > 30 && isQuadroPressed && !isCirclePressed)
            {
                std::vector<int> temp;
                temp.push_back(coord.X + 1);
                temp.push_back(coord.Y + 1);
                coordForRectangle.push_back(temp);
            }
            else if (coord.Y > 30 && !isQuadroPressed && isCirclePressed)
            {
                std::vector<int> temp;
                temp.push_back(coord.X + 1);
                temp.push_back(coord.Y + 1);
                coordForRectangle.push_back(temp);
            }
            if (coord.Y <= 5 && coord.Y >= 4 && coord.X >= 512 && coord.X <= 514)
            {// зміна на маленький розміру курсора
                isSmallSizePressed = true;
                isMediumSizePressed = false;
                isBigSizePressed = false;
            }
            if (coord.Y <= 10 && coord.Y >= 8 && coord.X >= 511 && coord.X <= 515)
            {// зміна на середній розміру курсора
                isSmallSizePressed = false;
                isMediumSizePressed = true;
                isBigSizePressed = false;
            }
            if (coord.Y <= 16 && coord.Y >= 13 && coord.X >= 510 && coord.X <= 516)
            {// зміна на великий розміру курсора
                isSmallSizePressed = false;
                isMediumSizePressed = false;
                isBigSizePressed = true;
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 607 && coord.X <= 617)
            {// вихід
                isExitPressed = true;
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 10 && coord.X <= 21)
            {// очистити
                clear();
                createMenu();
            }
            if (coord.Y <= 10 && coord.Y >= 4 && coord.X >= 402 && coord.X <= 417)
            {// малювати квадратом
                if (isQuadroPressed)
                {
                    isQuadroPressed = false;
                }
                else
                {
                    isQuadroPressed = true;
                }
            }
            if (coord.Y <= 10 && coord.Y >= 5 && coord.X >= 373 && coord.X <= 385)
            {// малювати коло
                if (isCirclePressed)
                {
                    isCirclePressed = false;
                }
                else
                {
                    isCirclePressed = true;
                }
            }
            if (coord.Y <= 9 && coord.Y >= 4 && coord.X >= 202 && coord.X <= 213)
            {// заливка
                if (isFullBucketPressed)
                {
                    isFullBucketPressed = false;
                }
                else
                {
                    isFullBucketPressed = true;
                }
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 572 && coord.X <= 577)
            {// синій колір
                SetConsoleTextAttribute(hConsole, 9);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 562 && coord.X <= 567)
            {// зелений колір
                SetConsoleTextAttribute(hConsole, 10);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 552 && coord.X <= 557)
            {// червоний колір
                SetConsoleTextAttribute(hConsole, 12);
            }
            if (coord.Y <= 11 && coord.Y >= 8 && coord.X >= 552 && coord.X <= 557)
            {// білий колір
                SetConsoleTextAttribute(hConsole, 15);
            }
            if (coord.Y <= 11 && coord.Y >= 8 && coord.X >= 562 && coord.X <= 567)
            {// жовтий колір
                SetConsoleTextAttribute(hConsole, 14);
            }
            if(coord.Y <= 11 && coord.Y >= 8 && coord.X >= 572 && coord.X <= 577)
            {// pink колір
                SetConsoleTextAttribute(hConsole, 13);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 542 && coord.X <= 547)
            {// червоний колір
                if (isCleanerActive)
                {
                    isCleanerActive = false;
                }
                else 
                {
                    isCleanerActive = true;
                }

            }

            //std::cout << "left - X" << coord.X << ", Y = " << coord.Y << std::endl;
        }
        if (isQuadroPressed && !isCirclePressed)
        {
            drawRectangle(coordForRectangle);
        }
        if (isCirclePressed)
        {
            drawCircle(coordForRectangle);
        }
        if (isFullBucketPressed && coord.Y >30)
        {
            
            bucketAll(coord.X,coord.Y - 1);
        }
    }




    //system("pause");
    return 0;

}