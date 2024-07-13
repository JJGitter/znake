#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"
#include "food.h"
#include "main.h"
#include "walls.h"

const uint16_t window_pixel_width = 640; //needs to be evenly divisible by grid_element_width_

int main()
{
    GameState game_state = ePaused;
    sf::RenderWindow window(
        sf::VideoMode(window_pixel_width, window_pixel_width),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");

    window.setFramerateLimit(14);

    Grid grid(window_pixel_width);
    Snake snake(grid);
    Food food;
    Walls walls(grid);
    bool has_collided = false;

    food.spawn(grid.get_max_element_index());

    while (window.isOpen())
    {
        sf::Event event;
        bool snake_already_turned = false;

        while (window.pollEvent(event))
        {
            bool space_bar_pressed = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space;
            bool any_key_pressed = event.type == sf::Event::KeyPressed;

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }else if (space_bar_pressed)
            {
                toggle_pause(game_state);
            }else if (any_key_pressed && !snake_already_turned)
            {
                process_turn_event(event, snake);
                snake_already_turned = true;
            }
        }

        if (game_state == eRunning) {
            snake.move();
            has_collided = snake.check_for_collision(walls);
            if(has_collided)
            {
                game_state = eGameOver;
            }
            snake.check_for_food(food, grid);

            if (snake.is_digesting())
            {
                snake.digest();
            }
        }

        window.clear(sf::Color(155,186,90,255));

        snake.draw(window, grid);
        food.draw(window, grid);
        walls.draw(window, grid);

        window.display();
    }

    return 0;
}

void toggle_pause(GameState &game_state)
{
    if (game_state == ePaused)
    {
        game_state = eRunning;
    }else if (game_state == eRunning)
    {
        game_state = ePaused;
    }
}

void process_turn_event(sf::Event &event, Snake &snake)
{
    uint8_t button_pressed = event.key.code;
    uint8_t current_direction = snake.direction();

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