#include <Windows.h>
#include <iostream>
#include "Menu.h"
#include "Tools.h"

void printToCoordinates(int x, int y, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(format, args);
    va_end(args);
    fflush(stdout);
}

int main(int argc, char* argv[])
{
    
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //full screan console

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
    while (!isExitPressed)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events); // ���������� 
        
        if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // ����� ������
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            //std::cout << "right - X" << coord.X << ", Y = " << coord.Y << std::endl;
            break;
        }
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // ��� ������
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            if (coord.Y > 30)
            {// �������� �������� �� �������
                printToCoordinates(coord.Y + 1 , coord.X + 1 ,"0");
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 607 && coord.X <= 617)
            {// ����� � ��������
                isExitPressed = true;
            }
            if (coord.Y <= 11 && coord.Y >= 2 && coord.X >= 10 && coord.X <= 21)
            {// ��������
                clear();
                createMenu();
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

            //std::cout << "left - X" << coord.X << ", Y = " << coord.Y << std::endl;
        }
    }




    //system("pause");
    return 0;

}