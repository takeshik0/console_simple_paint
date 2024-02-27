#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Tools.h"
#include "Rectangle.h"
#include "Circle.h"

//#define SEE_COORDS

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

void bucketAll(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord{ .X = x, .Y = y};
    DWORD count;
    CHAR_INFO charInfo;

    // �������� ���������� ��� ������ �� �������� �����������
    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&charInfo.Char.AsciiChar, 1, coord, &count);// ����� � �������
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

void draw(BrushSize &brushSize, COORD coord, std::string whatToDraw)
{
    if (brushSize == BrushSize::Small)
    {
        printToCoordinates(coord.Y + 1, coord.X + 1, whatToDraw);
    }
    if (brushSize == BrushSize::Medium)
    {
        printToCoordinates(coord.Y + 1, coord.X + 1, whatToDraw + whatToDraw);
        printToCoordinates(coord.Y - 1, coord.X - 1, whatToDraw + whatToDraw);
        printToCoordinates(coord.Y, coord.X, whatToDraw + whatToDraw);
    }
    if (brushSize == BrushSize::Big)
    {
        printToCoordinates(coord.Y + 2, coord.X + 2, whatToDraw + whatToDraw + whatToDraw + whatToDraw);//�� ����� �� �� ���������
        printToCoordinates(coord.Y + 1, coord.X + 1, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coord.Y - 1, coord.X - 1, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coord.Y - 2, coord.X - 2, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
        printToCoordinates(coord.Y, coord.X, whatToDraw + whatToDraw + whatToDraw + whatToDraw);
    }
}



int main(int argc, char* argv[])
{
    makeFullScreanConsole();
    
    removeScroll();//�������� ������ ���������
    
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // �������� ����������
    INPUT_RECORD InputRecord; // ��������������� ��� ���������� ���������� ��� ����� ����������� � ����������� �������� �����
    DWORD Events; // unsigned long
    COORD coord; // ��� ��������� X, Y


    /*block �������� ������*/
    consoleSelectionBlock(hin);


    createMenu();// ��������� �������



    SetConsoleMode(hin, ENABLE_MOUSE_INPUT);// ���������� mouse input

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// color change

    bool isExitPressed = false;



    BrushSize brushSize = BrushSize::Small;

    DrawingType drawingType = DrawingType::None;

    std::vector<std::vector<int>> coordForRectangle;



    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // ���������� 
        
        if (onRightButtonPressed(InputRecord))
        {
            coord = InputRecord.Event.MouseEvent.dwMousePosition;

            coordForRectangle.clear();

            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 10 && coord.X <= 21)
            {// �������� use
                clear();
                createMenu();
                isExitPressed = false;

                brushSize = BrushSize::Small;

                drawingType = DrawingType::None;


            }
        }
        if (onLeftButtonPressed(InputRecord))
        {
            coord = InputRecord.Event.MouseEvent.dwMousePosition;

            if (coord.Y > 30 && !(drawingType == DrawingType::Quadro) && !(drawingType == DrawingType::Circle) && !(drawingType == DrawingType::FullBucket))
            {// �������� �������� �� �������
                if (!(drawingType == DrawingType::Cleaner))
                {
                    draw(brushSize, coord, "0");
                    
                }
                else
                {// cleaner mode
                    draw(brushSize, coord, " ");
                }
                
            }
            else if (coord.Y > 30 && (drawingType == DrawingType::Quadro) && !(drawingType == DrawingType::Circle))
            {
                coordForRectangle.push_back({ coord.X + 1 ,coord.Y + 1 });
            }
            else if (coord.Y > 30 && !(drawingType == DrawingType::Quadro) && (drawingType == DrawingType::Circle))
            {
                coordForRectangle.push_back({ coord.X + 1 ,coord.Y + 1 });
            }
            if (coord.Y <= 5 && coord.Y >= 4 && coord.X >= 512 && coord.X <= 514)
            {// ���� �� ��������� ������ �������
                brushSize = BrushSize::Small;
            }
            if (coord.Y <= 10 && coord.Y >= 8 && coord.X >= 511 && coord.X <= 515)
            {// ���� �� ������� ������ �������
                brushSize = BrushSize::Medium;
            }
            if (coord.Y <= 16 && coord.Y >= 13 && coord.X >= 510 && coord.X <= 516)
            {// ���� �� ������� ������ �������
                brushSize = BrushSize::Big;
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 607 && coord.X <= 617)
            {// �����
                isExitPressed = true;
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 10 && coord.X <= 21)
            {// ��������
                clear();
                createMenu();
            }
            if (coord.Y <= 10 && coord.Y >= 4 && coord.X >= 402 && coord.X <= 417)
            {// �������� ���������
                if (!(drawingType == DrawingType::Quadro))
                {
                    drawingType = DrawingType::Quadro;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
            if (coord.Y <= 10 && coord.Y >= 5 && coord.X >= 373 && coord.X <= 385)
            {// �������� ����
                if (!(drawingType == DrawingType::Circle))
                {
                    drawingType = DrawingType::Circle;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
            if (coord.Y <= 9 && coord.Y >= 4 && coord.X >= 202 && coord.X <= 213)
            {// �������
                if (!(drawingType == DrawingType::FullBucket))
                {
                    drawingType = DrawingType::FullBucket;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 572 && coord.X <= 577)
            {// ���� ����
                SetConsoleTextAttribute(hConsole, 9);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 562 && coord.X <= 567)
            {// ������� ����
                SetConsoleTextAttribute(hConsole, 10);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 552 && coord.X <= 557)
            {// �������� ����
                SetConsoleTextAttribute(hConsole, 12);
            }
            if (coord.Y <= 11 && coord.Y >= 8 && coord.X >= 552 && coord.X <= 557)
            {// ���� ����
                SetConsoleTextAttribute(hConsole, 15);
            }
            if (coord.Y <= 11 && coord.Y >= 8 && coord.X >= 562 && coord.X <= 567)
            {// ������ ����
                SetConsoleTextAttribute(hConsole, 14);
            }
            if(coord.Y <= 11 && coord.Y >= 8 && coord.X >= 572 && coord.X <= 577)
            {// pink ����
                SetConsoleTextAttribute(hConsole, 13);
            }
            if (coord.Y <= 6 && coord.Y >= 3 && coord.X >= 542 && coord.X <= 547)
            {// �������� ����
                if (!(drawingType == DrawingType::Cleaner))
                {
                    drawingType = DrawingType::Cleaner;
                }
                else
                {
                    drawingType = DrawingType::None;
                }
            }
#ifdef SEE_COORDS
            std::cout << "left - X" << coord.X << ", Y = " << coord.Y << std::endl;
#endif // DEBUG
 
        }
        if (drawingType == DrawingType::Quadro && !(drawingType == DrawingType::Circle))
        {
            drawRectangle(coordForRectangle);
        }
        if (drawingType == DrawingType::Circle)
        {
            drawCircle(coordForRectangle);
        }
        if (drawingType == DrawingType::FullBucket && coord.Y >30)
        {
            
            bucketAll(coord.X,coord.Y - 1);
        }
    }




    return 0;

}