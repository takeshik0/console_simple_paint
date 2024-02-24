#include <Windows.h>
#include <iostream>
#include "Menu.h"


void removeScroll()
{
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

    // Get console handle and get screen buffer information from that handle.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);

    // Get rid of the scrollbar by setting the screen buffer size the same as 
    // the console window size.
    COORD new_screen_buffer_size;

    // screenBufferInfo.srWindow allows us to obtain the width and height info 
    // of the visible console in character cells.
    // That visible portion is what we want to set the screen buffer to, so that 
    // no scroll bars are needed to view the entire buffer.
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
        screenBufferInfo.srWindow.Left + 1; // Columns
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
        screenBufferInfo.srWindow.Top + 1; // Rows

    // Set new buffer size
    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
}



void consoleSelectionBlock(HANDLE hin)
{/*block �������� ������*/
    DWORD prev_mode;
    GetConsoleMode(hin, &prev_mode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

void printToCoordinates(int x, int y, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(format, args);
    va_end(args);
    fflush(stdout);
}

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}


int main(int argc, char* argv[])
{
    
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //full screan console

    removeScroll();
    
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // �������� ����������
    INPUT_RECORD InputRecord; // ��������������� ��� ���������� ���������� ��� ����� ����������� � ����������� �������� �����
    DWORD Events; // unsigned long
    COORD coord; // ��� ��������� X, Y


    /*block �������� ������*/
    consoleSelectionBlock(hin);


    createMenu();



    SetConsoleMode(hin, ENABLE_MOUSE_INPUT);// ���������� mouse input

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// ����� ����
    
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
                printToCoordinates(coord.Y + 1 , coord.X + 1 ,"X");
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
            if (coord.Y <= 5 && coord.Y >= 2 && coord.X >= 572 && coord.X <= 577)
            {// ���� ����
                SetConsoleTextAttribute(hConsole, 9);
            }
            //std::cout << "left - X" << coord.X << ", Y = " << coord.Y << std::endl;
        }
    }




    //system("pause");
    return 0;

}