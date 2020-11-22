#include "game.h"

void GameScene::push_bullets(Bullet_Type bulletType)
{
    if (IsMouseReleased == true)
    {
        Bullet bullet;
        switch (bulletType)
        {
        case Bullet_Type::Pistol: bullet.set_infor(600, 10, Bullet_Type::Pistol); break;
        case Bullet_Type::Artillery: bullet.set_infor(400, 50, Bullet_Type::Artillery); break;
        case Bullet_Type::Fireball: bullet.set_infor(200, 40, Bullet_Type::Fireball); break;
        case Bullet_Type::Laser: bullet.set_infor(300, 30, Bullet_Type::Laser); break;
        case Bullet_Type::Nuclear: bullet.set_infor(1000, 100, Bullet_Type::Nuclear); break;
        }
         // switch로 타입별로 다른 속도랑 무게값(중력) 입력
        bullet.set_direction();
        bullets.push_back(bullet);
    }
}

void GameScene::push_enemy()
{
    Enemy enemy;
    enemies.push_back(enemy);
}

void GameScene::erase_bullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].get_position_x() > Width || bullets[i].get_position_y() < 0)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void GameScene::erase_enemy()
{
    for (int i = 0; i < enemies.size(); i++)
    {   
        if(enemies[i].get_position_x() < 400)
        {
            enemies.erase(enemies.begin() + i);
        }
    }
}


void GameScene::draw_bullets(Bullet_Type bulletType)
{
    push_settings();
    no_outline();
    set_fill_color(0, 0, 255);
    for (auto& i : bullets)
    {
        i.move(DeltaTime);
        switch (bulletType)
        {
            case Bullet_Type::Pistol: 
                push_settings();
                set_fill_color(255);
                draw_ellipse(i.get_position_x(), i.get_position_y(), 30);
                pop_settings();
                break;
            case Bullet_Type::Artillery: 
                push_settings();
                set_fill_color(0, 255, 0, 255);
                draw_ellipse(i.get_position_x(), i.get_position_y(), 50);
                pop_settings();
                break;
            case Bullet_Type::Fireball: 
                push_settings();
                set_fill_color(0, 0, 255, 255);
                draw_ellipse(i.get_position_x(), i.get_position_y(), 100);
                pop_settings();
                break;
            case Bullet_Type::Laser: 
                push_settings();
                set_fill_color(255, 0, 0, 255);
                draw_ellipse(i.get_position_x(), i.get_position_y(), 10); 
                pop_settings();
                break;
            case Bullet_Type::Nuclear: 
                push_settings();
                set_fill_color(255, 255, 0, 255);
                draw_ellipse(i.get_position_x(), i.get_position_y(), 500);
                pop_settings();
                break;
        }
    }
    pop_settings();
}
void GameScene::draw_aim()
{
    double aim_x = get_mouse_x();
    double aim_y = get_mouse_y();
    push_settings();
    set_fill_color(255, 0, 0, 255);
    draw_line(aim_x - 50, aim_y, aim_x + 50, aim_y);
    draw_line(aim_x, aim_y - 50, aim_x, aim_y + 50);
    no_fill();
    draw_ellipse(aim_x, aim_y, 30);
    pop_settings();
}

void GameScene::draw_cards(void)
{
    double x{ Width / 10000. };
    double x_increase{ Width / 30. };
    for (auto p : index_type_map)
    {
        //draw_rectangle(x,0,50,50);
        draw_text(to_string(static_cast<int>(p.second)), x += x_increase, 0);
        //0: Pistol, 1: Artillery, 2: Fireball, 3: Laser, 4: Nuclear
    }
}


void GameScene::draw_enemy()
{}
//클래스 객체 단위로 총알 한 발을 의미