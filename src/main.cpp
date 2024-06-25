#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"
#include "food.h"
#include "main.h"

const uint16_t window_pixel_width = 640; //needs to be evenly divisible by grid_element_width_

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(window_pixel_width, window_pixel_width),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");

    window.setFramerateLimit(14);

    Grid grid(window_pixel_width);
    Snake snake(grid);
    Food food;

    food.spawn(grid.get_width_in_nr_of_elements());

    snake.eat_initially();
    snake.eat_initially();
    snake.eat_initially();
    snake.eat_initially();
    snake.eat_initially();
    snake.eat_initially();

    while (window.isOpen())
    {
        sf::Event event;
        bool is_key_already_pressed = false;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }else if ((event.type == sf::Event::KeyPressed) && !is_key_already_pressed)
            {
                process_turn_event(event, snake, is_key_already_pressed);
            }
        }

        window.clear(sf::Color(155,186,90,255));

        snake.move();
        snake.check_for_food(food, grid);

        if (snake.is_digesting())
        {
            snake.digest(food);
        }

        snake.draw(window, grid);
        food.draw(window, grid);

        window.display();
    }

    return 0;
}

void process_turn_event(sf::Event &event, Snake &snake, bool &is_key_already_pressed)
{
    uint8_t button_pressed = event.key.code;
    uint8_t current_direction = snake.direction();
    is_key_already_pressed = true;

    switch (button_pressed)
    {
    case sf::Keyboard::Up:
        if (current_direction != down)
        {
            snake.turn(up);
        }
        break;
    case sf::Keyboard::Right:
        if (current_direction != left)
        {
            snake.turn(right);
        }
        break;
    case sf::Keyboard::Down:
        if (current_direction != up)
        {
            snake.turn(down);
        }
        break;
    case sf::Keyboard::Left:
        if (current_direction != right)
        {
            snake.turn(left);
        }
        break;
    default:
        break;
    }
}