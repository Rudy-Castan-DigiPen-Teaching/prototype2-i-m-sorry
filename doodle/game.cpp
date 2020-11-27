//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "game.h"

void GameScene::start_level()
{
    constexpr int INTERVALMINIMUM{ 50 };
    constexpr int ENEMYUNITCOEFFICIENT{ 3 };
    constexpr int ENEMYINTERVALCOEFFICIENT{ 10 };
    remaining_enemy = LEVEL * ENEMYUNITCOEFFICIENT;
    enemy_interver -= ENEMYINTERVALCOEFFICIENT * LEVEL;
    if (enemy_interver < INTERVALMINIMUM)
    {
        enemy_interver = INTERVALMINIMUM;
    }
}

void GameScene::next_level()
{
    if (enemies.empty() && MENU == MenuType::In_Game && remaining_enemy == 0)
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
    if(timer % enemy_interver == 0 && remaining_enemy != 0)
    {
        push_enemy();
        remaining_enemy--;
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
    constexpr int ROCKSPEED{ 3000 };
    constexpr int PISTOLSPEED{ 4000 };
    constexpr int BARRIERSPEED{ 10 };
    constexpr int LASERSPEED{ 8000 };
    constexpr int NUCLEARSPEED{ 1000 };
    
    constexpr int ROCKWEIGHT{ 100 };
    constexpr int PISTOLWEIGHT{ 10 };
    constexpr int BARRIERWEIGHT{ 0 };
    constexpr int LASERWEIGHT{ 0 };
    constexpr int NUCLEARWEIGHT{ 0 };
    
    constexpr int ROCKSIZE{ 75 };
    constexpr int PISTOLSIZE{ 50 };
    constexpr int LASERSIZE{ 50 };
    if (bulletType < Bullet_Type::Rock || bulletType > Bullet_Type::Nuclear)
    {
        helper::error("failed to match bullet type: " + to_string(static_cast<int>(bulletType)));
    }
    Bullet bullet;
    switch (bulletType)
    {
    case Bullet_Type::Rock:
        bullet.set_direction();
        bullet.set_infor(ROCKSPEED, ROCKWEIGHT, ROCKSIZE, Bullet_Type::Rock);
        art.PlaySound(RockSound);
        break;
    case Bullet_Type::Pistol:
        bullet.set_direction();
        bullet.set_infor(PISTOLSPEED, PISTOLWEIGHT, PISTOLSIZE,Bullet_Type::Pistol);
        art.PlaySound(PistolSound);
        break;
    case Bullet_Type::Barrier:
        bullet.set_direction_fixed(Width, Height/2);
        bullet.set_infor(BARRIERSPEED, BARRIERWEIGHT, Height, Bullet_Type::Barrier);
        art.PlaySound(BarrierSound);
        break;
    case Bullet_Type::Laser:
        bullet.set_direction();
        bullet.set_infor(LASERSPEED, LASERWEIGHT, LASERSIZE, Bullet_Type::Laser);
        art.PlaySound(LaserSound);
        break;
    case Bullet_Type::Nuclear:
        bullet.set_direction_fixed(Width, Height/2);
        bullet.set_infor(NUCLEARSPEED, NUCLEARWEIGHT, Height, Bullet_Type::Nuclear);
        art.PlaySound(NuclearSound);
        break;
    }
    bullets.push_back(bullet);
}

void GameScene::push_enemy()
{
    Enemy enemy;
    constexpr double ENEMYSIZEMAX{ 300. };
    constexpr double ENEMYPOSLIMIT{ 100. };
    constexpr int ENEMYHEALTHCOEFFICIENT{ 5 };
    constexpr int ENEMYHEALTHORIGIN{ 1 };
    constexpr int ENEMYSPEEDCOEFFICIENT{ 10 };
    constexpr double ENEMYSPEEDORIGIN{ 100. };
    constexpr double ENEMYSPEEDMIN{ 150. };
    constexpr double ENEMYSPEEDMAX{ 250. };
    constexpr double ENEMYSIZEMIN{ 100. };
    constexpr double ENEMYCOLOR{ 255. };
    constexpr double ENEMYALPHAMIN{ 100. };
    enemy.set_size(random(ENEMYSIZEMIN, ENEMYSIZEMAX    ));
    enemy.set_position(Width, random(ENEMYPOSLIMIT, Height- ENEMYPOSLIMIT));
    enemy.set_velocity(ENEMYSPEEDORIGIN +random(ENEMYSPEEDMIN, ENEMYSPEEDMAX) * LEVEL / ENEMYSPEEDCOEFFICIENT);
    enemy.set_color({ random(ENEMYCOLOR), random(ENEMYCOLOR), random(ENEMYCOLOR), random(ENEMYALPHAMIN, ENEMYCOLOR) });
    enemy.set_health(LEVEL / ENEMYHEALTHCOEFFICIENT + ENEMYHEALTHORIGIN);
    enemies.push_back(enemy);
}

void GameScene::move_enmey()
{
    for (auto& i : enemies)
    {
        i.move(DeltaTime);
    }
}

void GameScene::bullet_limit()
{
    constexpr int BARRIER_TIMER{3};
    for (int i = 0; i < bullets.size(); i++)
    {
        switch (bullets[i].get_bullet_type())
        {
        case Bullet_Type::Rock:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
            {
                over_limitB.push_back(i);
            }
            break;
        case Bullet_Type::Pistol:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width * 0.7)
            {
                over_limitB.push_back(i);
            }
            break;
        case Bullet_Type::Barrier:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= BARRIER_TIMER)   
            {
                over_limitB.push_back(i);
            }
            break;
        case Bullet_Type::Laser:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
            {
                over_limitB.push_back(i);
            }
            break;
        case Bullet_Type::Nuclear:
            if (helper::getDistance(bullets[i].get_position(), bullets[i].get_start_position()) >= Width)
            {
                over_limitB.push_back(i);
            }
            break;
        }
    }
    for (int i = 0; i < over_limitB.size(); i++)
    {
        bullets.erase(bullets.begin() + over_limitB[i]);
    }
    over_limitB.clear();
}

void GameScene::game_over()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].get_position().x < enemies[i].get_size()*.5)
        {
            MENU = MenuType::Game_Over;
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
                set_fill_color(BULLET_1_COLOR);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Pistol: 
                push_settings();
                set_fill_color(BULLET_2_COLOR);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Barrier: 
                push_settings();
                set_fill_color(BULLET_3_COLOR);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
            case Bullet_Type::Laser: 
                push_settings();
                set_fill_color(BULLET_4_COLOR);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                
                break;
            case Bullet_Type::Nuclear: 
                push_settings();
                set_fill_color(BULLET_5_COLOR);
                draw_ellipse(i.get_position().x, i.get_position().y, i.get_size());
                pop_settings();
                break;
        }
    }
    pop_settings();
}
void GameScene::draw_aim()
{
    constexpr double AIMLINESIZE{ 50. };
    constexpr double AIMCIRCLESIZE{ 30. };
    double aim_x = get_mouse_x();
    double aim_y = get_mouse_y();
    double line_y= (Height / 2.) ;
    push_settings();
    set_outline_color(BULLET_4_COLOR);
    draw_line(aim_x - AIMLINESIZE, aim_y, aim_x + AIMLINESIZE, aim_y);
    draw_line(aim_x, aim_y - AIMLINESIZE, aim_x, aim_y + AIMLINESIZE);
    no_fill();
    draw_ellipse(aim_x, aim_y, AIMCIRCLESIZE);
    set_outline_color(BLACK);
    draw_line(0, line_y,aim_x,aim_y);
    pop_settings();
}

void GameScene::draw_cards(void)
{
    double x{ Width / 10000. };
    double x_increase{ Width / 30. };
    constexpr double ELLIPSE_SIZE{ 50. };
    constexpr double ELLIPSE_Y_POS{ 25. };
    push_settings();
    set_font_size(30);
    draw_text("Remaining enimies : " + to_string(remaining_enemy), Width / 2, Height *.9);
    for (auto p : index_type_map)
    {
        switch (p.second)
        {
        case Bullet_Type::Rock:
            set_fill_color(BULLET_1_COLOR);
            break;
        case Bullet_Type::Pistol:
           set_fill_color(BULLET_2_COLOR);
            break;
        case Bullet_Type::Barrier:
            set_fill_color(BULLET_3_COLOR);
            break;
        case Bullet_Type::Laser:
            set_fill_color(BULLET_4_COLOR);
            break;
        case Bullet_Type::Nuclear:
            set_fill_color(BULLET_5_COLOR);
            break;
        }
        draw_ellipse(x+=x_increase, ELLIPSE_Y_POS, ELLIPSE_SIZE);
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
        set_outline_color(BLACK);
        draw_text(to_string(i.get_health()),i.get_position().x, i.get_position().y);
        pop_settings();
    }
    pop_settings();
}

void GameScene::EraseByCollision()
{ 
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
                    vector<int>::iterator iter;
                    iter = find(eraseE.begin(), eraseE.end(), e);
                    if(iter == eraseE.end())
                    {
                        eraseE.push_back(e);
                    }
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
    eraseB.clear();
    eraseE.clear();
}