#pragma once
#include <Windows.h>
#include "Tools.h"


struct RectangleOf
{
    // ����������� �������� ���� �������� ����������� �� ������ �������.
    COORD startPoint, endPoint;

    bool contains(COORD point) const;
};


void createMenu();