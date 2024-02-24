#include "Menu.h"
// це крінж йобаний

void createMenu()
{
    //вже ні хрена не макс(не зайка) відтх просто я не придумав нічо іншого ніж просто замінювати пробіли менюшки на знаки
    const int MAX_WIDTH = 633 - 20;
    const int MENU_SIZE = 30;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < MENU_SIZE - 12; i++)
    {
        if (i == 2)
        {

            std::cout << "\n";

            
            std::cout << "            CCCCCC  ";
            for (int i = 0; i < MAX_WIDTH - 29 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 28 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 27 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 26 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//red
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//green
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 25 + 3; i++)
            {

                std::cout << " "; 
            }
            std::cout << "X";
            std::cout << "X";
            std::cout << "\n";
            std::cout << "          CC        ";
            for (int i = 0; i < MAX_WIDTH - 26 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
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
            for (int i = 0; i < MAX_WIDTH - 27 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
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
            for (int i = 0; i < MAX_WIDTH - 28 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
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
            for (int i = 0; i < MAX_WIDTH - 29 + 3; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            for (int i = 0; i < 8; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "X";
            std::cout << "\n";
            std::cout << "            CCCCCC  ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < MAX_WIDTH + 27; i++)
    {
        std::cout << "|";
    }
}