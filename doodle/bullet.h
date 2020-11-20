#pragma once
#include "main_header.h"



class Bullet
{
    Pos position{ 0, 500 };
    Pos direction{ 0, 0 };
    Bullet_Type whatType;
    double gravity{ 9.8 };
    double velocity{ 0 };
    double acceleration{ 0 };
    double weight{ 0 };

public:
    Bullet() = default;

    void move(double dt);
    double get_position_x();
    double get_position_y();
    void   set_direction();
    void   set_infor(double vel, double wei, Bullet_Type what);
};