#include "game.h"

void GameScene::push_bullets(Bullet_Type bulletType)
{
        Bullet bullet;
        switch (bulletType)
        {
        case Bullet_Type::Pistol: 
            bullet.set_direction();
            bullet.set_infor(6000, 10, 20, Bullet_Type::Pistol); 
            break;
        case Bullet_Type::Artillery:
            bullet.set_direction();
            bullet.set_infor(4000, 50, 30,Bullet_Type::Artillery); 
            break;
        case Bullet_Type::Fireball: 
            bullet.set_direction();
            bullet.set_infor(2000, 40, 40, Bullet_Type::Fireball); 
            break;
        case Bullet_Type::Laser:
            bullet.set_direction(400,200);
            bullet.set_infor(8000, 0, 10, Bullet_Type::Laser); 
            break;
        case Bullet_Type::Nuclear: 
            bullet.set_direction();
            bullet.set_infor(5000, 100, 200, Bullet_Type::Nuclear); 
            break;
        }
         // switch로 타입별로 다른 속도랑 무게값(중력) 입력
        bullets.push_back(bullet);
}

void GameScene::push_enemy(Enemy_Type enemyType)
{
    Enemy enemy;
    switch (enemyType)
    {
    case Enemy_Type::Air:
        enemy.set_size(60);
        enemy.set_position(Width, Height * 0.8);
        enemy.set_velocity(100);
        enemy.set_color({ 255, 255, 0});
        break;
    case Enemy_Type::Ground:
        enemy.set_size(100);
        enemy.set_position(Width, enemy.get_size()*.5);
        enemy.set_velocity(100);
        enemy.set_color({ 255, 0 ,255 });
        break;
    }
    enemies.push_back(enemy);
}

void GameScene::move_enmey()
{
    for (auto& i : enemies)
    {
        i.move(DeltaTime);
    }
}

void GameScene::erase_bullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        switch (bullets[i].get_bullet_type())
        {
        case Bullet_Type::Pistol:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 4000)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Artillery:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 8000)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Fireball:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 2000)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Laser:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 20000)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Nuclear:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 10000)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        }
    }
}

void GameScene::erase_enemy()
{
    for (int i = 0; i < enemies.size(); i++)
    {   
        if(enemies[i].get_position().x < 0)
        {
            enemies.erase(enemies.begin() + i);
            MENU=MenuType::Game_Over;
        }
    }
}


void GameScene::draw_bullets()
{
    push_settings();
    no_outline();
    for (auto& i : bullets)
    {
        i.move(DeltaTime);
        switch (i.get_bullet_type())
        {
            case Bullet_Type::Pistol: 
                push_settings();
                set_fill_color(255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Artillery: 
                push_settings();
                set_fill_color(0, 255, 0, 255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Fireball: 
                push_settings();
                set_fill_color(0, 0, 255, 255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Laser: 
                push_settings();
                set_fill_color(255, 0, 0, 255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Nuclear: 
                push_settings();
                set_fill_color(255, 255, 0, 255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
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
        draw_rectangle(x+=x_increase,25,50,50);
        draw_text(to_string(static_cast<int>(p.second)), x , 0);
        //0: Pistol, 1: Artillery, 2: Fireball, 3: Laser, 4: Nuclear
    }
}

void GameScene::draw_enemy()
{
    push_settings();
    no_outline();
    for (auto& i : enemies)
    {
        set_fill_color(i.get_color());
        draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
    }
    pop_settings();
}
//클래스 객체 단위로 총알 한 발을 의미

void GameScene::EraseEnemieByCollision()
{ 
    auto enemies_size = enemies.size();
    auto bullets_size = bullets.size();
    for(auto e = 0; e < enemies_size; e++)
    {
        for(auto b = 0; b < bullets_size; b++)
        {
            if(helper::getDistance(bullets[b].get_position(),enemies[e].get_position()) <= bullets[b].get_size()/2 + enemies[e].get_size()/2)
            {
                enemies.erase(enemies.begin() + e);
            }
        }
    }
}

//충돌 체크 1개, 총알이 없어질 조건
// -> erase 콜