#include "Menu.h"


RectangleOf redColor{
    .startPoint = {.X = 552, .Y = 3,},
    .endPoint = {.X = 557, .Y = 6}
};
RectangleOf greenColor{
    .startPoint = {.X = 562, .Y = 3,},
    .endPoint = {.X = 567, .Y = 6}
};
RectangleOf blueColor{
    .startPoint = {.X = 572, .Y = 3,},
    .endPoint = {.X = 577, .Y = 6}
};
RectangleOf whiteColor{
   .startPoint = {.X = 552, .Y = 8,},
   .endPoint = {.X = 557, .Y = 11}
};
RectangleOf yellowColor{
    .startPoint = {.X = 562, .Y = 8,},
    .endPoint = {.X = 567, .Y = 11}
};
RectangleOf pinkColor{
    .startPoint = {.X = 572, .Y = 8,},
    .endPoint = {.X = 577, .Y = 11}
};


RectangleOf smallSizePen{
    .startPoint = {.X = 492, .Y = 4},
    .endPoint = {.X = 494, .Y = 5}
};
RectangleOf middleSizePen{
     .startPoint = {.X = 491, .Y = 8},
     .endPoint = {.X = 495, .Y = 10}
};
RectangleOf bigSizePen{
     .startPoint = {.X = 490, .Y = 13},
     .endPoint = {.X = 496, .Y = 16}
};


RectangleOf cleanButton{
     .startPoint = {.X = 522, .Y = 3,},
     .endPoint = {.X = 527, .Y = 6}
};
RectangleOf fillBucketButton{
     .startPoint = {.X = 182, .Y = 3},
     .endPoint = {.X = 192, .Y = 7}
};
RectangleOf sizeOfRectangle{
    .startPoint = {.X = 382, .Y = 4,},
    .endPoint = {.X = 397, .Y = 10}
};


void createMenu()
{
    const int MAX_WIDTH = 613;
    const int MENU_SIZE = 15;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
    for (int i = 0; i < MAX_WIDTH + 27; i++)
    {
        std::cout << "|";
    }
}