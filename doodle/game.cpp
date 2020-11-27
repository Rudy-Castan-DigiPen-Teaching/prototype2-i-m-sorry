//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "game.h"

void GameScene::start_level()
{
    remaning_enemy = LEVEL * 3;
    enemy_interver -= 10 * LEVEL;
    if (enemy_interver < 50)
    {
        enemy_interver = 50;
    }
}

void GameScene::next_level()
{
    if (enemies.empty() && MENU == MenuType::In_Game && remaning_enemy == 0)
    {
        LEVEL++;
        MONEY += LEVEL * STARTMONEY;
        timer = 0;
        MENU = MenuType::Purchase;
        bullets.clear();
        index_type_map.clear();
    }
}

void GameScene::new_level()
{
        if(timer % enemy_interver == 0 && remaning_enemy != 0)
        {
            push_enemy();
            remaning_enemy--;
        }
        timer++;
}

void GameScene::reset_game()
{
    MONEY = STARTMONEY;
    LEVEL = 1;
    bullets.clear();
    enemies.clear();
    index_type_map.clear();
    
}
void GameScene::push_bullets(Bullet_Type bulletType)
{
    if (bulletType < Bullet_Type::Rock || bulletType > Bullet_Type::Nuclear)
    {
        helper::error("failed to match bullet type: " + to_string(static_cast<int>(bulletType)));
    }
    Bullet bullet;
    switch (bulletType)
    {
    case Bullet_Type::Rock:
        bullet.set_direction();
        bullet.set_infor(3000, 100, 75, Bullet_Type::Rock); 
        art.PlaySound(RockSound);
        break;
    case Bullet_Type::Pistol:
        bullet.set_direction();
        bullet.set_infor(4000, 10, 50,Bullet_Type::Pistol); 
        art.PlaySound(PistolSound);
        break;
    case Bullet_Type::Barrier:
        bullet.set_direction_fixed(0, Height/2);
        bullet.set_infor(10, 0, Height, Bullet_Type::Barrier);
        art.PlaySound(BarrierSound);
        break;
    case Bullet_Type::Laser:
        bullet.set_direction();
        bullet.set_infor(8000, 0, 50, Bullet_Type::Laser); 
        art.PlaySound(LaserSound);
        break;
    case Bullet_Type::Nuclear:
        bullet.set_direction_fixed(0, Height/2);
        bullet.set_infor(1000, 0, Height, Bullet_Type::Nuclear); 
        art.PlaySound(NuclearSound);
        break;
    }
    bullets.push_back(bullet);
}

void GameScene::push_enemy()
{
    Enemy enemy;

    enemy.set_size(random(100., 300.));
    enemy.set_position(Width, random(100., Height-100.));
    enemy.set_velocity(100+random(150., 250.) * LEVEL / 10);
    enemy.set_color({ random(0.,256.), random(0.,256.), random(0.,256.), random(100.,256.) });
    enemy.set_health(LEVEL/5 + 1);
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
        case Bullet_Type::Rock:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Pistol:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width * 0.7)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Barrier:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= 3)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Laser:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
            {
                bullets.erase(bullets.begin() + i);
            }
            break;
        case Bullet_Type::Nuclear:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
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
            case Bullet_Type::Rock: 
                push_settings();
                set_fill_color(255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Pistol: 
                push_settings();
                set_fill_color(0, 255, 0, 255);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Barrier: 
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
    draw_line(0,Height/2,aim_x,aim_y);
    pop_settings();
}

void GameScene::draw_cards(void)
{
    double x{ Width / 10000. };
    double x_increase{ Width / 30. };
    push_settings();
    for (auto p : index_type_map)
    {
        switch (p.second)
        {
        case Bullet_Type::Rock:
            set_fill_color(255);
            break;
        case Bullet_Type::Pistol:
           set_fill_color(0, 255, 0, 255);
            break;
        case Bullet_Type::Barrier:
            set_fill_color(0, 0, 255, 255);
            break;
        case Bullet_Type::Laser:
            set_fill_color(255, 0, 0, 255);
            break;
        case Bullet_Type::Nuclear:
            set_fill_color(255, 255, 0, 255);
            break;
        }
        draw_ellipse(x+=x_increase,25,50);
    }
    pop_settings();
}

void GameScene::draw_enemy()
{
    push_settings();
    no_outline();
    for (auto& i : enemies)
    {
        set_fill_color(i.get_color());
        draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
        push_settings();
        set_outline_color(0);
        draw_text(to_string(i.get_health()),i.get_position().x, i.get_position().y);
        pop_settings();
    }
    pop_settings();
}

void GameScene::EraseEnemieByCollision()
{ 
    vector<int> eraseB;
    vector<int> eraseE;
    for(auto e = 0; e < enemies.size(); e++)
    {
        for(auto b = 0; b < bullets.size(); b++)
        {
            if(helper::getDistance(bullets[b].get_position(),enemies[e].get_position()) <= bullets[b].get_size()/2 + enemies[e].get_size()/2)
            {   
                if (bullets[b].get_bullet_type() == Bullet_Type::Rock || bullets[b].get_bullet_type() == Bullet_Type::Pistol)
                {
                    eraseB.push_back(b);
                }
                if(enemies[e].get_health() > 1)
                {
                    enemies[e].health_decrease();
                }
                else if(enemies[e].get_health() == 1)
                {
                    eraseE.push_back(e);
                }
            }
        }
    }
    for (int i = 0; i < eraseB.size(); i++)
    {
        bullets.erase(bullets.begin() + eraseB[i]);
    }
    for (int i = 0; i < eraseE.size(); i++)
    {
        enemies.erase(enemies.begin() + eraseE[i]);
    }
}



