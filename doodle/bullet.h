//Daehyeon Kim, Hyeong Ahn, Sunwoo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#pragma once
#include "main_header.h"



class Bullet
{
    Pos startPosition{ 0, 500 };
    Pos position = startPosition;
    Pos direction{ 0, 0 };
    Bullet_Type whatType{ Bullet_Type::Pistol };
    double gravity{ 9.8 };
    double velocity{ 0 };
    double acceleration{ 0 };
    double weight{ 0 };
    double bulletSize{ 0 };

public:
    Bullet() = default;
    Bullet_Type get_bullet_type();
    void move(double dt);
    Pos get_position();
    Pos get_start_position();
    double get_size();
    
    void   set_direction();
    void   set_direction(double, double);
    void   set_infor(double vel, double wei, double size, Bullet_Type what);
};