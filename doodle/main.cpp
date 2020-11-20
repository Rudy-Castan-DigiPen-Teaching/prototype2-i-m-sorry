#include "game.h"
#include "menu.h"
#include "pos.h"
inline BuyScene buyscene;
inline GameScene gamescene;
double getDegree(double x, double y)
{
    return atan2(x, y);
}

int main(void)
{
    create_window("prototype2 by I'm sorry");
    set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);


    while (!is_window_closed())
    {
        update_window();
        if (MENU == MenuType::Purchase)
        {
            clear_background(120);
            draw_text("Gold: " + to_string(MONEY), 0, Height - 100.);
            draw_text("Press S to start new wave", 0, 0);
            buyscene.draw_button();

        }
        else if (MENU == MenuType::In_Game)
        {
            clear_background(0);
            gamescene.draw_cards();
            gamescene.draw_aim();
            for (auto p : index_type_map)
            {
                gamescene.push_bullets(p.second);
                gamescene.draw_bullets(p.second);
                index_type_map.erase(p.first);
            }
            
            IsMouseReleased = false;
        }
    }

    return 0;
}

void on_mouse_released(MouseButtons button)
{
    if (MENU == MenuType::In_Game)
    {
        if (button == MouseButtons::Left)
        {
            IsMouseReleased = true;
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