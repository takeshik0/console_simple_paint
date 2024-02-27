#include "Menu.h"
//�� ��� �� ���� ����
// �� ���� �������

void createMenu()
{
    //��� � ����� �� ����(�� �����) ���� ������ � �� �������� ��� ������ �� ������ ��������� ������ ������� �� �����
    const int MAX_WIDTH = 613;
    const int MENU_SIZE = 30;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);//������� �� ������ ��������
    for (int i = 0; i < MENU_SIZE - 12 - 2 - 3; i++)
    {
        if (i == 2)
        {

            std::cout << "\n";

            
            std::cout << "            CCCCCC  ";
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 91) && i <= MAX_WIDTH - 86)
                {// ������ ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
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
            
            for (int i = 0; i < MAX_WIDTH - 25; i++)
            {
                
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 121) && i <= MAX_WIDTH - 119)
                {// small pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i == MAX_WIDTH - 91) || i == MAX_WIDTH - 86)
                {// ������ ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
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
            for (int i = 0; i < MAX_WIDTH - 24; i++)
            {
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 257) && i <= MAX_WIDTH - 251)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 121) && i <= MAX_WIDTH - 119)
                {// small pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i == MAX_WIDTH - 91) || i == MAX_WIDTH - 86)
                {// ������ ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
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
            for (int i = 0; i < MAX_WIDTH - 23; i++)
            {
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 259) && i <= MAX_WIDTH - 249)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 91) && i <= MAX_WIDTH - 86)
                {// ������ ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
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
            for (int i = 0; i < MAX_WIDTH - 22; i++)
            {
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 260) && i <= MAX_WIDTH - 248)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
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
            for (int i = 0; i < MAX_WIDTH - 23; i++)
            {
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 260) && i <= MAX_WIDTH - 248)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 122) && i <= MAX_WIDTH - 118)
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 24; i++)
            {
                if ((i >= MAX_WIDTH - 431) && i <= MAX_WIDTH - 421)
                {// �������
                    SetConsoleTextAttribute(hConsole, 11);
                    std::cout << "/";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 259) && i <= MAX_WIDTH - 249)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 122) && i <= MAX_WIDTH - 118)
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 25; i++)
            {
                if ((i >= MAX_WIDTH - 257) && i <= MAX_WIDTH - 251)
                {// ����
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "O";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 231) && i <= MAX_WIDTH - 216)
                {// �������
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "[";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 122) && i <= MAX_WIDTH - 118)
                {// medium pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 81) && i <= MAX_WIDTH - 76)
                {//white
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
                {//pink
                    SetConsoleTextAttribute(hConsole, 13);
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
                else if ((i >= MAX_WIDTH - 71) && i <= MAX_WIDTH - 66)
                {//yellow
                    SetConsoleTextAttribute(hConsole, 14);
                    std::cout << "#";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else if ((i >= MAX_WIDTH - 61) && i <= MAX_WIDTH - 56)
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
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 123) && i <= MAX_WIDTH - 117)
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else{std::cout << " ";} 
            }
            std::cout << "\n";
            std::cout << "                    ";
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 123) && i <= MAX_WIDTH - 117)
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "\n";
            std::cout << "                    ";
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 123) && i <= MAX_WIDTH - 117)
                {// big pensil
                    SetConsoleTextAttribute(hConsole, 8);
                    std::cout << "&";
                    SetConsoleTextAttribute(hConsole, 10);
                }
                else { std::cout << " "; }
            }
            std::cout << "\n";
            std::cout << "                    ";
            for (int i = 0; i < MAX_WIDTH - 26; i++)
            {
                if ((i >= MAX_WIDTH - 123) && i <= MAX_WIDTH - 117)
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