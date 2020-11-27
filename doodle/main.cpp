//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
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

void setup();

int main(void) try
{
    setup();
    create_window("Bullet Defense by I'm sorry");
    set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

    Image splash{"assets/Copyright_information.png"};
    ofstream out{"assets/Bullet_Defense.txt" };
    int timer{ 0 };
    constexpr Color GRAY{ 120 };
    constexpr int SPLASH_TIME{ 300 };
    const double GAMEOVER_X{Width / 25.};
    const double GAMEOVER_Y1{Height / 2.};
    const double GAMEOVER_Y2{Height / 10.};   
    while (!is_window_closed())
    {
        update_window();
        clear_background(GRAY);
        switch (MENU)
        {
        case MenuType::Splash:
            push_settings();
            clear_background(BLACK);
            set_frame_of_reference(FrameOfReference::RightHanded_OriginCenter);
            set_image_mode(RectMode::Center);
            draw_image(splash, 0, 0);
            pop_settings();
            if (timer > SPLASH_TIME)
            {
                MENU = MenuType::Purchase;
            }
            timer++;
            break;
        case MenuType::Purchase:
            buyscene.draw_info();
            buyscene.draw_button();
            buyscene.draw_count();
            break;
        case MenuType::In_Game:
            gamescene.new_level();
            gamescene.draw_cards();
            gamescene.draw_aim();
            gamescene.draw_bullets();
            gamescene.draw_enemy();
            gamescene.move_enmey();
            gamescene.bullet_limit();
            gamescene.EraseByCollision();
            gamescene.next_level();
            gamescene.game_over();
            break;
        case MenuType::Game_Over:
            clear_background(BLACK);
            push_settings();
            set_font_size(200);
            draw_text("Game Over", GAMEOVER_X, GAMEOVER_Y1);
            pop_settings();
            draw_text("Press R to Restart new game", GAMEOVER_X, GAMEOVER_Y2);
            draw_text("Press Q to Quit", GAMEOVER_X, 0);
            break;
        case MenuType::Quit:
            close_window();
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

void setup()
{
    art.setup();
    ifstream in{ "assets/Bullet_Defense.txt" };
    if (!in)
    {
        ofstream out{ "assets/Bullet_Defense.txt" };
    }
    in >> MONEY;
    in >> LEVEL;
    in.close();
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
    }
}

void on_key_pressed(KeyboardButtons button)
{
    constexpr int SHOW_ME_THE_MONEY{ 10000 };
    ofstream out{ "assets/Bullet_Defense.txt" };
    if (MENU == MenuType::Purchase)
    {
        switch (button)
        {
        case KeyboardButtons::S:
            if (!index_type_map.empty())
            {
                MENU = MenuType::In_Game;
                gamescene.start_level();
                buyscene.reset_count();
            }
            else
            {
                out << MONEY << "\n" << LEVEL;
            }
            break;
        case  KeyboardButtons::R:
            gamescene.reset_game();
            buyscene.reset_count();
            break;
        case KeyboardButtons::Q:
            MENU = MenuType::Quit;
            break;
        case KeyboardButtons::_1:
        case KeyboardButtons::_2:
        case KeyboardButtons::_3:
        case KeyboardButtons::_4:
        case KeyboardButtons::_5: buyscene.buyBullet(button); break;
        case KeyboardButtons::M: MONEY += SHOW_ME_THE_MONEY; break;
        default: break;
        }
    }
    else if (MENU == MenuType::In_Game)
    {
        if (button == KeyboardButtons::R)
        {
            gamescene.reset_game();
            MENU = MenuType::Purchase;
        }
    }
    else if (MENU == MenuType::Game_Over)
    {
        switch (button)
        {
        case KeyboardButtons::R:
            gamescene.reset_game();
            MENU = MenuType::Purchase;
            break;
        case KeyboardButtons::Q:
            MENU = MenuType::Quit;
            break;
        default: break;
        }
    }
}
