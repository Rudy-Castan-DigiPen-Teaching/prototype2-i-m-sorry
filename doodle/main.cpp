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
}

int main(void)
{
    create_window("prototype2 by I'm sorry");
    set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);
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
            gamescene.draw_cards();
            gamescene.draw_aim();
            gamescene.draw_bullets();
            gamescene.erase_bullet();

            gamescene.draw_enemy();
            gamescene.move_enmey();
            gamescene.erase_enemy();
            gamescene.EraseEnemieByCollision();
            break;
        case MenuType::Game_Over:
            clear_background(0);
            break;
        }
    }
    return 0;
}

void on_mouse_pressed(MouseButtons button)
{
    if (MENU == MenuType::In_Game)
    {
        if (button == MouseButtons::Left)
        {
            gamescene.push_enemy(Enemy_Type::Air);
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
        switch (button)
        {
        case KeyboardButtons::S: MENU = MenuType::In_Game; break;
        case KeyboardButtons::_1:
        case KeyboardButtons::_2:
        case KeyboardButtons::_3:
        case KeyboardButtons::_4:
        case KeyboardButtons::_5:  buyscene.buyBullet(button); break;
        default: break;
        }
    }
}