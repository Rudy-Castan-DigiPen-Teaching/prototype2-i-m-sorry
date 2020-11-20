#include "menu.h"

void BuyScene::buyBullet(KeyboardButtons button)
{
    if (button == KeyboardButtons::_1)
    {
        if (MONEY - 100 >= 0)
        {
            MONEY -= 100;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end()) //check if the key word(index) exists
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Pistol));
                    break;
                }
            }
        }
        else
        {
            //not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_2)
    {
        if (MONEY - 200 >= 0)
        {
            MONEY -= 200;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Artillery));
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_3)
    {
        if (MONEY - 250 >= 0)
        {
            MONEY -= 250;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Fireball));
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_4)
    {
        if (MONEY - 500 >= 0)
        {
            MONEY -= 500;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Laser));
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_5)
    {
        if (MONEY - 1000 >= 0)
        {
            MONEY -= 1000;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Nuclear));
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }

}

void BuyScene::draw_button(void)
{
    double x{ Width / 10. };
    double x_increase{ Width / 6. };
    push_settings();
    set_font_size(30);
    draw_rectangle(x, Height / 2, 200.);
    draw_text("1: Pistol", x, Height / 2);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("2: Artillery", x, Height / 2);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("3: Fireball", x, Height / 2);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("4: Laser", x, Height / 2);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("5: Nuclear", x, Height / 2);
    pop_settings();
}