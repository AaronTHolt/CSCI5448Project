#ifndef _CUBE_SIDES_H_
#define _CUBE_SIDES_H_

#define NUMSIDES 6

enum class CubeSides: int{
    Top    = 0,
    Bottom = 1,
    Left   = 2,
    Right  = 3,
    Front  = 4,
    Back   = 5,
};

int operator+(const CubeSides& c);

#endif
