//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020

#include "menu.h"

void BuyScene::buyBullet(KeyboardButtons button)
{
    constexpr int BULLET_1{ 100 };
    constexpr int BULLET_2{ 200 };
    constexpr int BULLET_3{ 500 };
    constexpr int BULLET_4{ 500 };
    constexpr int BULLET_5{ 2000 };

    if (button == KeyboardButtons::_1)
    {
        if (MONEY - BULLET_1 >= 0)
        {
            MONEY -= BULLET_1;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end()) //check if the key word(index) exists
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Rock));
                    bullet_count[0]++;
                    
                    break;
                }
            }
        }
        else
        {
            art.PlaySound(Not_enough);
        }
    }
    else if (button == KeyboardButtons::_2)
    {
        if (MONEY - BULLET_2 >= 0)
        {
            MONEY -= BULLET_2;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Pistol));
                    bullet_count[1]++;
                    
                    break;
                }
            }
        }
        else
        {
            art.PlaySound(Not_enough);
        }
    }
    else if (button == KeyboardButtons::_3)
    {
        if (MONEY - BULLET_3 >= 0)
        {
            MONEY -= BULLET_3;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Barrier));
                    bullet_count[2]++;
                    
                    break;
                }
            }
        }
        else
        {
            art.PlaySound(Not_enough);
        }
    }
    else if (button == KeyboardButtons::_4)
    {
        if (MONEY - BULLET_4 >= 0)
        {
            MONEY -= BULLET_4;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Laser));
                    bullet_count[3]++;
                    
                    break;
                }
            }
        }
        else
        {
            art.PlaySound(Not_enough);
        }
    }
    else if (button == KeyboardButtons::_5)
    {
        if (MONEY - BULLET_5 >= 0)
        {
            MONEY -= BULLET_5;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Nuclear));
                    bullet_count[4]++;
                    
                    break;
                }
            }
        }
        else
        {
            art.PlaySound(Not_enough);
        }
    }

}

void BuyScene::draw_button()
{
    double x{ Width / 10. };
    double x_increase{ Width / 6. };
    double y_pos{ Height / 2. };
    constexpr double RECT_SIZE{ 200. };

    push_settings();
    set_font_size(30);
    set_fill_color(BULLET_1_COLOR);
    draw_rectangle(x, y_pos, RECT_SIZE);
    draw_text("1: Rock", x, y_pos);
    set_fill_color(BULLET_2_COLOR);
    draw_rectangle(x += x_increase, y_pos, RECT_SIZE);
    draw_text("2: Pistol", x, y_pos);
    set_fill_color(BULLET_3_COLOR);
    draw_rectangle(x += x_increase, y_pos, RECT_SIZE);
    draw_text("3: Barrier", x, y_pos);
    set_fill_color(BULLET_4_COLOR);
    draw_rectangle(x += x_increase, y_pos, RECT_SIZE);
    draw_text("4: Laser", x, y_pos);
    set_fill_color(BULLET_5_COLOR);
    draw_rectangle(x += x_increase, y_pos, RECT_SIZE);
    draw_text("5: Nuclear", x, y_pos);
    pop_settings();
}

void BuyScene::draw_count()
{
    double x{ Width / 10. };
    double x_increase{ Width / 6. };
    double y_pos{ Height / 2 - 100. };

    push_settings();
    draw_text(to_string(bullet_count[0]), x, y_pos);
    draw_text(to_string(bullet_count[1]), x += x_increase, y_pos);
    draw_text(to_string(bullet_count[2]), x += x_increase, y_pos);
    draw_text(to_string(bullet_count[3]), x += x_increase, y_pos);
    draw_text(to_string(bullet_count[4]), x += x_increase, y_pos);
    pop_settings();
}

void BuyScene::reset_count()
{
    for (int i = 0; i < bullet_count.size(); i++)
    {
        bullet_count[i] = 0;
    }
}

void BuyScene::draw_info()
{
    double x_pos{ Width * 3. / 4. };
    double y_pos{ Height * 1. };
    double y_increase{100.};

    push_settings();
    draw_text("Gold: " + to_string(MONEY), 0, y_pos-= y_increase);
    draw_text("Level: " + to_string(LEVEL), 0, y_pos-= y_increase);
    set_font_size(30);
    draw_text("Press S to Start new wave or Save ", 0, y_increase *2);
    draw_text("Press R to Restart new game ", 0, y_increase);
    draw_text("Press Q to Quit", 0, 0);

    y_pos= (Height / 4.);
    y_increase = (50.);

    draw_text("I'm sorry", x_pos, y_pos);
    draw_text("Dae Hyeon Kim", x_pos, y_pos -= y_increase);
    draw_text("Hyoung Won An", x_pos, y_pos -= y_increase);
    draw_text("Sun Woo Lee", x_pos, y_pos -= y_increase);
    pop_settings();
}