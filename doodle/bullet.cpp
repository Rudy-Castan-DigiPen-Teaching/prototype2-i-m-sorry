#include "bullet.h"

void Bullet::move(double dt)
{
    position.x += velocity * direction.x * dt;
    position.y += velocity * direction.y * dt;
    direction.y -= gravity * weight * dt * dt / 2;
}


void Bullet::set_direction()
{
    direction = { cos(getDegree(get_mouse_y() - get_position_y(), get_mouse_x() - get_position_x())),
                 sin(getDegree(get_mouse_y() - get_position_y(), get_mouse_x() - get_position_x())) };
}

void Bullet::set_infor(double vel, double wei, Bullet_Type type)
{
    velocity = vel;
    weight = wei;
    whatType = type;
}
double Bullet::get_position_x() { return position.x; }
double Bullet::get_position_y() { return position.y; }


