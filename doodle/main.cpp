//Daehyeon Kim, Hyeong Ahn, Sunwoo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "game.h"
#include "menu.h"
#include "pos.h"
inline BuyScene buyscene;
inline GameScene gamescene;



namespace helper
{
    double getDegree(double x, double y)
    {
        return atan2(x, y);
    }

    double getDistance(Pos pos1, Pos pos2)
    {
        double disX = pow(pos1.x - pos2.x, 2);
        double disY = pow(pos1.y - pos2.y, 2);
        return sqrt(disX + disY);
    }
    [[noreturn]] void error(const std::string& s) { throw std::runtime_error(s); }
}



int main(void) try
{
    create_window("Bullet Defense by I'm sorry");
    set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);
    gamescene.art.setup();
    ifstream in{ "Bullet_Defense.txt" };
    if (!in)
    {
        ofstream out{ "Bullet_Defense.txt" };
    } 
    in>>MONEY;
    in>>LEVEL;
    in.close();
    ofstream out{ "Bullet_Defense.txt" };
    
    while (!is_window_closed())
    {
        update_window();
        clear_background(120);
        switch (MENU)
        {
            case MenuType::Purchase:
                draw_text("Gold: " + to_string(MONEY), 0, Height - 100.);
                draw_text("Press S to start new wave", 0, 0);
                buyscene.draw_button();
                buyscene.draw_count();
                break;
            case MenuType::In_Game:
                gamescene.new_level();
                gamescene.draw_cards();
                gamescene.draw_aim();
                gamescene.draw_bullets();
                gamescene.erase_bullet();
                gamescene.draw_enemy();
                gamescene.move_enmey();
                gamescene.erase_enemy();
                gamescene.EraseEnemieByCollision();
                gamescene.next_level();
                break;
            case MenuType::Game_Over:
                clear_background(0);
                out.close();
                break;
        }
    }
    out.close();
    return 0;
}
catch (exception& e)
{
    cerr << "Error: " << e.what() << endl;
    return -1;
}

void on_mouse_pressed(MouseButtons button)
{
    if (MENU == MenuType::In_Game)
    {
        if (button == MouseButtons::Left)
        {
            if (!index_type_map.empty())
            {
                gamescene.push_bullets(index_type_map.begin()->second);
                index_type_map.erase(index_type_map.begin());
            }
        }
        else if (button == MouseButtons::Right)
        {
            gamescene.push_enemy(Enemy_Type::Ground);
        }
    }
}

void on_key_pressed(KeyboardButtons button)
{
    if (MENU == MenuType::Purchase)
    {
        ofstream out{ "Bullet_Defense.txt" };
        switch (button)
        {
        case KeyboardButtons::S: 
            if (!index_type_map.empty())
            {
                MENU = MenuType::In_Game;
                buyscene.reset_count();
            } else
            {
                out << MONEY << " " << LEVEL;
            }  
            break;
        case KeyboardButtons::_1:
        case KeyboardButtons::_2:
        case KeyboardButtons::_3:
        case KeyboardButtons::_4:
        case KeyboardButtons::_5: buyscene.buyBullet(button); break;
        default: break;
        }
    }
}