#include "bullet.h"

void Bullet::move(double dt)
{
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

void Bullet::set_direction(double x, double y)
{
    direction = {x,y};
}

void Bullet::set_infor(double vel, double wei, double size,Bullet_Type type)
{
    velocity = vel;
    weight = wei;
    bulletSize = size;
    whatType = type;
}
double Bullet::get_size() { return bulletSize; }
Pos Bullet::get_position() { return position; }
Pos Bullet::get_start_position() { return startPosition; }


