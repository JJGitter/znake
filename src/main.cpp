#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"
#include "food.h"

const uint16_t window_pixel_width = 640;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(window_pixel_width, window_pixel_width),
        "Pro elite programmer, Marcus 'Elden Lord' Gladh");

    window.setFramerateLimit(10);

    Grid grid(window_pixel_width);
    const uint8_t start_position = grid.get_width_in_nr_of_elements() / 2;
    Snake snake(start_position);
    Food food;

    sf::CircleShape food_element;
    food_element.setRadius(grid.get_pixel_width_of_single_element() / 2);
    food_element.setFillColor(sf::Color::Red);
    food.spawn(grid.get_width_in_nr_of_elements(), grid.get_width_in_nr_of_elements());

    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();
    snake.eat();

    std::array<uint8_t, 2> food_coordinates;

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
        }

        window.clear(sf::Color(155,186,90,255));

        snake.move();

        snake.draw(window, grid);

        food_coordinates = food.get_coordinates();

        //draw food
        //TODO: EXTRACT DRAW INTO food.draw()
        //WHY IS THE FOOD POSITION NOT RANDOM. IT IS THE SAME EVERY TIME
        uint16_t food_pixel_x = grid.get_pixel_x_from_coordinate_x(food_coordinates[0]);
        uint16_t food_pixel_y = grid.get_pixel_y_from_coordinate_y(food_coordinates[1]);
        food_element.setPosition(food_pixel_x, food_pixel_y);
        window.draw(food_element);

        window.display();
    }

    return 0;
}