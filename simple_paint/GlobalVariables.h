#pragma once
#include "Windows.h"

struct RectangleOf
{
    // Прямокутник задається лівою верхньою координатою та правою нижньою.
    COORD startPoint, endPoint;

    bool contains(COORD point) const;
};

inline static const RectangleOf redColor{
    .startPoint = {.X = 572, .Y = 3,},
    .endPoint = {.X = 577, .Y = 6}
};
inline static const RectangleOf greenColor{
    .startPoint = {.X = 582, .Y = 3,},
    .endPoint = {.X = 587, .Y = 6}
};
inline static const RectangleOf blueColor{
    .startPoint = {.X = 592, .Y = 3,},
    .endPoint = {.X = 597, .Y = 6}
};
inline static const RectangleOf whiteColor{
   .startPoint = {.X = 572, .Y = 8,},
   .endPoint = {.X = 577, .Y = 11}
};
inline static const RectangleOf yellowColor{
    .startPoint = {.X = 582, .Y = 8,},
    .endPoint = {.X = 587, .Y = 11}
};
inline static const RectangleOf pinkColor{
    .startPoint = {.X = 592, .Y = 8,},
    .endPoint = {.X = 597, .Y = 11}
};


inline static const RectangleOf smallSizePen{
    .startPoint = {.X = 552, .Y = 4},
    .endPoint = {.X = 554, .Y = 5}
};
inline static const RectangleOf middleSizePen{
     .startPoint = {.X = 551, .Y = 8},
     .endPoint = {.X = 555, .Y = 10}
};
inline static const RectangleOf bigSizePen{
     .startPoint = {.X = 550, .Y = 13},
     .endPoint = {.X = 556, .Y = 16}
};

inline static const RectangleOf clearButton{
    .startPoint = {.X = 10, .Y = 2},
    .endPoint = {.X = 21, .Y = 11}
};
inline static const RectangleOf cleanButton{
     .startPoint = {.X = 562, .Y = 3,},
     .endPoint = {.X = 567, .Y = 6}
};
inline static const RectangleOf sizeOfRectangle{
    .startPoint = {.X = 432, .Y = 4,},
    .endPoint = {.X = 447, .Y = 10}
};
inline static const RectangleOf exitButton{
     .startPoint = {.X = 627, .Y = 2},
     .endPoint = {.X = 637, .Y = 11}
};
inline static const RectangleOf diameterOfCircle{
    .startPoint = {.X = 393, .Y = 5,},
    .endPoint = {.X = 405, .Y = 10}
};
inline static const RectangleOf fillBucket{
     .startPoint = {.X = 222, .Y = 4,},
     .endPoint = {.X = 233, .Y = 9}
};
