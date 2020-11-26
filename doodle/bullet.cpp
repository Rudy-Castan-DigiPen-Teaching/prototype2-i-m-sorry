//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "bullet.h"

void Bullet::move(double dt)
{
    if (dt < 0)
    {
        helper::error("Deltatime cannot be negatve");
    }
    position.x += velocity * direction.x * dt;
    position.y += velocity * direction.y * dt;
    direction.y -= gravity * weight * dt * dt / 2;
}

Bullet_Type Bullet::get_bullet_type() {
    return whatType;
}

void Bullet::set_direction()
{
    direction = { cos(helper::getDegree(get_mouse_y() - get_position().y, get_mouse_x() - get_position().x)),
                 sin(helper::getDegree(get_mouse_y() - get_position().y, get_mouse_x() - get_position().x)) };
}

void Bullet::set_direction_fixed(double x, double y)
{
    if (x < 0 || x > Width)
    {
        helper::error("X position out of range");
    }
    if (y < 0 || y > Height)
    {
        helper::error("Y position out of range");
    }
    direction = { cos(helper::getDegree(y - get_start_position().y, x - get_start_position().x)),
                 sin(helper::getDegree(y - get_start_position().y, x - get_start_position().x)) };
}

void Bullet::set_infor(double vel, double wei, double size,Bullet_Type type)
{
    if (vel < 0)
    {
        helper::error("Velocity cannot be negative");
    }
    if (wei < 0)
    {
        helper::error("Weight cannot be negative");
    }
    if (size < 0)
    {
        helper::error("Ellipse radius cannot be negative");
    }
    if (type < Bullet_Type::Rock || type > Bullet_Type::Nuclear)
    {
        helper::error("failed to match bullet type: " + to_string(static_cast<int>(type)));
    }
    velocity = vel;
    weight = wei;
    bulletSize = size;
    whatType = type;
}
double Bullet::get_size() { return bulletSize; }
Pos Bullet::get_position() { return position; }
Pos Bullet::get_start_position() { return startPosition; }


